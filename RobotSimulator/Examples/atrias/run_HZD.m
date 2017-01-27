%% Clear and set paths
restoredefaultpath
clear all; clc;

addpath('../../');
addpath('controllers')
addpath('guards')
addpath('wrappers')
addpath('utils')
% addpath(genpath('model'))
addpath(genpath('..\..\..\Model-Generator\models\atrias'))
addpath(genpath('..\..\..\RobotAnimator'))

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
sim.nSteps = 20;
sim.Controller = HZD_Controller();
sim.currentDomain = RightStance_Domain;

%% Load optimization parameters
optimization = load('mat\walkingForwards_v1');
N = length(optimization.outputs{1}.t);
M = 5;

% Construct Desired q trajectory
HAlpha_q_RightStance = bezfit(linspace(0,1,N), optimization.outputs{1}.q', M);
HAlpha_q_LeftStance =  bezfit(linspace(0,1,N), optimization.outputs{2}.q', M);

% Construct Desired dq trajectory
HAlpha_dq_RightStance = bezfit(linspace(0,1,N), optimization.outputs{1}.dq', M);
HAlpha_dq_LeftStance =  bezfit(linspace(0,1,N), optimization.outputs{2}.dq', M);

% Store into controller
sim.Controller.HAlpha_q_RightStance = HAlpha_q_RightStance;
sim.Controller.HAlpha_q_LeftStance = HAlpha_q_LeftStance;
sim.Controller.HAlpha_dq_RightStance = HAlpha_dq_RightStance;
sim.Controller.HAlpha_dq_LeftStance = HAlpha_dq_LeftStance;
sim.Controller.ct_RightStance = 1/optimization.outputs{1}.t(1); 
sim.Controller.ct_LeftStance = 1/optimization.outputs{2}.t(1); 

DOF = 16;
q_sym = sym('q', [DOF,1]);

% Pitch, SwingLeg, StanceKnee, SwingKnee, Roll, SwingHip
outputs_Right = [q_sym(4); mean(q_sym(13:14));   q_sym(9)-q_sym(8); q_sym(14)-q_sym(13); q_sym(5); q_sym(12)];
outputs_Left  = [q_sym(4);   mean(q_sym(8:9)); q_sym(14)-q_sym(13);   q_sym(9)-q_sym(8); q_sym(5);  q_sym(7)];

H0_Right = eval(jacobian(outputs_Right, q_sym));
H0_Left = eval(jacobian(outputs_Left, q_sym));

sim.Controller.H0_RightStance = H0_Right;
sim.Controller.H0_LeftStance = H0_Left;

sim.Controller.currentDomain = RightStance_Domain;

%% Run Simulator
q0 = optimization.outputs{1}.q(1,:)';
dq0 = optimization.outputs{1}.dq(1,:)';

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
anim.endTime = 20;
anim.pov = Animator.AnimatorPointOfView.TopSouthEast;
conGUI = Animator.AnimatorControls();
conGUI.anim = anim;





