function [ output ] = J_holonomicPos_RightStance_mex( vars )
%J_HOLONOMICPOS Function wrapper to combine mathematica generated functions
% for comupting the jacobian of the holonomic position constraint. 

% Input variables - {'q',h'}
DOF = 22;
nh1 = 4; % Fixed joints
nh2 = 2; % Four bar 
nh3 = 3; % Back toe
nh4 = 3; % Front toe

q = vars(1:DOF);
h1 = vars(DOF+1:DOF+nh1);
h2 = vars(DOF+nh1+1:DOF+nh1+nh2);
h3 = vars(DOF+nh1+nh2+1:DOF+nh1+nh2+nh3);
h4 = vars(DOF+nh1+nh2+nh3+1:end);

%% Construct dynamics constraint from mathematica generated functions

% Fixed
f_name = 'J_holConstrPosition_fixed';
J_tmp = feval(f_name,[q,h1]);
% Construct Full Jacobian
J1 = zeros(nh1,DOF+nh1+nh2+nh3+nh4);
J1(:,1:DOF) = J_tmp(:,1:DOF);
J1(:,DOF+1:DOF+nh1) = J_tmp(:,DOF+1:end);

% Four bar
f_name = 'J_holConstrPosition_fourbar';
J_tmp = feval(f_name,[q,h2]);
% Construct Full Jacobian
J2 = zeros(nh2,DOF+nh1+nh2+nh3+nh4);
J2(:,1:DOF) = J_tmp(:,1:DOF);
J2(:,DOF+nh1+1:DOF+nh1+nh2) = J_tmp(:,DOF+1:end);

% Back toe
f_name_1 = 'J_holConstrPosition_toebottomrightback';
tmp1 = feval(f_name_1,[q,h3]);
f_name_2 = 'Js_holConstrPosition_toebottomrightback';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J_tmp = zeros(nh3,DOF+nh3);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
% Construct Full Jacobian
J3 = zeros(nh3,DOF+nh1+nh2+nh3+nh4);
J3(:,1:DOF) = J_tmp(:,1:DOF);
J3(:,DOF+nh1+nh2+1:DOF+nh1+nh2+nh3) = J_tmp(:,DOF+1:end);

% Front toe
f_name_1 = 'J_holConstrPosition_toebottomrightfront';
tmp1 = feval(f_name_1,[q,h4]);
f_name_2 = 'Js_holConstrPosition_toebottomrightfront';
tmp2 = feval(f_name_2,0);
% Construct Jacobian
J_tmp = zeros(nh4,DOF+nh4);
for i = 1:size(tmp2,1)
    J_tmp(tmp2(i,1),tmp2(i,2)) = tmp1(i); 
end
% Construct Full Jacobian
J4 = zeros(nh4,DOF+nh1+nh2+nh3+nh4);
J4(:,1:DOF) = J_tmp(:,1:DOF);
J4(:,DOF+nh1+nh2+nh3+1:end) = J_tmp(:,DOF+1:end);

% output = [J1; J2; J3];
output = [J1; J2; J3; J4];

end

