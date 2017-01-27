function [ output ] = f_swingFootClearance_LeftStance_mex( vars, extra )
%F_SWINGFOOTCLEARANCE Function wrapper to combine mathematica generated 
% functions for computing the swing foot clearance constraint. 

% Input variables - {'q'}
q = vars;
footClearance_des = extra;

%% Construct constraint from mathematica generated functions
f_name = 'p_toebottomrightback';
tmp1 = feval(f_name,q);

f_name = 'p_toebottomrightfront';
tmp2 = feval(f_name,q);

output = [footClearance_des - tmp1(3); footClearance_des - tmp2(3)];

