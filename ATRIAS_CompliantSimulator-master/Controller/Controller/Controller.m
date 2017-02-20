classdef Controller < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    
	% PUBLIC PROPERTIES =====================================================
	properties         

    end % properties
	
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		velcocity_filtered = [0;0;0];	
        Kp = 10;
        Kd = 1;
        ks_leg = 2690.8;
        impact_thre = 200;
        Kfd_p=0.25;
        Kfd_r=0.15
	end % properties
	
	% PUBLIC METHODS ========================================================
	methods
		function userSetup(obj)
			%USERSETUP Initialize system object.
			
		end % userSetup
        function [output] = ...
            userStep(obj, input)   
            
            % Extract input 
            t = input.t;    
            q = input.q;
            dq = input.dq;
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;		
          
            % ----- Insert Controller here ------
%             Hd=[0;3/4*pi;5/4*pi;0;3/4*pi;5/4*pi];

            % Decide which leg is on the ground
            ControlState.s = (t - ControlState.LastStepTime)*ControlParams.LeftStance.ct;
            % cs is used in the bazier curve
            if ControlState.s>1.05
                cs=1.05;
            elseif ControlState.s<-0.05;
                cs=-0.05;
            else
                cs=ControlState.s;
            end
            switch_flag=decide_phase(obj,q,ControlState.StanceLeg,ControlState.s);
            if switch_flag==1
                ControlState.StanceLeg=-ControlState.StanceLeg;
                ControlState.LastStepTime=t;
            end
            
            if ControlState.StanceLeg==1;
                ControlParams_choice=ControlParams.RightStance;
                swing_leg_index=2;
                swing_hip_index=6;
            elseif ControlState.StanceLeg==-1;
                ControlParams_choice=ControlParams.LeftStance;
                swing_leg_index=1;
                swing_hip_index=5;
            else
                disp('Something wrong with the ControlState.StanceLeg');
            end
            
            Hd=bezier(ControlParams_choice.HAlpha_q,cs);
            Hd(swing_leg_index)=Hd(swing_leg_index)+obj.Kfd_p*(-dq(1));
            Hd(swing_hip_index)=Hd(swing_hip_index)+obj.Kfd_r*(-dq(2));
            dHd=bezier(ControlParams_choice.HAlpha_dq,cs);
%             Hd=[-1/8*pi;7/8*pi-1/8*pi;9/8*pi-1/8*pi;1/8*pi;7/8*pi+1/8*pi;9/8*pi+1/8*pi];
%             H0=zeros(6,17); H0(1:3,4:6)=eye(3);H0(4:6,11:13)=eye(3);
            H0=ControlParams_choice.H0;
            y=H0*q-Hd;
            dy=H0*dq-dHd;
            
            Kd=50*eye(6);
            Kp=1000*eye(6);

            u = zeros(6,1);
            
            u=ControlParams_choice.M^-1*(-Kd*dy-Kp*y);
            
            
            % Store Data
            Data.q = q;
            Data.dq = dq;
            Data.u = u;
            Data.y=y;
            Data.dy=dy;
            Data.s=ControlState.s;
            Data.cs=cs;
%             Data.Hd = Hd;
%             Data.dHd = dHd;
            
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
function switch_flag=decide_phase(obj,q,stanceleg_flag,s)
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

fz_st = 2*obj.ks_leg*(cos(q_pitch + q_st_lB)*(q_st_mA - q_st_lA) - cos(q_pitch + q_st_lA)*(q_st_mB - q_st_lB))/sin(q_st_lA - q_st_lB);
fz_sw = 2*obj.ks_leg*(cos(q_pitch + q_sw_lB)*(q_sw_mA - q_sw_lA) - cos(q_pitch + q_sw_lA)*(q_sw_mB - q_sw_lB))/sin(q_sw_lA - q_sw_lB);



if (fz_sw>obj.impact_thre && s>0.5) || s>2 
    switch_flag=1;
else
    switch_flag=0;
end
end
