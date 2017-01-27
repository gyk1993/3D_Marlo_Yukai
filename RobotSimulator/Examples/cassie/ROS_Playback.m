%% ROS Initialization
ROS_init;

%% ROS Playpack
dt = 0.01;
Ts = mean(diff(t_log));
time_playback_factor = .01;

trajectory_log = ROS_JointTrajectory(t_log, q_log, dt, Ts, time_playback_factor);
disp('Publishing Joint Trajectory')
pub = rospublisher('/set_joint_trajectory', 'trajectory_msgs/JointTrajectory');
send(pub,trajectory_log);

