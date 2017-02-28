function [ output ] = f_holonomicVel_LeftStance_mex( vars )
%F_HOLONOMICVEL Function wrapper to combine mathematica and matlab
% generated functions for comupting the holonomic velocity constraint. 

% Input variables - {'q',dq'}
DOF = 16;
q = vars(1:DOF);
dq = vars(DOF+1:end);

%% Construct constraint from mathematica generated functions

% Four bar
f_name = 'f_holConstrVelocity_fourBar';
tmp1 = feval(f_name,[q,dq]);

% Back toe
f_name = 'f_holConstrVelocity_LeftFoot';
tmp2 = feval(f_name,[q,dq]);

% J*dq = 0
output = [tmp1; tmp2];

