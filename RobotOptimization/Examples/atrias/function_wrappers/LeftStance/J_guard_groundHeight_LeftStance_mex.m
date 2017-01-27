function [ output ] = J_guard_groundHeight_LeftStance_mex( vars, extra )
%J_GUARD_GROUNDHEIGHT Function wrapper to combine mathematica generated 
% functions for comupting the jacobian of the guard constraint. 

% Input variables - {'q'}
% Extra variables - groundHeight
q = vars;
groundHeight = extra;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_RightFoot';
tmp = feval(f_name,[q,zeros(1,length(q))]);

% Jac(swingFootHeight - groundHeight)
output = tmp(3,:);

end


