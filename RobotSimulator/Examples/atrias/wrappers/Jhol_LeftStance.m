function [ J ] = Jhol_LeftStance( x )
%JHOL_LEFTSTANCE Jacobian of holonomic constraints for atrias left stance

% Call all individual jacobians
J1 = Jhol_FourBar(x);
J2 = J_LeftFoot(x);

% Construct full Jacobian
J = [J1; J2];

end

