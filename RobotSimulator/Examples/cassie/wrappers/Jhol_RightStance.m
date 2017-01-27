function [ J ] = Jhol_RightStance( x )
%JHOL_RIGHTSTANCE Jacobian of holonomic constraints for cassie right stance

% Call all individual jacobians
J1 = Jhol_fixed(x);
J2 = Jhol_4barKnee(x);
J3 = J_toebottomrightback(x);
J4 = J_toebottomrightfront(x);
J4(1,:) = [];

% Construct full Jacobian
J = [J1; J2; J3; J4];

end

