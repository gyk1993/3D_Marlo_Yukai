function [ dJ ] = dJhol_Floating( x )
%DJHOL_FLOATING dJ of holonomic constraints for cassie floating base

% Call all individual jacobians
dJ1 = dJhol_fixed(x);
dJ2 = dJhol_4barKnee(x);

% Construct full Jacobian
dJ = [dJ1; dJ2];

end

