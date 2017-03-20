%% Initialize Controller Parameters here
c_Kp_link=60;
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

c_Kfd_p=0.6;
c_Kfd_r=0.4;
c_Kfp_p=0.7;
c_Kfp_r=0.6;
c_pitch_fil_para=0.01;
c_roll_fil_para=0.1;
c_frequency_test=1;
c_joint_num_test=2;
c_amplitude_test=10;
c_hold=1;
c_zero=0;
c_torso_control=1;
c_passivity = 0;
