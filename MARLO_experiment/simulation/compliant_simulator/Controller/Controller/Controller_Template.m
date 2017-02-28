classdef Controller_Template < Controller_MARLO
	%MIKHAILCONTROLLER Mikhail's controller.
	%
	% Copyright   2015 Mikhail S. Jones
    
	% PUBLIC PROPERTIES =====================================================
	properties         
				
    end % properties
	
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		
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
