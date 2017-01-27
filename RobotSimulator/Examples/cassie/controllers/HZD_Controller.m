classdef HZD_Controller < Simulator.ControllerAbstract
    properties
        currentDomain
        H0_RightStance
        H0_LeftStance
        ct_RightStance
        ct_LeftStance
        HAlpha_RightStance
        HAlpha_LeftStance
        t0 = 0;
        Kp = 1000;
        Kd = 100;
    end
    
	methods
		function [u, log] = getTorques(obj, t, x)
            % Split state
            q = x(1:end/2);
            dq = x(end/2+1:end);
          
            % Choose controller parameters
            if strcmp(obj.currentDomain.name, 'RightStance')
                H0 = obj.H0_RightStance;
                ct = obj.ct_RightStance;
                HAlpha = obj.HAlpha_RightStance;
            elseif strcmp(obj.currentDomain.name, 'LeftStance')
                H0 = obj.H0_LeftStance;
                ct = obj.ct_LeftStance;
                HAlpha = obj.HAlpha_LeftStance;
            else
                error('Domain name unrecognized...')
            end
            
            %% Compute outputs
            
            % Compute gait timing variable
            s = ct * (t-obj.t0);
            ds = ct;
            dds = 0;
            
            % Saturate s
            if s > 1 
                s = 1;
%                 ds = 0;
            elseif s < 0 
                s = 0;
%                 ds = 0;
            end
            
            % Compute controlled coordinates
            h0 = H0 * q;
            dh0 = H0 * dq;
            
            % Compute desired values
            hd = bezierv(HAlpha, s);
            dhd_ds  = beziervd(HAlpha, s);
            ddhd_ds = bezierva(HAlpha, s);
            dhd = dhd_ds*ds;
            
            % Compute outputs
            y = h0 - hd;
            dy = dh0 - dhd;
            
            %% Find Control Torques
            I = eye(length(hd));
            dh_dq = I*H0;
            
            D = obj.currentDomain.D_funcHandle(x);
            C = obj.currentDomain.C_funcHandle(x);
            G = obj.currentDomain.G_funcHandle(x);
            B = obj.currentDomain.B_funcHandle(x);
            J = obj.currentDomain.Jhol_funcHandle(x);
            dJ = obj.currentDomain.dJhol_funcHandle(x);
            
            % HZD Controller       
            M_c = [D, J'; J, zeros(size(J, 1))];
            H_c = [C*dq + G; dJ*dq];
            B_c = [B; zeros(size(dJ, 1), size(B, 2))];
            dh_dq_c = [dh_dq, zeros(size(dh_dq,1),size(dJ,1))];
            
            LgLfh = dh_dq_c*(M_c\B_c);
            Lf2h = -dh_dq_c*(M_c\H_c)  - ddhd_ds*dds - ddhd_ds*ds^2;
            
            % Compute torques
            u = -inv(LgLfh)*(Lf2h + obj.Kp.*y + obj.Kd.*dy);
            
            log.y = y;
            log.dy = dy;
            log.s = s;
            log.ds = ds;
            
        end
        
        
        
		function [terminate, log] = BetweenDomains(obj, t, x_minus, x_plus, nextDomain)
            obj.currentDomain = nextDomain;
            obj.t0 = t;
			terminate = false;
            log = [];
        end
	end
	
end
