% Use the optimized results
% Load in optimization parameters
MAT_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\RobotOptimization\Examples\atrias\mat\';
optimization = load([MAT_PATH,'walkingInPlace_v3']);

% c2o_transform is a matrix that transform the coordinate in optimization
% to q_new
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
 
 M=[ 0, 1/2, 1/2, 0,   0,   0
 0,   0,   0, 0, 1/2, 1/2
 0,  -1,   1, 0,   0,   0
 0,   0,   0, 0,  -1,   1
 1,   0,   0, 0,   0,   0
 0,   0,   0, 1,   0,   0];


q_sym = sym('q',[16,1]);
% RightLeg_absolute, LeftLeg_absolute, RightKnee, LeftKnee,Right_Hip_absolute, LeftHip_absolute
% outputs_Right = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7)+q_sym(5); q_sym(12)+q_sym(5)];
% outputs_Left  = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7)+q_sym(5); q_sym(12)+q_sym(5)];
% outputs_Right = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)+q_sym(5)];
% outputs_Left  = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7)+q_sym(5); q_sym(12)];
outputs_Right = [mean(q_sym(8:9)); mean(q_sym(13:14))+q_sym(4);   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7); q_sym(12)+q_sym(5)];
outputs_Left  = [mean(q_sym(8:9))+q_sym(4); mean(q_sym(13:14));   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(7)+q_sym(5); q_sym(12)];
H0_RightStance_opt = eval(jacobian(outputs_Right,q_sym));
H0_LeftStance_opt = eval(jacobian(outputs_Left,q_sym));

ct_RightStance = 1/optimization.outputs{1}.t(1); 
ct_LeftStance = 1/optimization.outputs{2}.t(1); 

H0_RightStance_controller=H0_RightStance_opt*c2o_transform;
H0_LeftStance_controller=H0_LeftStance_opt*c2o_transform;

% Right Stance Bezier Params
HAlpha_q_RightStance= bezfit(linspace(0,1,29), H0_RightStance_opt*optimization.outputs{1}.q', 5);
HAlpha_dq_RightStance= bezfit(linspace(0,1,29), H0_RightStance_opt*optimization.outputs{1}.dq', 5);

% Left Stance Bezier Params
HAlpha_q_LeftStance= bezfit(linspace(0,1,29), H0_LeftStance_opt*optimization.outputs{2}.q', 5);
HAlpha_dq_LeftStance= bezfit(linspace(0,1,29),H0_LeftStance_opt*optimization.outputs{2}.dq', 5);

% Construct Control Parameters Bus
ControlParams.RightStance.H0 = H0_RightStance_controller;
ControlParams.RightStance.ct = ct_RightStance;
ControlParams.RightStance.HAlpha_q = HAlpha_q_RightStance;
ControlParams.RightStance.HAlpha_dq = HAlpha_dq_RightStance;
ControlParams.RightStance.M=M;

ControlParams.LeftStance.H0 = H0_LeftStance_controller;
ControlParams.LeftStance.ct = ct_LeftStance;
ControlParams.LeftStance.HAlpha_q = HAlpha_q_LeftStance;
ControlParams.LeftStance.HAlpha_dq = HAlpha_dq_LeftStance;
ControlParams.LeftStance.M=M;

createBusObject(ControlParams, 'ControlParams_bus');


                         


