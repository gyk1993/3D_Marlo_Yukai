classdef (Abstract) DomainAbstract < handle
    properties
        name = '';
    end
    
    methods
        [dx, log] = FullDynamics(obj, t, x, u);
        [value, direction, nextDomainTransition] = guardFunction(obj, t, x);
    end
end
