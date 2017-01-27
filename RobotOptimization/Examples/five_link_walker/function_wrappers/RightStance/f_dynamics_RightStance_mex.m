function [ output ] = f_dynamics_RightStance_mex( vars )
%F_DYNAMICS_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the dynamics constraint. 

% Input variables - {'q','dq','ddq','u','Fe'}
DOF = 7;
DOA = 4;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:3*DOF);
u = vars(3*DOF+1:(3*DOF)+DOA);
Fe = vars((3*DOF+1)+DOA:end);

%% Construct dynamics constraint from mathematica + matlab generated functions
f_name_1_root = 'f_naturalDynamics';
tmp1 = zeros(DOF,1);
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    tmp1(i) = feval(f_name_1,[q,dq,ddq,u]);
end

f_name_2 = 'f_holConstrExternalForce_rightFoot';
tmp2 = feval(f_name_2,[q,Fe]);

%           tmp1              tmp2
% (D*ddq + C*dq + G - B*u) - (J'*Fe) = 0
output = tmp1 - tmp2;

