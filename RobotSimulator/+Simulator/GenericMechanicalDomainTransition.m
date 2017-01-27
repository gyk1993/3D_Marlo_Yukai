classdef GenericMechanicalDomainTransition < Simulator.DomainTransitionAbstract
    properties
        nextDomain = NaN;
    end
    
    methods
        function [x_minus, x_plus, nextDomain, log] = Transition(obj, t, x_minus, currentDomain)
            n = length(x_minus) / 2;
            
            q_minus = x_minus(1:n);
            dq_minus = x_minus((n+1):(2*n));
            
            Jhol = obj.nextDomain.Jhol_funcHandle(x_minus);
            D = obj.nextDomain.D_funcHandle(x_minus);
            
            Dinv = inv(D);
            
            M = inv(Jhol*Dinv*Jhol');
            
            q_plus = q_minus;
            dq_plus = (eye(n) - Dinv*Jhol'*M*Jhol)*dq_minus;
            log.Fimp = M*Jhol*(dq_plus - dq_minus);
            
            x_plus = [q_plus; dq_plus];
            nextDomain = obj.nextDomain;
        end
    end
end
