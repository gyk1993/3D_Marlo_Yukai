classdef WalkInPlaceController < Simulator.ControllerAbstract
    properties
        currentDomain
        
        HAlpha_RightStance
        HAlpha_LeftStance
        
        H0_RightStance
        H0_LeftStance
        
        velocity_filtered
        alpha = 0.8;
        
        RegulateVelocity = true;
        SmoothenErrors = false;
        
        t0 = 0;
        T = 1/3;
        Kp = 1000;
        Kd = 100;
    end
    
	methods
        function obj = WalkInPlaceController()
            
        end
    end
end
