%% Initialize Controller Parameters here
kp_ctrl = 80;
kd_ctrl = 1;
kp_hip_ctrl = 40;
kd_hip_ctrl = 1;

if isSim
    hold_ctrl = 0;
else
    hold_ctrl = 1;
end

controller_choice_ctrl = 2; %Controller Choice (1=joint,2=VC)

%% VC Controller Parameters
zero_error_ctrl = 1; % (0=No,1=Yes)
torso_control_ctrl = 1; % (0=No,1=Yes)
regulate_velocity_ctrl = 1; % (0=No,1=Yes)

floatDamper_ctrl = 1; % (0=No,1=Yes)
threeD_ctrl = 1; %3D Controller (0=No,1=Yes)
LimitSwHipAngle_ctrl = 1; % (0=No,1=Yes)

if isSim
    s_period_ctrl = 0.45;
    jointPassivity_ctrl = 1;
else
    s_period_ctrl = 1;
    jointPassivity_ctrl = 0;
end

deltaStKA_ctrl = zeros(1,6);
deltaSwKA_ctrl = zeros(1,6);

if isSim
    deltaSwHA_ctrl = 0;
    deltaSwLA_ctrl = 0.0559;
    footPlacementLA_ctrl = 0.4; % MUST BE POSITIVE
    footPlacementHA_ctrl = -0.3; % MUST BE NEGATIVE
else
    deltaSwHA_ctrl = -0.0273;
    deltaSwLA_ctrl = -0.005;
    footPlacementLA_ctrl = 0.5;
    footPlacementHA_ctrl = -0.8;
end

%% Joint Controller Parameters
joint_test_link_num_ctrl = 1;
joint_test_freq_ctrl = 0.2;
joint_test_amp_ctrl = 5;
joint_zero_ctrl = 1; %zero outputs (0=No,1=Yes)

%% Error checking
