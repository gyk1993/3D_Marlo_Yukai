function [ dJ ] = dJhol_LeftStance( x )
%DJHOL_LEFTSTANCE dJ of holonomic constraints for cassie left stance

% Call all individual jacobians
dJ1 = dJhol_fixed(x);
dJ2 = dJhol_4barKnee(x);
dJ3 = dJ_toebottomleftback(x);
dJ4 = dJ_toebottomleftfront(x);
dJ4(1,:) = [];

% Construct full Jacobian
dJ = [dJ1; dJ2; dJ3; dJ4];

end

