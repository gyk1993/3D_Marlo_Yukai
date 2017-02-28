classdef Controller_MARLO < matlab.System & matlab.system.mixin.Propagates 
	%CONTROLLER Controller superclass.
	
	% PUBLIC PROPERTIES =====================================================
	properties
		% Simulation flag
		isSim = true
	end % properties
	
	properties
        
	end % properties
	
	% PROTECTED PROPERTIES ==================================================
	properties (Access = protected)
        runTime = 0
	end % properties
	
	% CONSTANT PROPERTIES ===================================================
	properties (Constant = true, Hidden = true)
		% Sample interval time (s)
		sampleInterval = 0.0005 %MARLO sample time
	end % properties
	
	% NONTUNABLE PROPERTIES ===================================================
    properties(Nontunable)
       OutputBusName = 'Output_bus'; 
    end
    
	% ABSTRACT METHODS ======================================================
	methods (Abstract = true)
		[] = userSetup(obj)
		[u,y_out,dy_out] = userStep(obj, t, q, dq, ControlParams, ControlState)
	end % methods
	
	% PROTECTED METHODS =====================================================
	methods (Access = protected)
		function setupImpl(obj)
			%SETUPIMPL Initialize system object.
			% Run controller specific initialization
			obj.userSetup;
		end % setupImpl
        
        function out = getOutputSizeImpl(obj)
            out = propagatedInputSize(obj, 1);
        end
        
        function out = isOutputComplexImpl(obj)
            out = propagatedInputComplexity(obj, 1);
        end
        
        function out = getOutputDataTypeImpl(obj)
            out = obj.OutputBusName;
        end
        
        function out = isOutputFixedSizeImpl(obj)
            out = propagatedInputFixedSize(obj, 1);
        end
      
		function [output] = stepImpl(obj, input)
			%STEPIMPL System output and state update equations.

			% Run controller logic
			if ~input.ControlState.Commands.Shutdown
				% Run controller
				[output] = obj.userStep(input);
            else
                [output] = obj.userStep(input);
                
				% Damping gains
				kd_leg = -1;
				kd_hip = -1;
				                                
				% Leg actuator torques computed to behave like virtual dampers
				output.u([1 2 4 5]) = (input.dq([4 5 6 7]) - 0)*kd_leg;
				output.u([3 6]) = (input.dq([10 13]) - 0)*kd_hip;

			end 
            
		end % stepImpl
	end % methods
end % classdef
