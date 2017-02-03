% Load in optimization parameters
MAT_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\RobotOptimization\Examples\atrias\mat\';
optimization = load([MAT_PATH,'walkingInPlace_v1']);


% Pitch, SwingLeg, StanceKnee, SwingKnee, Roll, SwingHip
q_sym = sym('q',[13,1]);
outputs_Right = [q_sym(3); mean(q_sym(6:7));   q_sym(7)-q_sym(6); q_sym(5)-q_sym(4); q_sym(2); q_sym(13)];
outputs_Left  = [q_sym(3);   mean(q_sym(4:5)); q_sym(5)-q_sym(4); q_sym(7)-q_sym(6); q_sym(2);  q_sym(10)];

H0_RightStance = eval(jacobian(outputs_Right,q_sym));
H0_LeftStance = eval(jacobian(outputs_Left,q_sym));

ct_RightStance = 1/optimization.outputs{1}.t(1); 
ct_LeftStance = 1/optimization.outputs{2}.t(1); 


% Right Stance Bezier Params
HAlpha_q_RightStance_new = bezfit(linspace(0,1,29), optimization.outputs{1}.q', 5);
HAlpha_q_RightStance = zeros(13,6);
HAlpha_q_RightStance(1:3,:) = HAlpha_q_RightStance_new([5,4,6],:);
HAlpha_q_RightStance(4:13,:) = HAlpha_q_RightStance_new([8,9,13,14,8,9,7,13,14,12],:);
HAlpha_q_RightStance(13,:) = -HAlpha_q_RightStance(13,:);

HAlpha_dq_RightStance_new = bezfit(linspace(0,1,29), optimization.outputs{1}.dq', 5);
HAlpha_dq_RightStance = zeros(13,6);
HAlpha_dq_RightStance(1:3,:) = HAlpha_dq_RightStance_new([5,4,6],:);
HAlpha_dq_RightStance(4:13,:) = HAlpha_dq_RightStance_new([8,9,13,14,8,9,7,13,14,12],:);
HAlpha_dq_RightStance(13,:) = -HAlpha_dq_RightStance(13,:);

% Left Stance Bezier Params
HAlpha_q_LeftStance_new = bezfit(linspace(0,1,29), optimization.outputs{2}.q', 5);
HAlpha_q_LeftStance = zeros(13,6);
HAlpha_q_LeftStance(1:3,:) = HAlpha_q_LeftStance_new([5,4,6],:);
HAlpha_q_LeftStance(4:13,:) = HAlpha_q_LeftStance_new([8,9,13,14,8,9,7,13,14,12],:);
HAlpha_q_LeftStance(13,:) = -HAlpha_q_LeftStance(13,:);

HAlpha_dq_LeftStance_new = bezfit(linspace(0,1,29), optimization.outputs{2}.dq', 5);
HAlpha_dq_LeftStance = zeros(13,6);
HAlpha_dq_LeftStance(1:3,:) = HAlpha_dq_LeftStance_new([5,4,6],:);
HAlpha_dq_LeftStance(4:13,:) = HAlpha_dq_LeftStance_new([8,9,13,14,8,9,7,13,14,12],:);
HAlpha_dq_LeftStance(13,:) = -HAlpha_dq_LeftStance(13,:);

% Construct Control Parameters Bus
ControlParams.RightStance.H0 = H0_RightStance;
ControlParams.RightStance.ct = ct_RightStance;
ControlParams.RightStance.HAlpha_q = HAlpha_q_RightStance;
ControlParams.RightStance.HAlpha_dq = HAlpha_dq_RightStance;

ControlParams.LeftStance.H0 = H0_LeftStance;
ControlParams.RightStance.ct = ct_LeftStance;
ControlParams.LeftStance.HAlpha_q = HAlpha_q_LeftStance;
ControlParams.LeftStance.HAlpha_dq = HAlpha_dq_LeftStance;

createBusObject(ControlParams, 'ControlParams_bus');

