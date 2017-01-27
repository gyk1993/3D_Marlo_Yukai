classdef Passive_Controller < Simulator.ControllerAbstract
	methods
		function [u, log] = getTorques(obj, t, x)
            % Return 0 for all torques
			u = zeros(6,1);
            log = [];
        end
        
		function [terminate, log] = BetweenDomains(obj, t, x_minus, x_plus, nextDomain)
			terminate = false;
			log = [];
		end
	end
	
end
