classdef (Abstract) ControllerAbstract < handle
    properties
        name = '';
    end
    
    methods (Abstract)
        [u, log] = getTorques(obj, t, x);
        [terminate, log] = BetweenDomains(obj, t, x_minus, x_plus, nextDomain);
    end
end
