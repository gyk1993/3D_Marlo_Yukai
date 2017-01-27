function [ output ] = J_holonomicPos_LeftStance_mex( vars )
%J_HOLONOMICPOS Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic position constraint. 

% Input variables - {'q',h'}
DOF = 16;
nh1 = 4; % Four Bar
nh2 = 3; % Stance Foot

q = vars(1:DOF);
h1 = vars(DOF+1:DOF+nh1);
h2 = vars(DOF+nh1+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Four bar
f_name = 'J_holConstrPosition_fourBar';
J_tmp = feval(f_name,[q,h1]);
% Construct Full Jacobian
J1 = zeros(nh1,DOF+nh1+nh2);
J1(:,1:DOF) = J_tmp(:,1:DOF);
J1(:,DOF+1:DOF+nh1) = J_tmp(:,DOF+1:end);

% Stance Foot
f_name_1 = 'J_holConstrPosition_LeftFoot';
tmp1 = feval(f_name_1,[q,h2]);
f_name_2 = 'Js_holConstrPosition_LeftFoot';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J_tmp = zeros(nh2,DOF+nh2);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
% Construct Full Jacobian
J2 = zeros(nh2,DOF+nh1+nh2);
J2(:,1:DOF) = J_tmp(:,1:DOF);
J2(:,DOF+nh1+1:end) = J_tmp(:,DOF+1:end);

output = [J1; J2];

end

