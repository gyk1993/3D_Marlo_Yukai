function [ output ] = f_guard_groundHeight_RightStance_mex( vars, extra )
%F_GUARD_GROUNDHEIGHT Function wrapper to combine mathematica generated 
% functions for comupting the guard constraint. 

% Input variables - {'q'}
% Extra variables - groundHeight
q = vars;
groundHeight = extra;

%% Construct constraint from mathematica generated functions
f_name_1 = 'p_leftFoot';
tmp = feval(f_name_1,q);

% swingFootHeight - groundHeight = 0
output = tmp(2) - groundHeight;

