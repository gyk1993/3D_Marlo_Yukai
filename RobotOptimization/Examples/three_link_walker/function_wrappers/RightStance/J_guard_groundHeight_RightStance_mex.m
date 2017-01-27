function [ output ] = J_guard_groundHeight_RightStance_mex( vars, extra )
%J_GUARD_GROUNDHEIGHT Function wrapper to combine mathematica generated 
% functions for comupting the jacobian of the guard constraint. 

% Input variables - {'q'}
% Extra variables - groundHeight
q = vars;
groundHeight = extra;

%% Construct dynamics constraint from mathematica generated functions
f_name = 'J_leftFoot';
tmp = reshape(feval(f_name,q),[],length(q));

% Jac(h - h_des)
output = tmp(2,:);


