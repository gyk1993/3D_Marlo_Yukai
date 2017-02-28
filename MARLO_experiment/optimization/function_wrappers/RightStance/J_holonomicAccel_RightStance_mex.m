function [ output ] = J_holonomicAccel_RightStance_mex( vars )
%J_HOLONOMICACCEL Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic acceleration constraint. 

% Input variables - {'q',dq','ddq'}
DOF = 16;
nFe1 = 4;
nFe2 = 3;
q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Four bar
f_name = 'J_holConstrAcceleration_fourBar';
J1 = feval(f_name,[q,dq,ddq]);

% Back toe
f_name_1 = 'J_holConstrAcceleration_RightFoot';
tmp1 = feval(f_name_1,[q,dq,ddq]);
f_name_2 = 'Js_holConstrAcceleration_RightFoot';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J2 = zeros(nFe2,3*DOF);
for i = 1:size(tmp2,1)
    J2(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end


% Jac(J*ddq+dJ*dq)
output = [J1; J2];

