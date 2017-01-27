classdef (Abstract) DomainTransitionAbstract < handle
    properties
        name = '';
    end
    
    methods (Abstract)
        [x_plus, nextDomain, log] = Transition(obj, t, x_minus, currentDomain);
    end
end
