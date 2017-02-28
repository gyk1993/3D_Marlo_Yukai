function [terminate, log] = BetweenDomains(obj, t, x_minus, x_plus, nextDomain)

if obj.SmoothenErrors
    [s_prev, ~, ds_prev] = getS(t, obj.t0);
    error('NOT IMPLEMENTED YET');
end

obj.currentDomain = nextDomain;
obj.t0 = t;

if x_minus(3) < 0.25
    terminate = true;
else
    terminate = false;
end

log = [];

end