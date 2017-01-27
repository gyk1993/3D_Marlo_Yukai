classdef Simulator < handle
    properties
        ode_func = @ode45;
        Controller;
        currentDomain;
        nSteps = 1;
        maxTimeInDomain = 3;
        
    end
    
    methods
        function [logs] = Simulate(obj, t0, x0)
			logs = [];
			
            for n = 1:obj.nSteps
				log = struct();
				
				% Run ODE
                eventFunc = @(t, x) obj.CheckGuard(t, x);
                options = odeset('Events', eventFunc,...
                    'MaxStep',0.01,...
                    'InitialStep',0.001,...
                    'Refine',1,...
                    'RelTol',10^-3,...
                    'AbsTol',10^-6);
                [t, x, te, xe, ie] = obj.ode_func(@(t, x) obj.ContinuousSim(t, x), ...
                    [t0, t0 + obj.maxTimeInDomain], x0, options);
				t = t';
				x = x';
				if ~isempty(te)
					te = te(1,:)';
					xe = xe(1,:)';
					ie = ie(1,:)';
				else
					te = t(end);
					xe = x(:,end);
					ie = NaN;
                end
                

                disp(['Step ', num2str(n), ' completed.']);
				
				% Logging Continuous Phase
				log.currentDomain = obj.currentDomain;
				log.continuous = struct();
				
				for i = 1:length(t)
					[~, tmpLog] = obj.ContinuousSim(t(i), x(:,i));
					tmpLog.Dynamics.t = t(i);
					tmpLog.Dynamics.x = x(:,i);
					
					if i == 1
						log.continuous = tmpLog;
					else
						log.continuous = Simulator.util.RecurseLog(log.continuous, tmpLog);
					end
				end
                
				if isnan(ie)
					log.discrete.GuardIndex = NaN;
					log.discrete.domainTransition = NaN;
					logs = [logs, log];
					break;
				end
				
				% Implementing Transition
                [~, ~, domainTransition] = obj.currentDomain.guardFunction(te, xe);
				domainTransition = domainTransition(ie);
				log.discrete.GuardIndex = ie;
				log.discrete.domainTransition = domainTransition;
				
				if ~isa(domainTransition,'Simulator.DomainTransitionAbstract')
					logs = [logs, log];
					break;
				end
                
                [x_minus, x_plus, nextDomain, logTransition] = domainTransition.Transition(te, xe, obj.currentDomain);
				log.discrete.x_plus = x_plus;
				log.discrete.nextDomain = nextDomain;
				log.discrete.logs = logTransition;
                
				% Updating Controller about new domain (and logging)
                [terminate, logCtrlBtwnDomains] = obj.Controller.BetweenDomains(te, x_minus, x_plus, nextDomain);
				log.discrete.ControllerAfterTransition.logs = logCtrlBtwnDomains;
				log.discrete.ControllerAfterTransition.terminateFromController = terminate;
				if terminate
					logs = [logs, log];
                    disp(['Ending simulation after step ', num2str(n)]);
					break;
				end
				
				logs = [logs, log];
                obj.currentDomain = nextDomain;
                x0 = x_plus;
                t0 = te;
            end
        end
        
        function [dx, log] = ContinuousSim(obj, t, x)
            [u, logCtrl] = obj.Controller.getTorques(t, x);
            [dx, logFD] = obj.currentDomain.FullDynamics(t, x, u);
			
			log = struct();
			log.Dynamics = struct();
			log.Controller = struct();
			
			log.Controller.u = u;
			log.Controller.logs = logCtrl;
			log.Dynamics.dx = dx;
			log.Dynamics.logs = logFD;
        end
        
        function [value, isterminal, direction] = CheckGuard(obj, t, x)
            [value, direction, ~] = obj.currentDomain.guardFunction(t, x);
            isterminal = ones(size(value));
		end
    end
end
