function [ output ] = f_swingFootClearance_RightStance_mex( vars, extra )
%F_SWINGFOOTCLEARANCE Function wrapper to combine mathematica generated 
% functions for computing the swing foot clearance constraint. 

% Input variables - {'q'}
q = vars;
footClearance_des = extra;

%% Construct constraint from mathematica generated functions
f_name = 'p_LeftFoot';
tmp = feval(f_name,q);

output = footClearance_des - tmp(3);

