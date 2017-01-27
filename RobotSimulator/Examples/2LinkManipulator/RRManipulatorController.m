classdef RRManipulatorController < Simulator.ControllerAbstract
	methods
		function [u, log] = getTorques(obj, t, x)
			if mod(floor(t/5), 2) == 0
				p_desired = [1; 1];
			else
				p_desired = [-1; 1];
			end
			
			q_current = x(1:2);
			
			[~, p_current] = model.pos(x);
			
			x_desired = [q_current; 0; 0];
			for i = 1:10
				[~, p_tmp] = model.pos(x_desired);
				[~, J] = model.posJacobians(x_desired);
				delta_p = p_desired - p_tmp;

				delta_q = (J' * delta_p) .* 0.1;
				x_desired = x_desired + [delta_q; 0; 0];
			end
			
			kp = 100;
			kd = 10;
			K = [kp, 0, kd, 0; 0, kp, 0, kd];
			u = K * (x_desired - x);
			
			log.p_desired = p_desired;
			log.p_current = p_current;
		end
		function [terminate, log] = BetweenDomains(obj, t, x_minus, x_plus, nextDomain)
			error('Should not be called');
		end
	end
	
end
