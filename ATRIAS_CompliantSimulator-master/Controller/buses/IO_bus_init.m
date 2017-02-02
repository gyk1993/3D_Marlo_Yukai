%% Script to initialize the input / output buses (and also the data bus)

%% Input Bus
Input_bus;

% input.t = 0;
% input.q = zeros(17,1);
% input.dq = zeros(17,1);
% input.ControlParams = ControlParams;
% input.ControlState = ControlState;
% 
% createBusObject(input, 'Input_bus');

%% Output Data Bus
clear Data
clear Data_bus

Data.q = zeros(13,1);
Data.u = zeros(6,1);
Data.y = zeros(6,1);
Data.dy = zeros(6,1);
Data.s = 0;
Data.ds = 0;

Data.vel = [0;0;0];          % EKF velocity in the body frame
Data.vel_des = [0;0;0];          % Desired velocity in the body frame
Data.vel_last = [0;0;0];     % Last EKF velocity
Data.vel_filtered = [0;0;0]; % Filtered velocity estimate
Data.vel_step_sum = [0;0;0]; % Running velocity sum for the step
Data.vel_step_average = [0;0;0];      % Running velocity average for the step
Data.vel_step_average_last = [0;0;0]; % Last step velocity average
Data.vel_kin = [0;0;0];               % Kinematic-based velocity in the body frame


Data.StanceLeg = 0;
Data.s_st = 0;
Data.s_sw = 0;

Data.fz_st = 0;
Data.fz_sw = 0;
Data.qd = zeros(13,1);
Data.offsets = zeros(2,1);

Data.stepNumber = 0;
Data.HAlpha_q = zeros(13*6,1);
Data.HAlpha_dq = zeros(13*6,1);

Data.hd_adjustment = zeros(13,1);

createBusObject(Data, 'Data_bus');

%% Output Bus
Output_bus;

% eStop = false;
% u = zeros(6,1);
% userOut = zeros(1,47);
% 
% output.eStop = false;
% output.u = zeros(6,1);
% output.Data = Data;
% output.ControlParams = ControlParams;
% output.ControlState = ControlState;
% 
% createBusObject(output, 'Output_bus');