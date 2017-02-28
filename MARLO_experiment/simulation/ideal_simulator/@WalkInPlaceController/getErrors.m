function [y, dy] = getErrors(obj, x, s, ds, domainName)
q = x(1:end/2);
dq = x(end/2+1:end);

if strcmp(domainName, 'RightStance')
    HAlpha = obj.HAlpha_RightStance;
    H0 = obj.H0_RightStance;
elseif strcmp(domainName, 'LeftStance')
    HAlpha = obj.HAlpha_LeftStance;
    H0 = obj.H0_LeftStance;
else
    error('Domain name unrecognized...')
end

if obj.RegulateVelocity
    Rz = @(th) [cos(th), -sin(th); sin(th), cos(th)];
    velocity_current = Rz(q(6))'*dq(1:2);
    obj.velocity_filtered = obj.velocity_filtered.*(1 - obj.alpha) + velocity_current.*(obj.alpha);
    velocity_error = obj.velocity_filtered - [0; 0];
    
    swingHipAdjustment = -0.3 * velocity_error(1);
    swingLegAdjustment = 0.3 * velocity_error(2);
    
    error('NOT IMPLEMENTED YET');
end

% Feedback
ya = H0 * q;
dya = H0 * dq;

yd = bezierv(HAlpha, s);
dyd = bezierd(HAlpha, s) * ds;

y = ya - yd;
dy = dya - dyd;
end
