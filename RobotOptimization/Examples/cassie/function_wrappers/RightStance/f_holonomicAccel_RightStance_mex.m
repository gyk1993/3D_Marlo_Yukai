function [ output ] = f_holonomicAccel_RightStance_mex( vars )
%F_HOLONOMICACCEL Function wrapper to combine mathematica and matlab
% generated functions for comupting the holonomic position constraint. 

% Input variables - {'q',,'dq',ddq'}
DOF = 22;
q = vars(1:DOF);
dq = vars(DOF+1:2*DOF);
ddq = vars(2*DOF+1:end);

%% Construct constraint from mathematica generated functions

% Fixed
f_name = 'f_holConstrAcceleration_fixed';
tmp1 = feval(f_name,[q,dq,ddq]);

% Four bar
f_name = 'f_holConstrAcceleration_fourbar';
tmp2 = feval(f_name,[q,dq,ddq]);

% Back toe
f_name = 'f_holConstrAcceleration_toebottomrightback';
tmp3 = feval(f_name,[q,dq,ddq]);

% Front toe
f_name = 'f_holConstrAcceleration_toebottomrightfront';
tmp4 = feval(f_name,[q,dq,ddq]);

% J*ddq + dJ*dq = 0
output = [tmp1; tmp2; tmp3; tmp4];

