function [s, s_unsat, ds] = getS(obj, t, t0)
s_unsat = (t - obj.t0) / obj.T;

% Saturate s
if s_unsat > 1 
    s = 1;
    ds = 0;
elseif s_unsat < 0 
    s = 0;
    ds = 0;
else
    s = s_unsat;
    ds = 1;
end
end
