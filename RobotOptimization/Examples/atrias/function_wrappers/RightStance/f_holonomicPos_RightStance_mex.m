function [ output ] = f_holonomicPos_RightStance_mex( vars )
%F_HOLONOMICPOSITION Function wrapper to combine mathematica and matlab
% generated functions for comupting the holonomic position constraint. 

% Input variables - {'q',h'}
DOF = 16;
nh1 = 4; % Four Bar 
nh2 = 3; % Stance Foot

q = vars(1:DOF);
h1 = vars(DOF+1:DOF+nh1);
h2 = vars(DOF+nh1+1:end);

%% Construct constraint from mathematica generated functions

% Four bar
f_name = 'f_holConstrPosition_fourBar';
tmp1 = feval(f_name,[q,h1]);

% Back toe
f_name = 'f_holConstrPosition_RightFoot';
tmp2 = feval(f_name,[q,h2]);


% h - h_des = 0
output = [tmp1; tmp2];

