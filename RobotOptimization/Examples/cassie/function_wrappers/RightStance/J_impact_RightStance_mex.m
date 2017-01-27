function [ output ] = J_impact_RightStance_mex( vars )
%J_IMPACT_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the jacobian of the impact constraint. 

% Input variables - {'q','dq','Fimp','dq_end'}
DOF = 22;
nFimp1 = 4;
nFimp2 = 2;
nFimp3 = 3;
nFimp4 = 3;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
Fimp1 = vars(2*DOF+1:2*DOF+nFimp1);
Fimp2 = vars(2*DOF+nFimp1+1:2*DOF+nFimp1+nFimp2);
Fimp3 = vars(2*DOF+nFimp1+nFimp2+1:2*DOF+nFimp1+nFimp2+nFimp3);
Fimp4 = vars(2*DOF+nFimp1+nFimp2+nFimp3+1:2*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
dq_end = vars(2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1:end);

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
J_ImpactDynamics = zeros(DOF,3*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
J_ImpactDynamics(:,1:2*DOF) = J_tmp(:,1:2*DOF);
J_ImpactDynamics(:,(2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1):end) = J_tmp(:,2*DOF+1:end);


% Fixed
J_Force1 = zeros(size(J_ImpactDynamics));
f_name = 'J_holConstrImpactForce_fixed';
J_tmp = feval(f_name,[q,Fimp1]);
J_Force1(:,1:DOF) = J_tmp(:,1:DOF);
J_Force1(:,2*DOF+1:2*DOF+nFimp1) = J_tmp(:,DOF+1:end);
f_name = 'J_holConstrVelocity_fixed';
J_tmp = feval(f_name,[q,dq_end]);
J_velConstr1 = zeros(nFimp1,3*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
J_velConstr1(:,1:DOF) = J_tmp(:,1:DOF);
J_velConstr1(:,2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1:end) = J_tmp(:,DOF+1:end);

% Four Bar
f_name = 'J_holConstrImpactForce_fourbar';
J_tmp = feval(f_name,[q,Fimp2]);
J_Force2 = zeros(size(J_ImpactDynamics));
J_Force2(:,1:DOF) = J_tmp(:,1:DOF);
J_Force2(:,2*DOF+nFimp1+1:2*DOF+nFimp1+nFimp2) = J_tmp(:,DOF+1:end);
f_name = 'J_holConstrVelocity_fourbar';
J_tmp = feval(f_name,[q,dq_end]);
J_velConstr2 = zeros(nFimp2,3*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
J_velConstr2(:,1:DOF) = J_tmp(:,1:DOF);
J_velConstr2(:,2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1:end) = J_tmp(:,DOF+1:end);

% Back toe
f_name = 'J_holConstrImpactForce_toebottomleftback';
tmp1 = feval(f_name,[q,Fimp3]);
f_name = 'Js_holConstrImpactForce_toebottomleftback';
tmp2 = feval(f_name,0);
J_tmp = zeros(DOF,DOF+nFimp3);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
J_Force3 = zeros(size(J_ImpactDynamics));
J_Force3(:,1:DOF) = J_tmp(:,1:DOF);
J_Force3(:,2*DOF+nFimp1+nFimp2+1:2*DOF+nFimp1+nFimp2+nFimp3) = J_tmp(:,DOF+1:end);

f_name = 'J_holConstrVelocity_toebottomleftback';
tmp1 = feval(f_name,[q,dq_end]);
f_name = 'Js_holConstrVelocity_toebottomleftback';
tmp2 = feval(f_name,0);
J_tmp = zeros(nFimp3,2*DOF);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
J_velConstr3 = zeros(nFimp3,3*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
J_velConstr3(:,1:DOF) = J_tmp(:,1:DOF);
J_velConstr3(:,2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1:end) = J_tmp(:,DOF+1:end);

% Front toe
f_name = 'J_holConstrImpactForce_toebottomleftfront';
tmp1 = feval(f_name,[q,Fimp4]);
f_name = 'Js_holConstrImpactForce_toebottomleftfront';
tmp2 = feval(f_name,0);
J_tmp = zeros(DOF,DOF+nFimp4);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
J_Force4 = zeros(size(J_ImpactDynamics));
J_Force4(:,1:DOF) = J_tmp(:,1:DOF);
J_Force4(:,2*DOF+nFimp1+nFimp2+nFimp3+1:2*DOF+nFimp1+nFimp2+nFimp3+nFimp4) = J_tmp(:,DOF+1:end);

f_name = 'J_holConstrVelocity_toebottomleftfront';
tmp1 = feval(f_name,[q,dq_end]);
f_name = 'Js_holConstrVelocity_toebottomleftfront';
tmp2 = feval(f_name,0);
J_tmp = zeros(nFimp4,2*DOF);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
J_velConstr4 = zeros(nFimp4,3*DOF+nFimp1+nFimp2+nFimp3+nFimp4);
J_velConstr4(:,1:DOF) = J_tmp(:,1:DOF);
J_velConstr4(:,2*DOF+nFimp1+nFimp2+nFimp3+nFimp4+1:end) = J_tmp(:,DOF+1:end);

% Jac(D*(dq_end - dq)) - Jac(J'*Fimp) = 0
J_ImpactForce = J_Force1 + J_Force2 + J_Force3 + J_Force4;
output1 = J_ImpactDynamics - J_ImpactForce;
% Jac(J'*dq_end)
output2 = [J_velConstr1; J_velConstr2; J_velConstr3; J_velConstr4];

output = [output1; output2];
% output = output1;
end

