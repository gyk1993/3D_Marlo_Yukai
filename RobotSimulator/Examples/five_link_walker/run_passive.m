%% Clear and set paths
restoredefaultpath
clear all; clc;

addpath('../../');
addpath(genpath('../../../Model-Generator/models/five_link_walker'));
addpath('controllers')
addpath('guards')

%% Initialize Domains

% Initialize Right Stance Domain
RightStance_Domain = Simulator.GenericMechanicalDomain();
RightStance_Domain.D_funcHandle = @De_mat;
RightStance_Domain.C_funcHandle = @Ce_mat;
RightStance_Domain.G_funcHandle = @Ge_vec;
RightStance_Domain.B_funcHandle = @Be_mat;
RightStance_Domain.Jhol_funcHandle = @Jhol_RightStance_mex;
RightStance_Domain.dJhol_funcHandle = @dJhol_RightStance_mex;

% Initialize Left Stance Domain
LeftStance_Domain = Simulator.GenericMechanicalDomain();
LeftStance_Domain.D_funcHandle = @De_mat;
LeftStance_Domain.C_funcHandle = @Ce_mat;
LeftStance_Domain.G_funcHandle = @Ge_vec;
LeftStance_Domain.B_funcHandle = @Be_mat;
LeftStance_Domain.Jhol_funcHandle = @Jhol_LeftStance_mex;
LeftStance_Domain.dJhol_funcHandle = @dJhol_LeftStance_mex;

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
sim.maxTimeInDomain = 20;
sim.nSteps = 2;
sim.Controller = Passive_Controller();
sim.currentDomain = RightStance_Domain;

%% Run Simulator
q0 = [0;1;deg2rad(10); pi-deg2rad(10); 0 ;pi/3; 0]; dq0 = zeros(7,1);
[ pH, pT, pRK, pR, pLK, pL ] = positions(q0);
q0(2) = q0(2) - pR(2); % make sure right foot is on the ground

x0 = [q0; dq0];
t0 = 0;

log = sim.Simulate(t0, x0);
logAll = Simulator.util.RecurseAllLog(log);

%% Animation
positions_function = @model.positions;
t_log = logAll.continuous.Dynamics.t';
q_log = logAll.continuous.Dynamics.x(1:end/2, :)';

FactorTime = 1;
anim = model.RobotAnimator(t_log, q_log, positions_function, FactorTime);
anim.Play()












