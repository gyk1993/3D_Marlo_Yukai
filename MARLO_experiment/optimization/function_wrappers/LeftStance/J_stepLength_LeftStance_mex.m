function [ output ] = J_stepLength_LeftStance_mex( vars, extra )
%J_STEPLENGTH Function wrapper to combine mathematica generated 
% functions for computing the jacobian of the step length constraint. 

% Input variables - {'q'}
q = vars;
stepLength = extra(1:3);
selected = extra(4:6);

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_RightFoot';
tmp1 = feval(f_name,[q,zeros(1,length(q))]);

f_name = 'J_LeftFoot';
tmp2 = feval(f_name,[q,zeros(1,length(q))]);

output = tmp1 - tmp2;
output = repmat(selected',1,size(tmp1,2)) .* output;

end
