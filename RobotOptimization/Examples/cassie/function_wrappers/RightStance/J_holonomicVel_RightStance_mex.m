function [ output ] = J_holonomicVel_RightStance_mex( vars )
%J_HOLONOMICPOS Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic velocity constraint. 

% Input variables - {'q',dq'}
DOF = 22;
nFe1 = 4;
nFe2 = 2;
nFe3 = 3;
nFe4 = 3;
q = vars(1:DOF);
dq = vars(DOF+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Fixed
f_name = 'J_holConstrVelocity_fixed';
J1 = feval(f_name,[q,dq]);

% Four bar
f_name = 'J_holConstrVelocity_fourbar';
J2 = feval(f_name,[q,dq]);

% Back toe
f_name_1 = 'J_holConstrVelocity_toebottomrightback';
tmp1 = feval(f_name_1,[q,dq]);
f_name_2 = 'Js_holConstrVelocity_toebottomrightback';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J3 = zeros(nFe3,2*DOF);
for i = 1:size(tmp2,1)
    J3(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Front toe
f_name_1 = 'J_holConstrVelocity_toebottomrightfront';
tmp1 = feval(f_name_1,[q,dq]);
f_name_2 = 'Js_holConstrVelocity_toebottomrightfront';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J4 = zeros(nFe4,2*DOF);
for i = 1:size(tmp2,1)
    J4(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Jac(J*dq)
output = [J1; J2; J3; J4];
% output = [J1; J2; J3];

