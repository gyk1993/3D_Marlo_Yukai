function [ J ] = Jhol_RightStance( x )
%JHOL_RIGHTSTANCE Jacobian of holonomic constraints for atrias right stance

% Call all individual jacobians
J1 = Jhol_FourBar(x);
J2 = J_RightFoot(x);

% Construct full Jacobian
J = [J1; J2];

end

