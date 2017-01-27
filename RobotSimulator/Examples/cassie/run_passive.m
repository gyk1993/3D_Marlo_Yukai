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

% Initialize Floating Base Domain
FloatingBase_Domain = FloatingBase();
FloatingBase_Domain.D_funcHandle = @De_mat;
FloatingBase_Domain.C_funcHandle = @Ce_mat;
FloatingBase_Domain.G_funcHandle = @Ge_vec;
FloatingBase_Domain.B_funcHandle = @Be_mat;
FloatingBase_Domain.Jhol_funcHandle = @Jhol_Floating;
FloatingBase_Domain.dJhol_funcHandle = @dJhol_Floating;

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
q0 = zeros(22,1); dq0 = zeros(22,1);
q0(10) = pi/4; q0(18) = pi/8; % Hip flexion
q0(11) = -3*pi/4; q0(19) = -pi/4; % Knee Joint
q0([14,22]) = -pi/2; % Toe Joint
% q0(3) = 1; % Raise base up

% Make sure constraints are satisfied
q0([13,21]) = [deg2rad(13); deg2rad(13)] - q0([11, 19]); % 4-bar
q0([7,12,15,20]) = 0; % Fixed joints

% Place foot on ground
 [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
    kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, ...
    fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
    fixedkneetoshinright, anklejointright, toejointright, toebottomright] = positions(q0);
q0(3) = q0(3) - toebottomright(3); 

x0 = [q0; dq0];
t0 = 0;

log = sim.Simulate(t0, x0);
logAll = Simulator.util.RecurseAllLog(log);

%% Animation
positions_function = @positions;
t_log = logAll.continuous.Dynamics.t';
q_log = logAll.continuous.Dynamics.x(1:end/2, :)';

FactorTime = 1;
updateWorldPosition = 1;
anim = RobotAnimator(t_log, q_log, positions_function, FactorTime, updateWorldPosition);
anim.Play()





