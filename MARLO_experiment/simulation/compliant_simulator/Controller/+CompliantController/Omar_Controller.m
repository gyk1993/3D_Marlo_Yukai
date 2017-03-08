classdef Omar_Controller < Controller_MARLO
	properties
        %Kp
        kp;
        %Kd
        kd;
        %Kp Hip
        kp_hip;
        %Kd Hip
        kd_hip;
        %Holding s or joints (0/1)
        hold;
        %Holding s for shake test (0/1)
        shakeholdtest = 1;
        %Controller Choice (1=joint,2=VC)
        controller_choice;
        %Ts (controller sample time)
        Ts
    end
    
    properties %%% VC CONTROLLER TUNABLE PROPERTIES %%%
        %Zero Error (0/1)
        zero_error;
        %Torso Control (0/1)
        torso_control;
        %Regulate Velocity (0/1)
        regulate_velocity;
        %3D (0/1)
        threeD;
        %Limit Swing Hip Angle (0/1)
        LimitSwHipAngle;
        %Make Links Passive (0/1)
        jointPassivity;
        %Foot Placement Sw LA
        footPlacementLA;
        %Foot Placement Sw HA
        footPlacementHA;
        %s Period (s)
        s_period;
        %No. of Domains Per Leg
        number_of_domains_per_leg
        %Delta Stance KA Bezier Coef
        deltaStKA;
        %Delta Swing KA Bezier Coef
        deltaSwKA;
        %Delta Swing LA Bezier Coef
        deltaSwLA;
        %Delta Swing HA Bezier Coef
        deltaSwHA;
    end
    
	properties (Access = private) %%% VC CONTROLLER PROPERTIES %%%
        tau_velFilter = 0.25;
        filteredVelocity = [0; 0; 0];
        y_prev = zeros(6, 1); % For error zeroing
        s0 = 0; % For error zeroing and holding s
    end
    
	properties (Constant = true, Hidden = true)
        k_spring_leg = 2300;    % (Nm/rad)
        grf_z_min = 100;        % (N)
        grf_z_max = 200;        % (N)
    end
	
	methods %%% INITIALIZATION AND USERSTEP %%%
		function userSetup(obj)
			%USERSETUP Initialize system object.
            
        end
	
        function [output] = userStep(obj, input)
            switch(obj.controller_choice)
                case 1
                    [output] = JointController(obj, input);
                case 2
                    [output] = VCController(obj, input);
                otherwise
                    error('Wrong Controller Choice');
            end
        end
    end
    
    methods %%% VC CONTROLLER METHODS %%%
        function [output] = VCController(obj, input)
            % Extract input
            velEsts = input.velEst;
            t = input.t;    
            q = input.q;
            dq = input.dq;
            x = [q; dq];
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;
            Data = struct();
            
            % ----- Estimating Ground Reaction Forces ----- %
            [fz_R, fz_L, s_R, s_L] = obj.getEstimatedGRF(q);
            ControlState.s_R = s_R;
            ControlState.s_L = s_L;
            
            % ----- Consider Switching Leg ----- %
            [newDomain] = obj.getDomainSuggestion(t, q, dq, ControlState, ControlParams);
            if ControlState.Domain ~= newDomain
                % Switch domains
                prevDomain = ControlState.Domain;
                ControlState.Domain = newDomain;
                
                % Resetting s
                if (obj.isRightStance(prevDomain) ~= obj.isRightStance(newDomain)) && (obj.hold == 0)
                    obj.s0 = (t / obj.s_period) - 0;
                end
                
                % Consider error smoothening here
                ControlState.HAlphaErrorFix = zeros(6, 6);
                
                if  obj.zero_error && ~obj.hold
                    [HAlpha_new, H0_new, ~, ~] = obj.getParamsFromDomain(ControlParams, newDomain);
                    ya_new = H0_new * q;

                    if obj.hold
                        s_new = ControlState.s;
                    else
                        [s_new, ~, ~] = obj.getS(t, obj.s0, obj.s_period);
                    end
                    
                    
                    if s_new < 1
                        for i = 1:6
                            da = SolveForDeltaAlpha(HAlpha_new(i, :), s_new, ya_new(i) - obj.y_prev(i));
                            ControlState.HAlphaErrorFix(i, 1) = da;
                        end
                    end
                end
            end
            
            % ----- Estimating Velocity of hip ----- %
            [velFiltered, velMeasured] = obj.getVelocities(velEsts, ControlState);
            vel_des = [0; 0; 0];
            vel_error = velFiltered - vel_des;

            swingHipAdjustment = obj.footPlacementHA * vel_error(1);
            swingLegAdjustment = obj.footPlacementLA * vel_error(2);
            
            ControlState.HAlphaSpeedReg = zeros(6, 6);
            if obj.regulate_velocity == 1 && obj.isSingleSupport(ControlState.Domain)
                if obj.isRightStance(ControlState.Domain) % Right Single Support
                    ControlState.HAlphaSpeedReg(5, :) = [0, linspace(0, swingLegAdjustment, 5)];
                    ControlState.HAlphaSpeedReg(4, :) = [0, linspace(0, swingHipAdjustment, 5)];
                else % Left Single Support
                    ControlState.HAlphaSpeedReg(2, :) = [0, linspace(0, swingLegAdjustment, 5)];
                    ControlState.HAlphaSpeedReg(1, :) = [0, linspace(0, swingHipAdjustment, 5)];
                end
            end
            
            
            % ----- Controller Params here ----- %
            [HAlpha, H0, A, ~] = obj.getParamsFromDomain(ControlParams, ControlState.Domain);
            HAlpha = HAlpha + ...
                ControlState.HAlphaErrorFix + ...
                ControlState.HAlphaSpeedReg;
            
            % ----- Updating s/ds ----- %
            if obj.hold
                % Holding s by changing s0
                obj.s0 = (t / obj.s_period) - ControlState.s;
                ControlState.s_unsat = ControlState.s;
                ControlState.ds = 0;
            else
                [s, s_unsat, ds] = obj.getS(t, obj.s0, obj.s_period);
                ControlState.s = s;
                ControlState.s_unsat = s_unsat;
                ControlState.ds = ds;
            end
            
            % ----- Getting errors ----- %
            [y, dy, ya, dya, yd, dyd] = obj.getErrors(x, ControlState.s, ControlState.ds, HAlpha, H0);
            
            % ----- Make some links passive ----- %
            if obj.jointPassivity
                if obj.isRightStance(ControlState.Domain)
                    % alpha=1 when Right Leg Off Ground
                    alpha = 1 - ControlState.s_R;

                    yd(2) = Interpolate1D(yd(2), ya(2), alpha);
                    dyd(2) = Interpolate1D(dyd(2), 0, alpha);

                    if obj.threeD
                        yd(1) = Interpolate1D(yd(1), ya(1), alpha);
                        dyd(1) = Interpolate1D(dyd(1), 0, alpha);
                    end
                    
                    % alpha=1 when Left Leg On Ground
                    alpha = ControlState.s_L;

                    yd(5) = Interpolate1D(yd(5), ya(5), alpha);
                    dyd(5) = Interpolate1D(dyd(5), 0, alpha);

                    if obj.threeD
                        yd(4) = Interpolate1D(yd(4), ya(4), alpha);
                        dyd(4) = Interpolate1D(dyd(4), 0, alpha);
                    end
                else %if obj.isLeftStance(ControlState.Domain)
                    % alpha=1 when Left Leg Off Ground
                    alpha = 1 - ControlState.s_L;

                    yd(5) = Interpolate1D(yd(5), ya(5), alpha);
                    dyd(5) = Interpolate1D(dyd(5), 0, alpha);

                    if obj.threeD
                        yd(4) = Interpolate1D(yd(4), ya(4), alpha);
                        dyd(4) = Interpolate1D(dyd(4), 0, alpha);
                    end
                    
                    % alpha=1 when Right Leg On Ground
                    alpha = ControlState.s_R;

                    yd(2) = Interpolate1D(yd(2), ya(2), alpha);
                    dyd(2) = Interpolate1D(dyd(2), 0, alpha);

                    if obj.threeD
                        yd(1) = Interpolate1D(yd(1), ya(1), alpha);
                        dyd(1) = Interpolate1D(dyd(1), 0, alpha);
                    end
                end
                
                y = ya - yd;
                dy = dya - dyd;
            end
            
            % ----- Limit Floating Hip Angles ----- %
            
            if obj.LimitSwHipAngle
                if ControlState.s_R <= 0.999
                    if yd(1) > deg2rad(5)
                        yd(1) = deg2rad(5);
                    end
                end
                if ControlState.s_L <= 0.999
                    if yd(5) < deg2rad(-5)
                        yd(5) = deg2rad(-5);
                    end
                end
                
                y = ya - yd;
                dy = dya - dyd;
            end
            
            % ----- Calculating Torques ----- %
            Kp = [obj.kp_hip; obj.kp; obj.kp; obj.kp_hip; obj.kp; obj.kp];
            Kd = [obj.kd_hip; obj.kd; obj.kd; obj.kd_hip; obj.kd; obj.kd];
            
            u = - (Kp .* (A \ y) + Kd .* (A \ dy));
            % Gravity Compensation
            u(1) = u(1) - 0.8;
            u(4) = u(4) + 0.8;
            % u = zeros(6, 1);
            
            obj.y_prev = y;
            
            % ----- Data Logged -----%
            Data.q = q;
            Data.u = u;
            Data.y = y;
            Data.dy = dy;
            Data.ya = ya;
            Data.dya = dya;
            Data.yd = yd;
            Data.dyd = dyd;
            Data.s = ControlState.s;
            Data.s_unsat = ControlState.s_unsat;
            Data.ds = ControlState.ds;
            
            Data.Domain = ControlState.Domain;
            Data.s_R = s_R;
            Data.s_L = s_L;
            Data.fz_R = fz_R;
            Data.fz_L = fz_L;
            
            Data.velFiltered = velFiltered;
            Data.velMeasured = velMeasured;
            
            Data.swingHipAdjustment = swingHipAdjustment;
            Data.swingLegAdjustment = swingLegAdjustment;
            
            % ----- Store outputs ----- %
            output.eStop = false;
            output.u = u;
            output.Data = Data;
            output.ControlParams = ControlParams;
            output.ControlState = ControlState;
        end
        
        function [s, s_unsat, ds] = getS(obj, t, s0, T)
            s_unsat = t / T - s0;

            % Saturate s
            if s_unsat > 1 
                s = 1;
                ds = 0;
            elseif s_unsat < 0 
                s = 0;
                ds = 0;
            else
                s = s_unsat;
                ds = 1;
            end
        end
        
        function [fz_R, fz_L, s_R, s_L] = getEstimatedGRF(obj, q)
            q_pitch = q(1);
            q_R_lA = q(5);
            q_R_lb = q(6);
            q_R_grA = q(7);
            q_R_grB = q(8);
            q_L_lA = q(12);
            q_L_lb = q(13);
            q_L_grA = q(14);
            q_L_grB = q(15);
            
            % Estimated GRF
			fz_R = 2*obj.k_spring_leg*(cos(q_pitch + q_R_lb)*(q_R_grA - q_R_lA) - cos(q_pitch + q_R_lA)*(q_R_grB - q_R_lb))/sin(q_R_lA - q_R_lb);
			fz_L = 2*obj.k_spring_leg*(cos(q_pitch + q_L_lb)*(q_L_grA - q_L_lA) - cos(q_pitch + q_L_lA)*(q_L_grB - q_L_lb))/sin(q_L_lA - q_L_lb);
			
			% Scaling factors representing a normalized vertical GRF
			s_R = scaleFactor(fz_R, obj.grf_z_min, obj.grf_z_max);
			s_L = scaleFactor(fz_L, obj.grf_z_min, obj.grf_z_max);
        end
        
        function [HAlpha, H0, A, T] = getParamsFromDomain(obj, ControlParams, domain)
            switch(domain)
                case 0
                    HAlpha = ControlParams.RFB.HAlpha;
                    T = ControlParams.RFB.t;
                    H0 = ControlParams.RFB.H0;
                    A = ControlParams.RFB.A;
                case 1
                    HAlpha = ControlParams.RSS.HAlpha;
                    T = ControlParams.RSS.t;
                    H0 = ControlParams.RSS.H0;
                    A = ControlParams.RSS.A;
                case 2
                    HAlpha = ControlParams.RDS.HAlpha;
                    T = ControlParams.RDS.t;
                    H0 = ControlParams.RDS.H0;
                    A = ControlParams.RDS.A;
                case 3
                    HAlpha = ControlParams.RSwS.HAlpha;
                    T = ControlParams.RSwS.t;
                    H0 = ControlParams.RSwS.H0;
                    A = ControlParams.RSwS.A;
                case 4
                    HAlpha = ControlParams.LFB.HAlpha;
                    T = ControlParams.LFB.t;
                    H0 = ControlParams.LFB.H0;
                    A = ControlParams.LFB.A;
                case 5
                    HAlpha = ControlParams.LSS.HAlpha;
                    T = ControlParams.LSS.t;
                    H0 = ControlParams.LSS.H0;
                    A = ControlParams.LSS.A;
                case 6
                    HAlpha = ControlParams.LDS.HAlpha;
                    T = ControlParams.LDS.t;
                    H0 = ControlParams.LDS.H0;
                    A = ControlParams.LDS.A;
                case 7
                    HAlpha = ControlParams.LSwS.HAlpha;
                    T = ControlParams.LSwS.t;
                    H0 = ControlParams.LSwS.H0;
                    A = ControlParams.LSwS.A;
                otherwise
                    error('Something Wrong');
            end
            
            if domain < obj.number_of_domains_per_leg
                HAlpha(3,:) = HAlpha(3,:) + obj.deltaStKA;
                
                HAlpha(4,:) = HAlpha(4,:) + obj.deltaSwHA;
                HAlpha(5,:) = HAlpha(5,:) + obj.deltaSwLA;
                HAlpha(6,:) = HAlpha(6,:) + obj.deltaSwKA;
            else
                HAlpha(1,:) = HAlpha(1,:) + obj.deltaSwHA;
                HAlpha(2,:) = HAlpha(2,:) + obj.deltaSwLA;
                HAlpha(3,:) = HAlpha(3,:) + obj.deltaSwKA;
                
                HAlpha(6,:) = HAlpha(6,:) + obj.deltaStKA;
            end
            
            T = 1;
        end
        
        function [velFiltered, velMeasured] = getVelocities(obj, velEsts, ControlState)
            if ControlState.s_R > 0.999
                velMeasured = velEsts(1:3);
                alpha = obj.Ts/(obj.tau_velFilter + obj.Ts);
            elseif ControlState.s_L > 0.999
                velMeasured = velEsts(4:6);
                alpha = obj.Ts/(obj.tau_velFilter + obj.Ts);
            else
                velMeasured = [0; 0; 0];
                alpha = 0;
            end
            
            velFiltered = obj.filteredVelocity.*(1-alpha) + velMeasured.*alpha;
            obj.filteredVelocity = velFiltered;
        end
        
        function [y, dy, ya, dya, yd, dyd] = getErrors(obj, x, s, ds, HAlpha, H0)
            q = x(1:end/2);
            dq = x(end/2+1:end);

            % Feedback
            ya = H0 * q;
            dya = H0 * dq;

            yd = bezier(HAlpha, s);
            dyd = bezierd(HAlpha, s) * ds;
            
            if obj.shakeholdtest
%                 ya = H0 * q;
%                 dya = H0 * dq;
%                 
%                 yd([1,2,4,5]) = bezier(HAlpha([1,2,4,5],:), 1);
%                 dyd([1,2,4,5]) = bezierd(HAlpha([1,2,4,5],:), 1) * 0;
%                 
%                 yd([3,6]) = bezier(HAlpha([3,6],:), 0.5);
%                 dyd([3,6]) = bezierd(HAlpha([3,6],:), 0.5) * 0;
            end
            
            y = ya - yd;
            dy = dya - dyd;
        end
        
        %%% DOMAIN IDENTIFICATION STUFF %%%
        
        function [newDomain] = getDomainSuggestion(obj, t, q, dq, ControlState, ControlParams)
            currentDomain = ControlState.Domain;
            
            rightFoot = (ControlState.s_R > 0);
            leftFoot = (ControlState.s_L > 0);
            isRightS = obj.isRightStance(currentDomain);
            
            if obj.hold == false
                if ControlState.s_unsat >= 1
                    isRightS = ~isRightS;
                else
                    if obj.isRightStance(currentDomain) && ControlState.s_unsat > 0.65 && ControlState.s_L > 0.999
                        % Already on RStance Domain, left leg on ground, and s > 0.65
                        isRightS = ~isRightS;
                    elseif obj.isLeftStance(currentDomain) && ControlState.s_unsat > 0.65 && ControlState.s_R > 0.999
                        % Already on LStance Domain, right leg on ground, and s > 0.65
                        isRightS = ~isRightS;
                    end
                end
            end
            
            if isRightS && ~rightFoot && ~leftFoot
                newDomain = 0;
            elseif isRightS && rightFoot && ~leftFoot
                newDomain = 1;
            elseif isRightS && rightFoot && leftFoot
                newDomain = 2;
            elseif isRightS && ~rightFoot && leftFoot
                newDomain = 3;
                
            elseif ~isRightS && ~rightFoot && ~leftFoot
                newDomain = 4;
            elseif ~isRightS && ~rightFoot && leftFoot
                newDomain = 5;
            elseif ~isRightS && rightFoot && leftFoot
                newDomain = 6;
            else % if ~isRightS && rightFoot && ~leftFoot
                newDomain = 7;
            end
            
            if obj.torso_control == 0
                if isRightS
                    newDomain = 0;
                else
                    newDomain = obj.number_of_domains_per_leg;
                end
            end
        end
        
        function check = isRightStance(obj, domain)
            check = (domain < obj.number_of_domains_per_leg);
        end
        
        function check = isLeftStance(obj, domain)
            check = ~obj.isRightStance(domain);
        end
        
        function check = isFloating(obj, domain)
            check = (mod(domain, obj.number_of_domains_per_leg) == 0);
        end
        
        function check = isSingleSupport(obj, domain)
            check = (mod(domain, obj.number_of_domains_per_leg) == 1);
        end
        
        function check = isDoubleSupport(obj, domain)
            check = (mod(domain, obj.number_of_domains_per_leg) == 2);
        end
        
        function check = isSwingSingleSupport(obj, domain)
            check = (mod(domain, obj.number_of_domains_per_leg) == 3);
        end
    end
    
	methods %%% JOINT CONTROLLER METHODS %%%
        function [output] = JointController(obj, input)
            % Extract input 
            t = input.t;    
            q = input.q;
            dq = input.dq;
            x = [q; dq];
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;
            Data = struct();
            
            [y, dy, ya, dya, yd, dyd] = obj.getJointErrors(x, t);
            
            % ----- Calculating Torques ----- %
            Kp = [obj.kp_hip; obj.kp; obj.kp; obj.kp_hip; obj.kp; obj.kp];
            Kd = [obj.kd_hip; obj.kd; obj.kd; obj.kd_hip; obj.kd; obj.kd];
            u = - (Kp .* y + Kd .* dy);
            % u = zeros(6, 1);
            
            % ----- Data Logged -----%
            Data.q = q;
            Data.u = u;
            Data.y = y;
            Data.dy = dy;
            Data.ya = ya;
            Data.dya = dya;
            Data.yd = yd;
            Data.dyd = dyd;
            Data.s = 0;
            Data.s_unsat = 0;
            Data.ds = 0;
            
            Data.Domain = 0;
            Data.s_R = 0;
            Data.s_L = 0;
            Data.fz_R = 0;
            Data.fz_L = 0;
            
            Data.velFiltered = zeros(3,1);
            Data.velMeasured = zeros(3,1);
            
            Data.swingHipAdjustment = 0;
            Data.swingLegAdjustment = 0;
            
            % ----- Store outputs ----- %
            output.eStop = false;
            output.u = u;
            output.Data = Data;
            output.ControlParams = ControlParams;
            output.ControlState = ControlState;
        end
        
        function [y, dy, ya, dya, yd, dyd] = getJointErrors(obj, x, t)
            q = x(1:end/2);
            dq = x(end/2+1:end);

            % Feedback
            ya = q([4, 7:8, 11, 14:15]);
            dya = dq([4, 7:8, 11, 14:15]);

            yd = [0; pi - deg2rad(40);  pi + deg2rad(40); 0; pi - deg2rad(40);  pi + deg2rad(40)];
            dyd = [0; 0; 0; 0; 0; 0];
            
            if obj.joint_zero && obj.hold
                obj.joint_test_time_delta = 0;
                time = 0;
                obj.joint_test_time_start = t;
            else
                if obj.hold
                    obj.joint_test_time_start = t - obj.joint_test_time_delta;
                else
                    obj.joint_test_time_delta = t - obj.joint_test_time_start;
                end
                time = t - obj.joint_test_time_start;
            end
            
            yd(obj.joint_test_link_num) = yd(obj.joint_test_link_num) + deg2rad(obj.joint_test_amp)*sin(2*pi*obj.joint_test_freq*time);
            if obj.hold == 0
                dyd(obj.joint_test_link_num) = dyd(obj.joint_test_link_num) + deg2rad(obj.joint_test_amp)*2*pi*obj.joint_test_freq*cos(2*pi*obj.joint_test_freq.*time);
            end
            
            y = ya - yd;
            dy = dya - dyd;
        end
    end
    
	properties %%% JOINT CONTROLLER TUNABLE PROPERTIES %%%
        %Joint Test Link Number (RH, RA, RB, LH, LA, LB)
        joint_test_link_num;
        %Joint Test Fequency (Hz)
        joint_test_freq;
        %Joint Test Amplitude (degrees)
        joint_test_amp;
        %Joint Zero Everything (0=No,1=Yes)
        joint_zero;
    end
    
	properties (Access = private) %%% JOINT CONTROLLER PRIVATE PROPERTIES %%%
        joint_test_time_start = 0;
        joint_test_time_delta = 0;
    end
end

function c = Interpolate1D(a, b, alpha)
    c = a.*(1-alpha) + b.*alpha;
end

function Rz = Rz_func(th)
    Rz = [cos(th), -sin(th); sin(th), cos(th)];
end

function da = SolveForDeltaAlpha(HAlpha, s, y)
    a1 = HAlpha(1);
    a2 = HAlpha(2);
    a3 = HAlpha(3);
    a4 = HAlpha(4);
    a5 = HAlpha(5);
    a6 = HAlpha(6);
    da = -(y - a6*s^5 + a1*(s - 1)^5 - 5*a2*s*(s - 1)^4 + 5*a5*s^4*(s - 1) + 10*a3*s^2*(s - 1)^3 - 10*a4*s^3*(s - 1)^2)/(s - 1)^5;
end