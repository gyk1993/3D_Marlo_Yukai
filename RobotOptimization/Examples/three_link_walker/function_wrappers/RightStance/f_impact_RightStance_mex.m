function [ output ] = f_impact_RightStance_mex( vars )
%F_impact_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the impact constraint. 

% Input variables - {'q','dq','Fimp','dq_end'}
DOF = 5;
nFimp = 2;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
Fimp = vars(2*DOF+1:2*DOF+nFimp);
dq_end = vars((2*DOF+nFimp+1):end);

%% Construct dynamics constraint from mathematica + matlab generated functions
f_name_1_root = 'f_impactDynamics';
tmp1 = zeros(DOF,1);
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    tmp1(i) = feval(f_name_1,[q,dq,dq_end]);
end

f_name_2 = 'f_holConstrImpactForce_leftFoot';
tmp2 = feval(f_name_2,[q,Fimp]);

f_name_3 = 'f_holConstrVelocity_leftFoot';
tmp3 = feval(f_name_3,[q,dq_end]);

%       tmp1            tmp2
% (D*(dq_end - dq)) - (J'*Fimp) = 0
output1 = tmp1 - tmp2;
%  J'*dq_end = 0
output2 = tmp3;

output = [output1; output2];
end

