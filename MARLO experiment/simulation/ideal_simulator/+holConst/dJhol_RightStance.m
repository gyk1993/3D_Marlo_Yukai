function [ dJ ] = dJhol_RightStance( x )
%DJHOL_RIGHTSTANCE dJ of holonomic constraints for atrias right stance

% Call all individual jacobians
dJ1 = dJhol_FourBar(x);
dJ2 = dJ_RightFoot(x);

% Construct full Jacobian
dJ = [dJ1; dJ2];


end

