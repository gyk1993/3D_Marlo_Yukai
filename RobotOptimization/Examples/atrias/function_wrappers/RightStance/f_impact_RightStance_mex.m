function [ output ] = f_impact_RightStance_mex( vars )
%F_impact_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the impact constraint. 

% Input variables - {'q','dq','Fimp','dq_end'}
DOF = 16;
nFimp1 = 4;
nFimp2 = 3;

q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
Fimp1 = vars(2*DOF+1:2*DOF+nFimp1);
Fimp2 = vars(2*DOF+nFimp1+1:2*DOF+nFimp1+nFimp2);
dq_end = vars(2*DOF+nFimp1+nFimp2+1:end);

%% Construct dynamics constraint from mathematica + matlab generated functions
f_name_1_root = 'f_impactDynamics';
ImpactDynamics = zeros(DOF,1);
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    ImpactDynamics(i) = feval(f_name_1,[q,dq,dq_end]);
end

% Four Bar
f_name = 'f_holConstrImpactForce_fourBar';
Force1 = feval(f_name,[q,Fimp1]);
f_name = 'f_holConstrVelocity_fourBar';
velConstr1 = feval(f_name,[q,dq_end]);

% Swing Foot
f_name = 'f_holConstrImpactForce_LeftFoot';
Force2 = feval(f_name,[q,Fimp2]);
f_name = 'f_holConstrVelocity_LeftFoot';
velConstr2 = feval(f_name,[q,dq_end]);


%   ImpactDynamics   Impact Forces
% (D*(dq_end - dq)) - (J'*Fimp) = 0
ImpactForce = Force1 + Force2;
output1 = ImpactDynamics - ImpactForce;
%  J'*dq_end = 0
output2 = [velConstr1; velConstr2];

output = [output1; output2];
end

