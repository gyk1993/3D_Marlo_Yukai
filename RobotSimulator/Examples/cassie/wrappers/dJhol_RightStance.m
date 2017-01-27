function [ dJ ] = dJhol_RightStance( x )
%DJHOL_RIGHTSTANCE dJ of holonomic constraints for cassie right stance

% Call all individual jacobians
dJ1 = dJhol_fixed(x);
dJ2 = dJhol_4barKnee(x);
dJ3 = dJ_toebottomrightback(x);
dJ4 = dJ_toebottomrightfront(x);
dJ4(1,:) = [];

% Construct full Jacobian
dJ = [dJ1; dJ2; dJ3; dJ4];

end

