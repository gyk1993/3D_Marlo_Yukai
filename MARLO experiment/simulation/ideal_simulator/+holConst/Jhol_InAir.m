function [ J ] = Jhol_InAir( x )
%JHOL_LEFTSTANCE Jacobian of holonomic constraints for atrias left stance

% Call all individual jacobians
J1 = Jhol_FourBar(x);
J2 = J_holConstrPosition_TorsoTop(x);

% Construct full Jacobian
J = [J1; J2];

end
