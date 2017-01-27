%% Script to test animation of robot

addpath(genpath('../gen'))

t = 0;
q = zeros(5,1)'; q(2) = 1; q(4) = 3*pi/4; q(5) = 5*pi/4;
positions_function = @positions;

FactorTime = 1;
RobotAnimator(t, q, positions_function, FactorTime)