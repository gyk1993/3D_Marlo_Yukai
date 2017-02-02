classdef Controller < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    
	% PUBLIC PROPERTIES =====================================================
	properties         
		Kp = 10;
        Kd = 1;
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
	
        function [output] = ...
                userStep(obj, input)   
            
            % Extract input 
            obj.t = input.t;    
            q = input.q;
            dq = input.dq;
            ControlParams = input.ControlParams;
            ControlState = input.ControlState;		
          
            % ----- Insert Controller here ------
            
            u = zeros(6,1);
            
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