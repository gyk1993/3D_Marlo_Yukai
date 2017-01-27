function [ output ] = J_flatFoot_RightStance_mex( vars )
%J_FLATFOOT Function wrapper to combine mathematica generated 
% functions for computing the jacobian of the flat foot constraint. 

% Input variables - {'q'}
q = vars;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_toebottomleftback';
tmp1 = feval(f_name,[q,zeros(1,length(q))]);

f_name = 'J_toebottomleftfront';
tmp2 = feval(f_name,[q,zeros(1,length(q))]);

output = tmp1(3,:) - tmp2(3,:);


