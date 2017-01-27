function [ output ] = J_holonomicVel_LeftStance_mex( vars )
%J_HOLONOMICPOS Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic velocity constraint. 

% Input variables - {'q',dq'}
DOF = 16;
nFe1 = 4;
nFe2 = 3;
q = vars(1:DOF);
dq = vars(DOF+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Four bar
f_name = 'J_holConstrVelocity_fourBar';
J1 = feval(f_name,[q,dq]);

% Stance Foot
f_name_1 = 'J_holConstrVelocity_LeftFoot';
tmp1 = feval(f_name_1,[q,dq]);
f_name_2 = 'Js_holConstrVelocity_LeftFoot';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J2 = zeros(nFe2,2*DOF);
for i = 1:size(tmp2,1)
    J2(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end

% Jac(J*dq)
output = [J1; J2];

end
