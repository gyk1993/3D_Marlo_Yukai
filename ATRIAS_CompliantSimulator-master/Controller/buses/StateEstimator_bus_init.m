%% Script to initialize the StateEstimator bus

StateEstimator.Enabled = 0;
StateEstimator.mu = zeros(22,1);
StateEstimator.q = zeros(16,1); % Configuration Estimate
StateEstimator.v = zeros(3,1); % Velocity Estimate in body frame
StateEstimator.contactR = 0;
StateEstimator.contactL = 0;

createBusObject(StateEstimator, 'StateEstimator_bus');