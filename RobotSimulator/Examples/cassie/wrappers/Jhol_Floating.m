function [ J ] = Jhol_Floating( x )
%JHOL_FLOATING Jacobian of holonomic constraints for cassie floating base

% Call all individual jacobians
J1 = Jhol_fixed(x);
J2 = Jhol_4barKnee(x);

% Construct full Jacobian
J = [J1; J2];

end

