function [ output ] = J_dynamics_RightStance_mex( vars )
%J_DYNAMICS_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the jacobian of the dynamics constraint. 

% Input variables - {'q','dq','ddq','u','Fe'}
DOF = 5;
DOA = 2;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:3*DOF);
u = vars(3*DOF+1:(3*DOF)+DOA);
Fe = vars((3*DOF+1)+DOA:end);

%% Construct dynamics constraint from mathematica generated functions
f_name_1_root = 'J_naturalDynamics'; % Evaluates row of jacobian matrix
f_name_2_root = 'Js_naturalDynamics'; % Gets non-zero jacobian indices
J_natural = zeros(DOF,length([q,dq,ddq,u,Fe]));
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    f_name_2 = [f_name_2_root,num2str(i)];
    tmp1 = feval(f_name_1,[q,dq,ddq,u]);
    tmp2 = feval(f_name_2,0);
    J_natural(i,tmp2(:,2)) = tmp1; % Construct Jacobian
end

% External Force from holonomic constraints
J_tmp1 = zeros(DOF,length([q,Fe]));
J_lambda = zeros(DOF,length([q,dq,ddq,u,Fe]));
f_name_3 = 'J_holConstrExternalForce_rightFoot';
tmp3 = feval(f_name_3,[q,Fe]);
f_name_4 = 'Js_holConstrExternalForce_rightFoot';
tmp4 = feval(f_name_4,0);
for i = 1:size(tmp4,1)
    J_tmp1(tmp4(i,1),tmp4(i,2)) = tmp3(i); % Construct Jacobian
end
% Construct Full Jacobian
J_lambda(:,1:DOF) = J_tmp1(:,1:DOF);
J_lambda(:,3*DOF+DOA+1:end) = J_tmp1(:,DOF+1:end);

%           tmp1                  tmp2
% Jac(D*ddq + C*dq + G - B*u) - Jac(J'*Fe) = 0
output = J_natural - J_lambda;
