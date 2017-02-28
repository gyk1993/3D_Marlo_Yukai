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
Data.u = zeros(6,1);
Data.y = zeros(6,1);
Data.dy = zeros(6,1);
Data.ya = zeros(6,1);
Data.dya = zeros(6,1);
Data.yd = zeros(6,1);
Data.dyd = zeros(6,1);
Data.s = 0;
Data.s_unsat = 0;
Data.ds = 0;

Data.Domain = 0;
Data.s_R = 0;
Data.s_L = 0;
Data.fz_R = 0;
Data.fz_L = 0;

Data.velFiltered = zeros(3,1);
Data.velMeasured = zeros(3,1);

Data.swingHipAdjustment = 0;
Data.swingLegAdjustment = 0;

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