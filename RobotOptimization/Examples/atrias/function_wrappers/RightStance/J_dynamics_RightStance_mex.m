function [ output ] = J_dynamics_RightStance_mex( vars )
%J_DYNAMICS_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the jacobian of the dynamics constraint. 

% Input variables - {'q','dq','ddq','u','Fe'}
DOF = 16;
DOA = 6;
nFe1 = 4;
nFe2 = 3;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:3*DOF);
u = vars(3*DOF+1:(3*DOF)+DOA);
Fe1 = vars(3*DOF+DOA+1:3*DOF+DOA+nFe1);
Fe2 = vars(3*DOF+DOA+nFe1+1:end);

%% Construct dynamics constraint from mathematica generated functions
f_name_1_root = 'J_naturalDynamics'; % Evaluates row of jacobian matrix
f_name_2_root = 'Js_naturalDynamics'; % Gets non-zero jacobian indices
J_NaturalDynamics = zeros(DOF,length([q,dq,ddq,u,Fe1,Fe2]));
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    f_name_2 = [f_name_2_root,num2str(i)];
    J_tmp = feval(f_name_1,[q,dq,ddq,u]);
    tmp2 = feval(f_name_2,0);
    J_NaturalDynamics(i,tmp2(:,2)) = J_tmp; % Construct Jacobian
end

% Four Bar
J_Force1 = zeros(size(J_NaturalDynamics));
f_name = 'J_holConstrExternalForce_fourBar';
J_tmp = feval(f_name,[q,Fe1]);
% Construct Full Jacobian
J_Force1(:,1:DOF) = J_tmp(:,1:DOF);
J_Force1(:,3*DOF+DOA+1:3*DOF+DOA+nFe1) = J_tmp(:,DOF+1:end);

% Stance Foot
J_Force2 = zeros(size(J_NaturalDynamics));
f_name = 'J_holConstrExternalForce_RightFoot';
tmp1 = feval(f_name,[q,Fe2]);
f_name = 'Js_holConstrExternalForce_RightFoot';
tmp2 = feval(f_name,0);
% Construct Jacobian
J_tmp = zeros(DOF,DOF+nFe2);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
% Construct Full Jacobian
J_Force2(:,1:DOF) = J_tmp(:,1:DOF);
J_Force2(:,3*DOF+DOA+nFe1+1:end) = J_tmp(:,DOF+1:end);


%       J_NaturalDynamics      J_ExternalForce
% Jac(D*ddq + C*dq + G - B*u) - Jac(J'*Fe) = 0
J_ExternalForce = J_Force1 + J_Force1 + J_Force2;
output = J_NaturalDynamics - J_ExternalForce;

end
