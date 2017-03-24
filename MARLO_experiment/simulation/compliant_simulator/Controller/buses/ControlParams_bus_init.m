%% Use the optimized results
% % Load in optimization parameters
c2o_transform=[     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     1     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     1     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     1     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     1     0     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     0     1     0     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     0     0     1     0     0     0     0     0     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     1     0     0     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     1     0     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     1     0     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     0     1     0     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     0     0     1     0     0     0     0
     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     1     0
     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     1];

 link2gear_transform=eye(17,17);
 link2gear_transform([5 6 7 8 12 13 14 15],:)= link2gear_transform([7 8 5 6 14 15 12 13],:);
 

 M=[ 0, 1/2, 1/2, 0,   0,   0
 0,   0,   0, 0, 1/2, 1/2
 0,  -1,   1, 0,   0,   0
 0,   0,   0, 0,  -1,   1
 1,   0,   0, 0,   0,   0
 0,   0,   0, 1,   0,   0]; % M is from u to output;
q_sym = sym('q',[16,1]);
% outputs_Right = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];
% outputs_Left  = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];
% outputs_Right = [mean(q_sym(8:9)); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];
% outputs_Left  = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14));   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];
outputs_Right = [mean(q_sym(8:9)); mean(q_sym(13:14));   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];
outputs_Left  = [mean(q_sym(8:9)); mean(q_sym(13:14));   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)];

H0_RightStance_opt = eval(jacobian(outputs_Right,q_sym));
H0_LeftStance_opt = eval(jacobian(outputs_Left,q_sym));

T=0.5;
ct_RightStance = 1/T; 
ct_LeftStance = 1/T; 

H0_RightStance_controller=H0_RightStance_opt*c2o_transform* link2gear_transform;
H0_LeftStance_controller=H0_LeftStance_opt*c2o_transform* link2gear_transform;


HAlpha_q_RightStance = pi*[ 1 1 1 1 1 1;
                            1 1 1 1 1 1;
                            1/3 1/3 1/3 1/3 1/3 1/3;
                            1/3 1/3 7/12 7/12 1/3 4/12;
                            0 0 0 0 0 0;
                            0 0 0 0 0 0];
HAlpha_q_LeftStance = pi*[  1 1 1 1 1 1;
                            1 1 1 1 1 1;
                            1/3 1/3 7/12 7/12 1/3 4/12;
                            1/3 1/3 1/3 1/3 1/3 1/3;
                            0 0 0 0 0 0;
                            0 0 0 0 0 0];  
%  HAlpha_q_RightStance = pi*[ 1 1 1 1 1 1;
%                             1 1 1 1 1 1;
%                             1/3 1/3 1/3 1/3 1/3 1/3;
%                             1/3 1/3 1/3 1/3 1/3 1/3;
%                             0 0 0 0 0 0;
%                             0 0 0 0 0 0];
% HAlpha_q_LeftStance = pi*[  1 1 1 1 1 1;
%                             1 1 1 1 1 1;
%                             1/3 1/3 1/3 1/3 1/3 1/3;
%                             1/3 1/3 1/3 1/3 1/3 1/3;
%                             0 0 0 0 0 0;
%                             0 0 0 0 0 0];  

% Construct Control Parameters Bus
ControlParams.RightStance.H0 = H0_RightStance_controller;
ControlParams.RightStance.ct = ct_RightStance;
ControlParams.RightStance.HAlpha_q = HAlpha_q_RightStance;
ControlParams.RightStance.M=M;

ControlParams.LeftStance.H0 = H0_LeftStance_controller;
ControlParams.LeftStance.ct = ct_LeftStance;
ControlParams.LeftStance.HAlpha_q = HAlpha_q_LeftStance;
ControlParams.LeftStance.M=M;

createBusObject(ControlParams, 'ControlParams_bus');

               
                         


