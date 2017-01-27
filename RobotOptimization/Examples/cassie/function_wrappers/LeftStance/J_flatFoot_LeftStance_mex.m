function [ output ] = J_flatFoot_LeftStance_mex( vars )
%J_FLATFOOT Function wrapper to combine mathematica generated 
% functions for computing the jacobian of the flat foot constraint. 

% Input variables - {'q'}
q = vars;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_toebottomrightback';
tmp1 = feval(f_name,[q,zeros(1,length(q))]);

f_name = 'J_toebottomrightfront';
tmp2 = feval(f_name,[q,zeros(1,length(q))]);

output = tmp1(3,:) - tmp2(3,:);


