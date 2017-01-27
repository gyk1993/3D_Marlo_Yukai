function [ output ] = f_stepLength_LeftStance_mex( vars, extra )
%F_STEPLENGTH Function wrapper to combine mathematica generated 
% functions for computing the step length constraint. 

% Input variables - {'q'}
q = vars;
steplength = extra(1:3);
selected = extra(4:6);

%% Construct constraint from mathematica generated functions
f_name = 'p_toebottomright';
tmp1 = feval(f_name,q);

f_name = 'p_toebottomleft';
tmp2 = feval(f_name,q);

output = tmp1 - tmp2 - steplength;
output = selected .* output;

end
