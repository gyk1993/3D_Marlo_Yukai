function [ dJ ] = dJhol_LeftStance( x )
%DJHOL_LEFTSTANCE dJ of holonomic constraints for atrias left stance

% Call all individual jacobians
dJ1 = dJhol_FourBar(x);
dJ2 = dJ_LeftFoot(x);

% Construct full Jacobian
dJ = [dJ1; dJ2];

end

