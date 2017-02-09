classdef Controller < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    
	% PUBLIC PROPERTIES =====================================================
	properties         
		Kp = 10;
        Kd = 1;
        Rg_flag=0;
        Lg_flag=0;
        step_time=0;
    end % properties
	
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		velcocity_filtered = [0;0;0];	
	end % properties
	
	% PUBLIC METHODS ========================================================
	methods
		function userSetup(obj)
			%USERSETUP Initialize system object.
			
		end % userSetup
        function [Rg_flag,Lg_flag]=decide_phase(obj,q)
            
            ATRIAS3D_Positions_Left(q_old, extra_vars);
            fz_st = 2*obj.ks_leg*(cos(q_pitch + q_st_lB)*(q_st_mA - q_st_lA) - cos(q_pitch + q_st_lA)*(q_st_mB - q_st_lB))/sin(q_st_lA - q_st_lB);
			fz_sw = 2*obj.ks_leg*(cos(q_pitch + q_sw_lB)*(q_sw_mA - q_sw_lA) - cos(q_pitch + q_sw_lA)*(q_sw_mB - q_sw_lB))/sin(q_sw_lA - q_sw_lB);
`           
        end
        function [output] = ...
                userStep(obj, input)   
            
            % Extract input 
%             obj.t = input.t;    
            q = input.q;
            dq = input.dq;
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;		
          
            % ----- Insert Controller here ------
%             Hd=[0;3/4*pi;5/4*pi;0;3/4*pi;5/4*pi];
            Hd=[-1/8*pi;7/8*pi-1/8*pi;9/8*pi-1/8*pi;1/8*pi;7/8*pi+1/8*pi;9/8*pi+1/8*pi];
            H0=zeros(6,17); H0(1:3,4:6)=eye(3);H0(4:6,11:13)=eye(3);
            
            y=H0*q-Hd;
            dy=H0*dq;
            
            Kd=50*eye(6);
            Kp=1000*eye(6);

            u = zeros(6,1);
            u=-Kd*dy-Kp*y;
            
            
            % Store Data
            Data.q = q;
            Data.dq = dq;
            Data.u = u;
            
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
