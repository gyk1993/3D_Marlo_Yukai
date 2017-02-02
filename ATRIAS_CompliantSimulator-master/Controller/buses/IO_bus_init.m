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