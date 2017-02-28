function [u, log] = getTorques(obj, t, x)
q = x(1:end/2);
dq = x(end/2+1:end);

if strcmp(obj.currentDomain.name, 'RightStance')
    H0 = obj.H0_RightStance;
elseif strcmp(obj.currentDomain.name, 'LeftStance')
    H0 = obj.H0_LeftStance;
else
    error('Domain name unrecognized...')
end

%% Compute outputs

% Compute gait timing variable
[s, s_unsat, ds] = obj.getS(t, obj.t0);

% Feedback
[y, dy] = obj.getErrors(x, s, ds, obj.currentDomain.name);

% Calculating Torques
u = obj.kp .* (H0 \ y) + obj.kd .* (H0 \ dy);

% Logging
log.y = y;
log.dy = dy;
log.s = s;
log.s_unsat = s_unsat;
log.ds = ds;
end
