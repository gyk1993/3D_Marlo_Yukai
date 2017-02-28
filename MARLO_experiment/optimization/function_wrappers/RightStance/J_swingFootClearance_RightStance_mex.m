function [ output ] = J_swingFootClearance_RightStance_mex( vars, extra )
%J_SWINGFOOTCLEARANCE Function wrapper to combine mathematica generated 
% functions for computing the jacobian of the foot clearance constraint. 

% Input variables - {'q'}
q = vars;
footClearance_des = extra;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_LeftFoot';
tmp = feval(f_name,[q,zeros(1,length(q))]);

output = -tmp(3,:);


