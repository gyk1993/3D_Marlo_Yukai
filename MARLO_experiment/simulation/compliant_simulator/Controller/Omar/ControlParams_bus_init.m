% Load in optimization parameters
gait = CompliantController.GetManualGait('Only2D',false,'SwingLegControlTorso',false);
% gait = CompliantController.GetGaitFromOptMat('C:\Users\oharib\Documents\GitHub\Omar-MARLO_WalkInPlace\gait-params\optGait.mat',...
%     'Only2D',false,'SwingLegControlTorso',false);

ControlParams = cell2struct(gait.outputs, gait.domainNames, 2);

createBusObject(ControlParams, 'ControlParams_bus');
