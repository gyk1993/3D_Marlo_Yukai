function [value, direction, domainTransition] = s_unsat(t, x, current_domain, controller)
[~, s_unsat, ~] = controller.getS(obj, t, t0);

value = s_unsat - 3;
direction = +1;
domainTransition = current_domain.nextDomainTransition;
end
