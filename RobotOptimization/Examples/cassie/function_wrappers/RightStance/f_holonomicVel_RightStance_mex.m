function [ output ] = f_holonomicVel_RightStance_mex( vars )
%F_HOLONOMICVEL Function wrapper to combine mathematica and matlab
% generated functions for comupting the holonomic velocity constraint. 

% Input variables - {'q',dq'}
DOF = 22;
q = vars(1:DOF);
dq = vars(DOF+1:end);

%% Construct constraint from mathematica generated functions

% Fixed
f_name = 'f_holConstrVelocity_fixed';
tmp1 = feval(f_name,[q,dq]);

% Four bar
f_name = 'f_holConstrVelocity_fourbar';
tmp2 = feval(f_name,[q,dq]);

% Back toe
f_name = 'f_holConstrVelocity_toebottomrightback';
tmp3 = feval(f_name,[q,dq]);

% Front toe
f_name = 'f_holConstrVelocity_toebottomrightfront';
tmp4 = feval(f_name,[q,dq]);

% J*dq = 0
output = [tmp1; tmp2; tmp3; tmp4];

