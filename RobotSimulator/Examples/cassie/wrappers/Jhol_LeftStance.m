function [ J ] = Jhol_LeftStance( x )
%JHOL_LEFTSTANCE Jacobian of holonomic constraints for cassie left stance

% Call all individual jacobians
J1 = Jhol_fixed(x);
J2 = Jhol_4barKnee(x);
J3 = J_toebottomleftback(x);
J4 = J_toebottomleftfront(x);
J4(1,:) = [];

% Construct full Jacobian
J = [J1; J2; J3; J4];

end

