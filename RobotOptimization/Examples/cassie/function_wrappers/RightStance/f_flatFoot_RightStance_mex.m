function [ output ] = f_flatFoot_RightStance_mex( vars )
%F_FLATFOOT Function wrapper to combine mathematica generated 
% functions for computing the flat foot constraint. 

% Input variables - {'q'}
q = vars;

%% Construct constraint from mathematica generated functions
f_name = 'p_toebottomleftback';
tmp1 = feval(f_name,q);

f_name = 'p_toebottomleftfront';
tmp2 = feval(f_name,q);

output = tmp1(3) - tmp2(3);

