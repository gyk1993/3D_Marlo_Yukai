function [ output ] = J_guard_groundHeight_RightStance_mex( vars, extra )
%J_GUARD_GROUNDHEIGHT Function wrapper to combine mathematica generated 
% functions for comupting the jacobian of the guard constraint. 

% Input variables - {'q'}
% Extra variables - groundHeight
q = vars;
groundHeight = extra;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_toebottomleftback';
tmp1 = feval(f_name,[q,zeros(1,length(q))]);

f_name = 'J_toebottomleftfront';
tmp2 = feval(f_name,[q,zeros(1,length(q))]);

% Jac(swingFootHeight - groundHeight)
output = [tmp1(3,:); tmp2(3,:)];


