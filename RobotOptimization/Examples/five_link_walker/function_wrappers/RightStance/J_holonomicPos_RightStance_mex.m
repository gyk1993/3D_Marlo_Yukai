function [ output ] = J_holonomicPos_RightStance_mex( vars )
%J_HOLONOMICPOS Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic position constraint. 

% Input variables - {'q',h'}
DOF = 7;
nHolConstraints = 2;
q = vars(1:DOF);
h = vars(DOF+1:end);

%% Construct dynamics constraint from mathematica generated functions
f_name_1 = 'J_holConstrPosition_rightFoot';
tmp1 = feval(f_name_1,[q,h]);
f_name_2 = 'Js_holConstrPosition_rightFoot';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J = zeros(nHolConstraints,DOF+nHolConstraints);
for i = 1:size(tmp2,1)
    J(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Jac(h - h_des)
output = J;

