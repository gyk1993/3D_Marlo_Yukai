%% Clear and set paths
restoredefaultpath
clear all; clc;

addpath('../../');
addpath('controllers')
addpath('guards')
addpath('wrappers')
addpath('domains')
addpath('utils')
% addpath(genpath('model'))
addpath(genpath('..\..\..\Model-Generator\models\cassie'))

%% Initialize Domains

% Initialize Right Stance Domain
RightStance_Domain = Simulator.GenericMechanicalDomain();
RightStance_Domain.name = 'RightStance';
RightStance_Domain.D_funcHandle = @De_mat;
RightStance_Domain.C_funcHandle = @Ce_mat;
RightStance_Domain.G_funcHandle = @Ge_vec;
RightStance_Domain.B_funcHandle = @Be_mat;
RightStance_Domain.Jhol_funcHandle = @Jhol_RightStance;
RightStance_Domain.dJhol_funcHandle = @dJhol_RightStance;

% Initialize Left Stance Domain
LeftStance_Domain = Simulator.GenericMechanicalDomain();
LeftStance_Domain.name = 'LeftStance';
LeftStance_Domain.D_funcHandle = @De_mat;
LeftStance_Domain.C_funcHandle = @Ce_mat;
LeftStance_Domain.G_funcHandle = @Ge_vec;
LeftStance_Domain.B_funcHandle = @Be_mat;
LeftStance_Domain.Jhol_funcHandle = @Jhol_LeftStance;
LeftStance_Domain.dJhol_funcHandle = @dJhol_LeftStance;

% Guard functions
RightStance_Domain.guard_funcHandle = @leftFootContact;
LeftStance_Domain.guard_funcHandle = @rightFootContact;

% Domain Transistions 
RightStance_Domain.nextDomainTransition = Simulator.GenericMechanicalDomainTransition();
RightStance_Domain.nextDomainTransition.nextDomain = LeftStance_Domain;
LeftStance_Domain.nextDomainTransition = Simulator.GenericMechanicalDomainTransition();
LeftStance_Domain.nextDomainTransition.nextDomain = RightStance_Domain;

%% Initialize Simulator

sim = Simulator.Simulator();
sim.maxTimeInDomain = 5;
sim.nSteps = 6;
sim.Controller = HZD_Controller();
sim.currentDomain = RightStance_Domain;

%% Load optimization parameters
optimization = load('mat\x_2step_05_dx_00_dy');

HAlpha_RightStance = reshape(optimization.outputs{1}.a(1,:),6,[])';
HAlpha_LeftStance = reshape(optimization.outputs{2}.a(1,:),6,[])';

sim.Controller.currentDomain = RightStance_Domain;

sim.Controller.HAlpha_RightStance = HAlpha_RightStance;
sim.Controller.HAlpha_LeftStance = HAlpha_LeftStance;
sim.Controller.ct_RightStance = 1/optimization.outputs{1}.t(1); 
sim.Controller.ct_LeftStance = 1/optimization.outputs{2}.t(1); 
H0 = eye(10);
H0 = [zeros(10,6), zeros(10,1), H0(:,1:4), zeros(10,2), H0(:,5), zeros(10,1), H0(:,6:9), zeros(10,2), H0(:,10)];
sim.Controller.H0_RightStance = H0;
sim.Controller.H0_LeftStance = H0;

%% Run Simulator
q0 = optimization.outputs{1}.q(1,:)';
dq0 = optimization.outputs{1}.dq(1,:)';

x0 = [q0; dq0];
t0 = 0;

log = sim.Simulate(t0, x0);
logAll = Simulator.util.RecurseAllLog(log);

%% Animation
positions_function = @positions;
t_log = logAll.continuous.Dynamics.t';
q_log = logAll.continuous.Dynamics.x(1:end/2, :)';

FactorTime = 1;
updateWorldPosition = 0;
anim = RobotAnimator(t_log, q_log, positions_function, FactorTime, updateWorldPosition);
anim.Play()

%% Get played trajectory
[q_all, t_all] = anim.ReturnTrajectory();




