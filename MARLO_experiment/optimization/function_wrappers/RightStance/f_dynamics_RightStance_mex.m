function [ output ] = f_dynamics_RightStance_mex( vars )
%F_DYNAMICS_RIGHTSTANCE Function wrapper to combine mathematica and matlab
% generated functions for comupting the dynamics constraint. 

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

%% Construct dynamics constraint from mathematica + matlab generated functions
f_name_1_root = 'f_naturalDynamics';
NaturalDynamics = zeros(DOF,1);
for i = 1:DOF
    f_name_1 = [f_name_1_root,num2str(i)];
    NaturalDynamics(i) = feval(f_name_1,[q,dq,ddq,u]);
end

% Four Bar
f_name = 'f_holConstrExternalForce_fourBar';
Force1 = feval(f_name,[q,Fe1]);

% Right Foot
f_name = 'f_holConstrExternalForce_RightFoot';
Force2 = feval(f_name,[q,Fe2]);

%     NaturalDynamics    External Forces
% (D*ddq + C*dq + G - B*u) - (J'*Fe) = 0
% ExternalForce = Force1 + Force2;
ExternalForce = Force1 + Force2;
output = NaturalDynamics - ExternalForce;

