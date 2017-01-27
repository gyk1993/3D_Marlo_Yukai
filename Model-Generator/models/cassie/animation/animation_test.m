%% Script to test animation of robot

addpath(genpath('../gen'))

t = 0;
q = zeros(1,22);

q1 = outputs{1}.q(1,:);
q2 = outputs{1}.q(ceil(end/2),:);
q3 = outputs{1}.qend(end,:);

positions_function = @positions;

FactorTime = 1;
RobotAnimator(t, q1, positions_function, FactorTime)
RobotAnimator(t, q2, positions_function, FactorTime)
RobotAnimator(t, q3, positions_function, FactorTime)