%% Initialize Controller Parameters here
c_Kp_link=80;
c_Kd_link=1;
c_Kp_hip=30;
c_Kd_hip=1;


% c_Kp = [50 0 0 0 0 0;
%     0 50 0 0 0 0;
%     0 0 50 0 0 0;
%     0 0 0 50 0 0;
%     0 0 0 0 100 0;
%     0 0 0 0 0 100;];
% c_Kd = 5*[1 0 0 0 0 0;
%     0 1 0 0 0 0;
%     0 0 1 0 0 0;
%     0 0 0 1 0 0;
%     0 0 0 0 1 0;
%     0 0 0 0 0 1;];

c_Kfd_p=0.4;
c_Kfd_r=0.8;
c_v1_offset = -0.02;
c_v2_offset = -0.03;
c_knee_stretch=0;
c_st_knee_offset=5;
c_Kfp_p=0.7;
c_Kfp_r=0.6;
c_pitch_fil_para=0.004;
c_roll_fil_para=0.1;
c_frequency_test=1;
c_joint_num_test=2;
c_amplitude_test=10;
c_hold=1;
c_zero=0;
c_torso_control_switch=1;
c_foot_placement_switch=1;
c_passivity = 1;
c_hold_s = 1;
c_steptime=0.4;
c_temp_switch=0;
c_nonlinear_foot_placement=1;


%simulation
if isSim == 1
c_hold_s = 0;
c_Kfd_p=0.5;
c_Kfd_r=0.8;
c_v1_offset = -0.02;
c_v2_offset = -0.03;
c_knee_stretch=0.8;
c_st_knee_offset=0;
end