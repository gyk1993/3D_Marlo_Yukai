classdef FloatingBase < Simulator.DomainAbstract 
    properties
        D_funcHandle = NaN;
        C_funcHandle = NaN;
        G_funcHandle = NaN;
        B_funcHandle = NaN;
        Jhol_funcHandle = NaN;
        dJhol_funcHandle = NaN;
        
        guard_funcHandle = NaN;
        nextDomainTransition = NaN;
    end
    
    methods
        function [dx, log] = FullDynamics(obj, t, x, u)
            n = length(x) / 2;
            
            q = x(1:n);
            dq = x((n+1):(2*n));
            
            D = obj.D_funcHandle(x);
            C = obj.C_funcHandle(x);
            G = obj.G_funcHandle(x);
            B = obj.B_funcHandle(x);
            
			if isa(obj.Jhol_funcHandle,'function_handle') && isa(obj.dJhol_funcHandle,'function_handle')
				Jhol = obj.Jhol_funcHandle(x);
				dJhol = obj.dJhol_funcHandle(x);
			else
				Jhol = [];
				dJhol = [];
			end
            
            m = size(Jhol, 1);
            
            D_c = [D, Jhol'; Jhol, zeros(m, m)];
            H_c = [C*dq + G; dJhol*dq];
            B_c = [B; zeros(m, size(B,2))];
            
            % Fix Base
            H_c(1:3) = H_c(1:3) + 1000*(q(1:3)-[0;0;1.5]) + 1000*dq(1:3);  
            
            ddq_c = D_c \ (B_c*u - H_c);
            
            ddq = ddq_c(1:n);
            if (m > 0)
                log.lambda = ddq_c((n+1):(n+m));
            else
                log.lambda = zeros(0, 1);
            end
            
            dx = [dq; ddq];
        end
        
        function [value, direction, nextDomainTransition] = guardFunction(obj, t, x)
			if isa(obj.guard_funcHandle, 'function_handle')
				[value, direction] = obj.guard_funcHandle(t, x, obj);
			else
				value = 1;
				direction = 1;
			end
			
            nextDomainTransition = obj.nextDomainTransition;
        end
    end
end
