classdef Controller_Yukai < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    % Modified by Yukai Mar 20th
	% PUBLIC PROPERTIES =====================================================
	properties         
        %Kp Link
        Kp_link;      
        %Kd Link
        Kd_link;
        %Kp Hip
        Kp_hip;
        %Kd Hip
        Kd_hip;
        Kfd_p;
        Kfd_r;
        Kfp_p;
        Kfp_r;
        pitch_fil_para;
        roll_fil_para;
        
        frequency_test;
        joint_num_test;
        amplitude_test;
        torso_control_switch;
        foot_placement_switch
        hold;
        zero;
        hold_s;
        steptime;
        st_knee_offset;
        passivity;
        temp_switch;
    end % properties
	properties (Access = private) 
        tf=1;

    end
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		velcocity_filtered = [0;0;0];	
        D2R=pi/180;
        R2D=180/pi;
        ks_leg = 2690.8;
%         impact_thre = 200;
        grf_z_min = 200;        % (N)
        grf_z_max = 300;        % (N)
        du_max=15;
        hip_gravity_compensation = 1;
        hip_hit_prevention = 10*pi/180;
	end % properties
	
	% PUBLIC METHODS ========================================================
	methods
		function userSetup(obj)
			%USERSETUP Initialize system object.
			
		end % userSetup
        function [output] = ...
            userStep(obj, input)   
            
            % Extract input 
            velEst = input.velEst;
            t = input.t;    
            q = input.q;
            dq = input.dq;
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;		
          
            % ----- Insert Controller here ------
            
            
            
            
            pitch_tune=0;
            roll_tune=0;
            pitch_tune_fil=0;
            roll_tune_fil=0;
            Kp=[obj.Kp_hip 0 0 0 0 0;
                0 obj.Kp_link 0 0 0 0;
                0 0 obj.Kp_link 0 0 0;
                0 0 0 obj.Kp_hip 0 0;
                0 0 0 0 obj.Kp_link 0;
                0 0 0 0 0 obj.Kp_link];
            Kd=[obj.Kd_hip 0 0 0 0 0;
                0 obj.Kd_link 0 0 0 0;
                0 0 obj.Kd_link 0 0 0;
                0 0 0 obj.Kd_hip 0 0;
                0 0 0 0 obj.Kd_link 0;
                0 0 0 0 0 obj.Kd_link];
            
            
            % Decide which leg is on the ground
            
%             if t<3.1
%                 obj.hold_s=1;
%             elseif t<5.22
%                 obj.hold_s=0;
%             elseif t<7.13
%                 obj.hold_s=1;
%                 obj.steptime=0.1;
%             else
%                 obj.hold_s=0;
%             end
%             
            % When switch to unhold from hold, apply the new step time and
            % reset laststeptime
            if obj.hold_s == 0 && ControlState.prev_hold_s == 1
                ControlParams.RightStance.ct = 1/obj.steptime;
                ControlParams.LeftStance.ct = 1/obj.steptime;
                ControlState.LastStepTime = t-ControlState.prev_s*obj.steptime;
            end
            
            % Calculate s and ds
            ControlState.s = (t - ControlState.LastStepTime)*ControlParams.LeftStance.ct;
            s=ControlState.s;
            ds=ControlParams.LeftStance.ct;
            
            % When hold, hold s, set ds=0;
            if obj.hold_s==1
                s=ControlState.prev_s;
                ds=0;
            end
%             s=0.5;
            
            % cs is used in the bazier curve
            if s>1
                cs=1;
                dcs=0;
            elseif s<-0;
                cs=0;
                dcs=0;
            else
                cs=s;
                dcs=ds;
            end
            [switch_flag fz_st fz_sw fz_R fz_L s_R s_L]=decide_phase(obj,q,ControlState.StanceLeg,s);
            ground_force=[fz_R; fz_L];
            % Switching leg
            if switch_flag==1
                ControlState.StanceLeg=-ControlState.StanceLeg;
                ControlState.LastStepTime=t;
                cs=0;
                s=0;
                % Set first two columns of bazier parameters to make hd
                % smooth
                if ControlState.StanceLeg==1
                    ControlParams.RightStance.HAlpha_q(:,1)=ControlState.hd;
                    ControlParams.RightStance.HAlpha_q(:,2)=ControlState.hd+ControlState.dhd/ControlParams.RightStance.ct/5;
                else
                    ControlParams.LeftStance.HAlpha_q(:,1)=ControlState.hd;
                    ControlParams.LeftStance.HAlpha_q(:,2)=ControlState.hd+ControlState.dhd/ControlParams.LeftStance.ct/5;
                end
            end
            


            
            
            [st_leg_i,st_knee_i,st_hip_i,sw_leg_i,sw_knee_i,sw_hip_i,ControlParams_choice]=get_index(ControlState,ControlParams);
            
            [ V_measured V_filtered ] = get_velocity(obj,velEst,s_R,s_L,ControlState);
            
            % Calculate h0 and hd
            H0=ControlParams_choice.H0;
            dh0=H0*dq;
            h0=H0*q;
            hd=bezier(ControlParams_choice.HAlpha_q,cs);
            dhd=bezierd(ControlParams_choice.HAlpha_q,cs)*dcs;
            
            % offset for stance knee
            hd(st_knee_i)=hd(st_knee_i)-min(1,cs/0.1)*pi/180*obj.st_knee_offset;
            
            
            % foot placement
            pitch_tune=obj.Kfd_p*V_filtered(2);
            pitch_tune=sign(pitch_tune)*min(abs(pitch_tune),0.3);
            roll_tune=obj.Kfd_r*V_filtered(1);
            if obj.foot_placement_switch == 1
                hd(sw_leg_i)=hd(sw_leg_i)+pitch_tune;
                hd(sw_hip_i)=hd(sw_hip_i)+roll_tune;
            end
            
%             pitch_tune=obj.Kfd_p*(dh0(st_leg_i)+dq(1)); % Here pitch is pitch of the stance leg, not torso. In other word, the absolute stance leg angle
%             pitch_tune=sign(pitch_tune)*min(abs(obj.Kfd_p*(dh0(st_leg_i)+dq(1))),0.3);
%             pitch_tune_fil=first_order_filter(ControlState.pitch_tune,pitch_tune,obj.pitch_fil_para);
            %             hd(sw_leg_i)=hd(sw_leg_i)-pitch_tune_fil;
            
            %             if st_hip_i==5 && dh0(st_hip_i)<0 || st_hip_i==6 && dh0(st_hip_i)>0
            %                 roll_tune=obj.Kfd_r*(dh0(st_hip_i));
            %             else
            %                 roll_tune=0;
            %             end
            %             roll_tune_fil=first_order_filter(ControlState.roll_tune,roll_tune,obj.roll_fil_para);
            %             hd(sw_hip_i)=hd(sw_hip_i)-roll_tune;
            
            
            %% Safe hip angle
            if sw_hip_i == 6
                if h0(5)-hd(6) > obj.hip_hit_prevention
                    hd(6) = h0(5)-obj.hip_hit_prevention;
                    dhd(6) = dh0(5);
                end
            else
                if hd(5)-h0(6) > obj.hip_hit_prevention
                    hd(5)= h0(6)+obj.hip_hit_prevention;
                    dhd(5)= dh0(6);
                end
            end
            
            % calculate desired joint angle
            hd_j=ControlParams_choice.M^-1*hd;
            dhd_j=ControlParams_choice.M^-1*dhd;
            h0_j=ControlParams_choice.M^-1*h0;
            dh0_j=ControlParams_choice.M^-1*dh0;
            
%             % Do the sin wave test
%             [y_j dy_j ControlState] = get_error_sin_wave(obj,q,dq,s,cs,ControlParams_choice,ControlState,st_leg_i,st_hip_i,sw_leg_i,sw_hip_i);
            y=h0-hd;
            dy=dh0-dhd;
%             y_j=h0_j-hd_j;
%             dy_j=dh0_j-dhd_j;
%             
            % Controlling the torso angle
            [cp1R cp2R cp1L cp2L dcp1R dcp2R dcp1L dcp2L] = get_spring_compressed_angle(q,dq);
            spring_compressed=[cp1R; cp2R; cp1L; cp2L];
            
            % passivity for stance leg
            if obj.passivity
                y(st_leg_i) = 0;
                y(st_hip_i) = 0;
                dy(st_leg_i) = dh0(st_leg_i);
                dy(st_hip_i) = dh0(st_hip_i);
            end
            
            % torso control
            if  obj.torso_control_switch
%                 if ControlState.StanceLeg == 1
                    y(1)=s_R*(-q(1)-1/2*(cp1R+cp2R))+(1-s_R)*y(1);
                    
                    y(5)=s_R*(-q(2))+(1-s_R)*y(5);
                    dy(5)=s_R*(-dq(2))+(1-s_R)*dy(5);
%                 else
                    y(2)=s_L*(-q(1)-1/2*(cp1L+cp2L))+(1-s_L)*y(2);
                    
                    y(6)=s_L*(-q(2))+(1-s_L)*y(6);
                    dy(6)=s_L*(-dq(2))+(1-s_L)*dy(6);
%                 end

               if obj.temp_switch == 0
                   dy(2)=s_L*(-dq(1)-1/2*(dcp1L+dcp2L))+(1-s_L)*dy(2);
                   dy(1)=s_R*(-dq(1)-1/2*(dcp1R+dcp2R))+(1-s_R)*dy(1);
               else
                   dy(2)=s_L*(-dq(1))+(1-s_L)*dy(2);
                   dy(1)=s_R*(-dq(1))+(1-s_R)*dy(1);
               end
                   
            end
            
                
            % get joint error
            y_j = ControlParams_choice.M^-1*y;
            dy_j = ControlParams_choice.M^-1*dy;
            
            
                
%            u=ControlParams_choice.M^-1*(-obj.Kd*dy-obj.Kp*y);
%            u(1)=-100*(q(4)-0)-5*(dq(4)-0);
%            u(4)=-100*(q(11)-0)-5*(dq(11)-0);
%             u=-Kd*ControlParams_choice.M^-1*dy-Kp*ControlParams_choice.M^-1*y;
            u=-Kp*y_j-Kd*dy_j;
            
            % compensation for hip
            if obj.hip_gravity_compensation == 1
                u(1)=u(1)-0.8;
                u(4)=u(4)+0.8;
            end
            
            
            
            %Store state and param
            ControlState.hd=hd;
            ControlState.dhd=dhd;
            ControlState.h0=h0;
            ControlState.dh0=dh0;
            ControlState.pitch_tune=pitch_tune_fil;
            ControlState.roll_tune=roll_tune_fil;
            ControlState.prev_u=u;
            ControlState.prev_t=t;
            ControlState.prev_hold=obj.hold;
            ControlState.prev_zero=obj.zero;
            ControlState.ini=0;
            ControlState.prev_V_filtered=V_filtered;
            ControlState.prev_hold_s=obj.hold_s;
            ControlState.prev_s=s;
            
            % Store Data
            
            Data.q = q;
            Data.dq = dq;
            Data.u = u;
            Data.y=y;
            Data.dy=dy;
            Data.s=s;
            Data.cs=cs;
            Data.hd = hd;
            Data.dhd = dhd;
            Data.h0=h0;
            Data.dh0=dh0;
            Data.pitch_tune=pitch_tune;
            Data.roll_tune=roll_tune;
            Data.pitch_tune_fil=pitch_tune_fil;
            Data.roll_tune_fil=roll_tune_fil;
            Data.hd_j=hd_j;
            Data.dhd_j=dhd_j;
            Data.y_j=y_j;
            Data.dy_j=dy_j;
            Data.h0_j=h0_j;
            Data.dh0_j=dh0_j;
            Data.spring_compressed=spring_compressed;
            Data.ground_force= ground_force;
            Data.s_force = [s_R; s_L];
            Data.V_measured=V_measured;
            Data.V_filtered=V_filtered;
            Data.StanceLeg=ControlState.StanceLeg;
            % -----------------------------------
            
            % Store outputs
            output.eStop = false;
            output.u = u;
            output.Data = Data;
            output.ControlParams = ControlParams;
            output.ControlState = ControlState;

        end
      

        
    end % methods
	
end % classdef

%% LOCAL FUNCTIONS ========================================================
function [y dy]=get_error(obj,q,dq,s,cs,ControlParams_choice,st_leg_i,st_hip_i,sw_leg_i,sw_hip_i)
%             Hd=bezier(ControlParams_choice.HAlpha_q,cs);
%             Hd(swing_leg_index)=Hd(swing_leg_index)+obj.Kfd_p*(-dq(1));
%             Hd(swing_hip_index)=Hd(swing_hip_index)+obj.Kfd_r*(-dq(2));
%             dHd=bezier(ControlParams_choice.HAlpha_dq,cs);
%             Hd=[-1/8*pi;7/8*pi-1/8*pi;9/8*pi-1/8*pi;1/8*pi;7/8*pi+1/8*pi;9/8*pi+1/8*pi];
%             H0=zeros(6,17); H0(1:3,4:6)=eye(3);H0(4:6,11:13)=eye(3);
            H0=ControlParams_choice.H0;
            dh0=H0*dq;
            h0=H0*q;
            Hd=bezier(ControlParams_choice.HAlpha_q,cs);
            dHd=bezierd(ControlParams_choice.HAlpha_q,cs)*ControlParams_choice.ct;
            pitch_tune=obj.Kfd_p*(dh0(st_leg_i)+dq(1));
            pitch_tune=sign(pitch_tune)*min(abs(obj.Kfd_p*(dh0(st_leg_i)+dq(1))),0.3);
            pitch_tune_fil=pitch_tune_filter(pitch_prev,pitch,para)
            Hd(sw_leg_i)=Hd(sw_leg_i)-pitch_tune;
            if st_hip_i==5 && dh0(st_hip_i)<0 || st_hip_i==6 && dh0(st_hip_i)>0
                Hd(sw_hip_i)=Hd(sw_hip_i)-obj.Kfd_r*(dh0(st_hip_i));
            end
%             Hd(sw_leg_i)=Hd(sw_leg_i)-obj.Kfp_p*(h0(st_leg_i)-Hd(st_leg_i))-obj.Kfd_p*(dh0(st_leg_i)-dHd(st_leg_i));
%             Hd(sw_hip_i)=Hd(sw_hip_i)-obj.Kfp_r*(h0(st_hip_i)-Hd(st_hip_i))-obj.Kfd_p*(dh0(st_hip_i)-dHd(st_hip_i));
%             Hd(swing_leg_index)=Hd(swing_leg_index);
%             Hd(swing_hip_index)=Hd(swing_hip_index);
            y=H0*q-Hd;
            dy=H0*dq-dHd;
end

function [y_j dy_j ControlState] = get_error_sin_wave(obj,q,dq,s,cs,ControlParams_choice,ControlState,st_leg_i,st_hip_i,sw_leg_i,sw_hip_i)
            H0=ControlParams_choice.H0;
            dh0=H0*dq;
            h0=H0*q;
            hd=bezier(ControlParams_choice.HAlpha_q,cs);
            dhd=bezierd(ControlParams_choice.HAlpha_q,cs)*ControlParams_choice.ct;
            hd_j=ControlParams_choice.M^-1*hd;
            dhd_j=ControlParams_choice.M^-1*dhd;
            h0_j=ControlParams_choice.M^-1*h0;
            dh0_j=ControlParams_choice.M^-1*dh0;
            
            hd_j_s=hd_j;
            dhd_j_s=dhd_j;
            
            
            
            
            if obj.hold == 0
                if ControlState.prev_hold == 1 | ControlState.prev_zero==1
                    ControlState.sin_phase = ControlState.hold_phase-2*pi*obj.frequency_test*t;
                end
                [hd_j dhd_j]=add_sin_wave(obj,ControlState,hd_j,dhd_j,t);
            else
                if ControlState.prev_hold == 0 | ControlState.ini==1
                    [hd_j dhd_j]=add_sin_wave(obj,ControlState,hd_j,dhd_j,t);
                    ControlState.hold_position=hd_j;
                    ControlState.hold_phase = rem(2*pi*obj.frequency_test*t+ControlState.sin_phase , 2*pi);
                end
                hd_j=ControlState.hold_position;
                dhd_j=zeros(6,1);
            end

            if obj.zero == 1
                ControlState.hold_phase = 0;
                ControlState.hold_position=hd_j_s;
                if ControlState.prev_zero==0
                    ControlState.cubic_para = cal_cubic_para(hd_j(obj.joint_num_test),dhd_j(obj.joint_num_test),hd_j_s(obj.joint_num_test),0,obj.tf);
                    ControlState.zero_t0=t;
                end
                if t-ControlState.zero_t0<obj.tf
                    [hd_j(obj.joint_num_test) dhd_j(obj.joint_num_test)]=cubic_path(ControlState.cubic_para,t-ControlState.zero_t0);
                else
                    hd_j=ControlParams_choice.M^-1*hd;
                    dhd_j=ControlParams_choice.M^-1*dhd;
                end
            end
            y_j=h0_j-hd_j;
            dy_j=dh0_j-dhd_j;
end

function [st_leg_i,st_knee_i,st_hip_i,sw_leg_i,sw_knee_i,sw_hip_i,ControlParams_choice]=get_index(ControlState,ControlParams)
if ControlState.StanceLeg==1;
    ControlParams_choice=ControlParams.RightStance;
    sw_leg_i=2;
    sw_knee_i=4;
    sw_hip_i=6;
    st_leg_i=1;
    st_knee_i=3;
    st_hip_i=5;
else ControlState.StanceLeg==-1;
    ControlParams_choice=ControlParams.LeftStance;
    sw_leg_i=1;
    sw_knee_i=3;
    sw_hip_i=5;
    st_leg_i=2;
    st_knee_i=4;
    st_hip_i=6;
end
end

function [switch_flag fz_st fz_sw fz_R fz_L s_R s_L]=decide_phase(obj,q,stanceleg_flag,s)
q_pitch=q(1);
q_roll=q(2);
q_yaw=q(3);
q_HR=q(4);              q_HL=q(11);
q_AR=q(5);              q_AL=q(12);
q_BR=q(6);              q_BL=q(13);
q_AgrR=q(7);            q_AgrL=q(14);
q_BgrR=q(8);            q_BgrL=q(15);
q_four_bar_AR=q(9);     q_four_bar_AL=q(16);
q_four_bar_BR=q(10);    q_four_bar_BL=q(17);

if stanceleg_flag==1
    q_st_lA=q_AR;       q_sw_lA=q_AL;
    q_st_lB=q_BR;       q_sw_lB=q_BL;
    q_st_mA=q_AgrR;     q_sw_mA=q_AgrL;
    q_st_mB=q_BgrR;     q_sw_mB=q_BgrL;
else
    q_sw_lA=q_AR;       q_st_lA=q_AL;
    q_sw_lB=q_BR;       q_st_lB=q_BL;
    q_sw_mA=q_AgrR;     q_st_mA=q_AgrL;
    q_sw_mB=q_BgrR;     q_st_mB=q_BgrL;
end

if abs(q_st_lA - q_st_lB)< 1e-5 || abs(q_sw_lA - q_sw_lB) < 1e-5
    fz_st = 0;
    fz_sw = 0;
else
    fz_st = 2*obj.ks_leg*(cos(q_pitch + q_st_lB)*(q_st_mA - q_st_lA) - cos(q_pitch + q_st_lA)*(q_st_mB - q_st_lB))/sin(q_st_lA - q_st_lB);
    fz_sw = 2*obj.ks_leg*(cos(q_pitch + q_sw_lB)*(q_sw_mA - q_sw_lA) - cos(q_pitch + q_sw_lA)*(q_sw_mB - q_sw_lB))/sin(q_sw_lA - q_sw_lB);
end

if stanceleg_flag==1
    fz_R=fz_st;
    fz_L=fz_sw;
else
    fz_R=fz_sw;
    fz_L=fz_st;
end

s_R = scaleFactor(fz_R, obj.grf_z_min, obj.grf_z_max);
s_L = scaleFactor(fz_L, obj.grf_z_min, obj.grf_z_max);

if (fz_sw>obj.grf_z_max && s>0.5) || s>2
% if s>100
    switch_flag=1;
else
    switch_flag=0;
end

end

function filtered=first_order_filter(prev,new,para)
    filtered=prev*(1-para)+new*para;
end

function [hd dhd] = cubic_path(a,tau)
    hd=a(1)+a(2)*tau+a(3)*tau^2+a(4)*tau^3;
    dhd=a(2)+2*a(3)*tau+3*a(4)*tau^2;
end

function a = cal_cubic_para(q0,v0,qf,vf,tf)
    t0=0;
    M=[1 t0 t0^2 t0^3;
        0 1 2*t0 3*t0^2;
        1 tf tf^2 tf^3;
        0 1 2*tf 3*tf^2];
    a=M^-1*[q0;v0;qf;vf];
end

function [hd_j dhd_j]=add_sin_wave(obj,ControlState,hd_j,dhd_j,t)
hd_j(obj.joint_num_test)=hd_j(obj.joint_num_test)+obj.amplitude_test*obj.D2R*sin(2*pi*obj.frequency_test*t+ControlState.sin_phase);
dhd_j(obj.joint_num_test)=dhd_j(obj.joint_num_test)+obj.amplitude_test*obj.D2R*2*pi*obj.frequency_test*cos(2*pi*obj.frequency_test*t+ControlState.sin_phase);
end

function [cp1R cp2R cp1L cp2L dcp1R dcp2R dcp1L dcp2L] = get_spring_compressed_angle(q,dq)
    cp1R=q(5)-q(7);
    cp2R=q(6)-q(8);
    cp1L=q(12)-q(14);
    cp2L=q(13)-q(15);
    
    dcp1R=dq(5)-dq(7);
    dcp2R=dq(6)-dq(8);
    dcp1L=dq(12)-dq(14);
    dcp2L=dq(13)-dq(15);
    
end

function [u u_d]=smooth_torque(obj,t,u,ControlState)
    u_d=u;
    if t-ControlState.prev_t > 10e-5
        if (u_d-ControlState.prev_u)/(t-ControlState.prev_t)>obj.du_max
            u = ControlState.prev_u + obj.du_max*(t-ControlState.prev_t);
        else
            u = u_d;
        end
    end
end

function [ V_measured V_filtered ] = get_velocity(obj,velEst,s_R,s_L,ControlState)
    if ControlState.StanceLeg ==1 & s_R>0.99
        V_measured = velEst(1:3);
    elseif ControlState.StanceLeg == -1 & s_L>0.99
        V_measured = velEst(4:6);
    else
        V_measured=zeros(3,1);
    end
    V_filtered = first_order_filter(ControlState.prev_V_filtered,V_measured,obj.pitch_fil_para);
end