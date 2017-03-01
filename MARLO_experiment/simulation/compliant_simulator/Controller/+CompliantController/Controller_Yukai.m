classdef Controller_Yukai < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    
	% PUBLIC PROPERTIES =====================================================
	properties         
        Kp;
        Kd;
        Kfd_p;
        Kfd_r;
        Kfp_p;
        Kfp_r;
        pitch_fil_para;
        roll_fil_para;
    end % properties
	
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		velcocity_filtered = [0;0;0];	

        ks_leg = 2690.8;
        impact_thre = 200;
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
            pitch_tune=0;
            roll_tune=0;
            pitch_tune_fil=0;
            roll_tune_fil=0;
            
            
            % Decide which leg is on the ground
            ControlState.s = (t - ControlState.LastStepTime)*ControlParams.LeftStance.ct;
            s=ControlState.s;
            s=0;
            % cs is used in the bazier curve
            if s>1.05
                cs=1.05;
            elseif s<-0.05;
                cs=-0.05;
            else
                cs=s;
            end
            switch_flag=decide_phase(obj,q,ControlState.StanceLeg,s);
            if switch_flag==1
                ControlState.StanceLeg=-ControlState.StanceLeg;
                ControlState.LastStepTime=t;
                cs=0;
                s=0;
                if ControlState.StanceLeg==1
                    ControlParams.RightStance.HAlpha_q(:,1)=ControlState.hd;
                    ControlParams.RightStance.HAlpha_q(:,2)=ControlState.hd+ControlState.dhd/ControlParams.RightStance.ct/5;
                else
                    ControlParams.LeftStance.HAlpha_q(:,1)=ControlState.hd;
                    ControlParams.LeftStance.HAlpha_q(:,2)=ControlState.hd+ControlState.dhd/ControlParams.LeftStance.ct/5;
                end
            end
            [st_leg_i,st_hip_i,sw_leg_i,sw_hip_i,ControlParams_choice]=get_index(ControlState,ControlParams);

            
            H0=ControlParams_choice.H0;
            dh0=H0*dq;
            h0=H0*q;
            hd=bezier(ControlParams_choice.HAlpha_q,cs);
            dhd=bezierd(ControlParams_choice.HAlpha_q,cs)*ControlParams_choice.ct;
            pitch_tune=obj.Kfd_p*(dh0(st_leg_i)+dq(1)); % Here pitch is pitch of the stance leg, not torso. In other word, the absolute stance leg angle
            pitch_tune=sign(pitch_tune)*min(abs(obj.Kfd_p*(dh0(st_leg_i)+dq(1))),0.3);
            pitch_tune_fil=first_order_filter(ControlState.pitch_tune,pitch_tune,obj.pitch_fil_para);
            hd(sw_leg_i)=hd(sw_leg_i)-pitch_tune_fil;
            
%             if st_hip_i==5 && dh0(st_hip_i)<0 || st_hip_i==6 && dh0(st_hip_i)>0
%                 roll_tune=obj.Kfd_r*(dh0(st_hip_i));
%             else
%                 roll_tune=0;
%             end
%             roll_tune_fil=first_order_filter(ControlState.roll_tune,roll_tune,obj.roll_fil_para);
%             hd(sw_hip_i)=hd(sw_hip_i)-roll_tune;
            
            y=h0-hd;
            dy=dh0-dhd;
            u = zeros(6,1);
%             y(st_leg_i)=-q(1);
%             y(st_hip_i)=-q(2);

           u=ControlParams_choice.M^-1*(-obj.Kd*dy-obj.Kp*y);
%            u(1)=-100*(q(4)-0)-5*(dq(4)-0);
%            u(4)=-100*(q(11)-0)-5*(dq(11)-0);
%             u=(-obj.Kd*ControlParams_choice.M^-1*dy-obj.Kp*ControlParams_choice.M^-1*y);

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
            %Store state and param
            ControlState.hd=hd;
            ControlState.dhd=dhd;
            ControlState.h0=h0;
            ControlState.dh0=dh0;
            ControlState.pitch_tune=pitch_tune_fil;
            ControlState.roll_tune=roll_tune_fil;
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

function [st_leg_i,st_hip_i,sw_leg_i,sw_hip_i,ControlParams_choice]=get_index(ControlState,ControlParams)
if ControlState.StanceLeg==1;
    ControlParams_choice=ControlParams.RightStance;
    sw_leg_i=2;
    sw_hip_i=6;
    st_leg_i=1;
    st_hip_i=5;
else ControlState.StanceLeg==-1;
    ControlParams_choice=ControlParams.LeftStance;
    sw_leg_i=1;
    sw_hip_i=5;
    st_leg_i=2;
    st_hip_i=6;
end
end
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
% if s>1
    switch_flag=1;
else
    switch_flag=0;
end
end
function filtered=first_order_filter(prev,new,para)
    filtered=prev*(1-para)+new*para;
end