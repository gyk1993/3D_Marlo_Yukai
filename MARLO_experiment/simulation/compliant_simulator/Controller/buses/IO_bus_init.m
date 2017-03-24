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

Data.q = zeros(17,1);
Data.dq = zeros(17,1);
Data.u = zeros(6,1);
Data.y = zeros(6,1);
Data.dy = zeros(6,1);
Data.s = 0;
Data.cs = 0;
Data.hd = zeros(6,1);
Data.dhd = zeros(6,1);
Data.h0 = zeros(6,1);
Data.dh0 = zeros(6,1);
Data.pitch_tune=0;
Data.roll_tune=0;
Data.pitch_tune_fil=0;
Data.roll_tune_fil=0;
Data.hd_j=zeros(6,1);
Data.dhd_j=zeros(6,1);
Data.y_j=zeros(6,1);
Data.dy_j=zeros(6,1);
Data.h0_j=zeros(6,1);
Data.dh0_j=zeros(6,1);
Data.spring_compressed=zeros(4,1);
Data.ground_force=zeros(2,1);
Data.s_force=zeros(2,1);
Data.V_measured=zeros(3,1);
Data.V_filtered=zeros(3,1);
Data.StanceLeg=0;
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