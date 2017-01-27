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
addpath(genpath('..\..\..\Model-Generator\models\atrias'))
addpath(genpath('..\..\..\RobotAnimator'))

%% Initialize Domains

% Initialize Right Stance Domain
RightStance_Domain = Simulator.GenericMechanicalDomain();
RightStance_Domain.D_funcHandle = @De_mat;
RightStance_Domain.C_funcHandle = @Ce_mat;
RightStance_Domain.G_funcHandle = @Ge_vec;
RightStance_Domain.B_funcHandle = @Be_mat;
RightStance_Domain.Jhol_funcHandle = @Jhol_RightStance;
RightStance_Domain.dJhol_funcHandle = @dJhol_RightStance;

% Initialize Left Stance Domain
LeftStance_Domain = Simulator.GenericMechanicalDomain();
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
sim.nSteps = 1;
sim.Controller = Passive_Controller();
sim.currentDomain = RightStance_Domain;

%% Run Simulator
q0 = zeros(16,1);
q0(3) = 1; 

q0(8) = pi - pi/6; q0(9) = pi + pi/6; 
q0(10) = q0(9) - q0(8); q0(11) = q0(8) - q0(9);

q0(13) = pi - pi/3; q0(14) = pi + pi/3; 
q0(15) = q0(14) - q0(13); q0(16) = q0(13) - q0(14);

p_stanceFoot = p_RightFoot(q0);
q0(3) = q0(3) - p_stanceFoot(3);

dq0 = zeros(16,1);

x0 = [q0; dq0];
t0 = 0;

log = sim.Simulate(t0, x0);
logAll = Simulator.util.RecurseAllLog(log);
t_log = logAll.continuous.Dynamics.t;
q_log = logAll.continuous.Dynamics.x(1:end/2,:);

%% Animation
f = figure;
anim = AtriasAnimator(t_log, q_log);
anim.Animate(true);
anim.isLooping = false;
anim.updateWorldPosition = false;
anim.endTime = 10;
anim.pov = Animator.AnimatorPointOfView.TopSouthEast;
conGUI = Animator.AnimatorControls();
conGUI.anim = anim;



