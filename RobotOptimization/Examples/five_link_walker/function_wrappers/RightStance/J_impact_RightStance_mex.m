function [ output ] = J_impact_RightStance_mex( vars )
%J_IMPACT_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the jacobian of the impact constraint. 

% Input variables - {'q','dq','Fimp','dq_end'}
DOF = 7;
nFimp = 2;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
Fimp = vars(2*DOF+1:2*DOF+nFimp);
dq_end = vars((2*DOF+nFimp+1):end);

%% Construct dynamics constraint from mathematica generated functions

% Part 1 of first constraint
f_name_1_root = 'J_impactDynamics'; % Evaluates row of jacobian matrix
f_name_2_root = 'Js_impactDynamics'; % Gets non-zero jacobian indices
J_tmp = zeros(DOF,3*DOF);
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    f_name_2 = [f_name_2_root,num2str(i)];
    tmp1 = feval(f_name_1,[q,dq,dq_end]);
    tmp2 = feval(f_name_2,0);
    J_tmp(i,tmp2(:,2)) = tmp1; % Construct Jacobian
end
% Construct Full Jacobian
J1 = zeros(DOF,3*DOF+nFimp);
J1(:,1:2*DOF) = J_tmp(:,1:2*DOF);
J1(:,(2*DOF+nFimp+1):end) = J_tmp(:,2*DOF+1:end);


% Part 2 of first constraint
J_tmp = zeros(DOF,DOF+nFimp);
J2 = zeros(DOF,length([q,dq,Fimp,dq_end]));
f_name = 'J_holConstrImpactForce_leftFoot';
tmp1 = feval(f_name,[q,Fimp]);
f_name = 'Js_holConstrImpactForce_leftFoot';
tmp2 = feval(f_name,0);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); % Construct Jacobian
end
% Construct Full Jacobian
J2(:,1:DOF) = J_tmp(:,1:DOF);
J2(:,2*DOF+1:2*DOF+nFimp) = J_tmp(:,DOF+1:end);


% Second Constraint
J_tmp = zeros(nFimp,2*DOF);
J3 = zeros(nFimp,length([q,dq,Fimp,dq_end]));
f_name = 'J_holConstrVelocity_leftFoot';
tmp1 = feval(f_name,[q,dq_end]);
f_name = 'Js_holConstrVelocity_leftFoot';
tmp2 = feval(f_name,0);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); % Construct Jacobian
end
% Construct Full Jacobian
J3(:,1:DOF) = J_tmp(:,1:DOF);
J3(:,(2*DOF+nFimp+1):end) = J_tmp(:,DOF+1:end);

% Jac(D*(dq_end - dq)) - Jac(J'*Fimp) = 0
output1 = J1 - J2;
% Jac(J'*dq_end)
output2 = J3;

output = [output1; output2];
end

