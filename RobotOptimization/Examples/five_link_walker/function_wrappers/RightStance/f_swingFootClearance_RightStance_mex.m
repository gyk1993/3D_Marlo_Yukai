function [ output ] = f_swingFootClearance_RightStance_mex( vars, extra )
%F_SWINGFOOTCLEARANCE Function wrapper to combine mathematica generated 
% functions for computing the swing foot clearance constraint. 

% Input variables - {'q'}
q = vars;
footClearance_des = extra;

%% Construct constraint from mathematica generated functions
f_name_1 = 'p_leftFoot';
tmp = feval(f_name_1,q);
output = tmp(2) - footClearance_des;

