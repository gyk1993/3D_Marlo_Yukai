function [ output ] = J_holonomicAccel_LeftStance_mex( vars )
%J_HOLONOMICACCEL Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic acceleration constraint. 

% Input variables - {'q',dq','ddq'}
DOF = 22;
nFe1 = 4;
nFe2 = 2;
nFe3 = 3;
nFe4 = 3;
q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Fixed
f_name = 'J_holConstrAcceleration_fixed';
J1 = feval(f_name,[q,dq,ddq]);

% Four bar
f_name = 'J_holConstrAcceleration_fourbar';
J2 = feval(f_name,[q,dq,ddq]);

% Back toe
f_name_1 = 'J_holConstrAcceleration_toebottomleftback';
tmp1 = feval(f_name_1,[q,dq,ddq]);
f_name_2 = 'Js_holConstrAcceleration_toebottomleftback';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J3 = zeros(nFe3,3*DOF);
for i = 1:size(tmp2,1)
    J3(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Front toe
f_name_1 = 'J_holConstrAcceleration_toebottomleftfront';
tmp1 = feval(f_name_1,[q,dq,ddq]);
f_name_2 = 'Js_holConstrAcceleration_toebottomleftfront';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J4 = zeros(nFe4,3*DOF);
for i = 1:size(tmp2,1)
    J4(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Jac(J*ddq+dJ*dq)
% output = [J1; J2; J3];
output = [J1; J2; J3; J4];

