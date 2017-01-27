clear all;

addpath('../../');

%% Inistializing simulator, system, and controller

RRManipulatorDomain = Simulator.GenericMechanicalDomain();
RRManipulatorDomain.D_funcHandle = @model.D_func;
RRManipulatorDomain.C_funcHandle = @model.C_func;
RRManipulatorDomain.G_funcHandle = @model.G_func;
RRManipulatorDomain.B_funcHandle = @model.B_func;

sim = Simulator.Simulator();
sim.maxTimeInDomain = 20;
sim.nSteps = 1;
sim.Controller = RRManipulatorController();
sim.currentDomain = RRManipulatorDomain;

%% Running simulation

log = sim.Simulate(0, [0; 0; 0; 0]);

%% Plotting

title('End Effector Position vs Time');
figure(1); hold on;
plot(log.continuous.Dynamics.t, log.continuous.Controller.logs.p_current);
plot(log.continuous.Dynamics.t, log.continuous.Controller.logs.p_desired, '--');
xlabel('time (s)');
ylabel('End Effector Position (m)');
legend({'X-Position', 'Y-Position','X-Position Desired', 'Y-Position Desired'});
