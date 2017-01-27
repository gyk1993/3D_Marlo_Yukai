%% Clear and set paths
restoredefaultpath
clear all; clc;

addpath('../../'); % Add Simulator
addpath('controllers')
addpath('guards')
addpath('mat')
addpath('utils')

%% Initialize Domains

% Initialize Right Stance Domain
RightStance_Domain = Simulator.GenericMechanicalDomain();
RightStance_Domain.name = 'RightStance';
RightStance_Domain.D_funcHandle = @model.De_mat;
RightStance_Domain.C_funcHandle = @model.Ce_mat;
RightStance_Domain.G_funcHandle = @model.Ge_vec;
RightStance_Domain.B_funcHandle = @model.Be_mat;
RightStance_Domain.Jhol_funcHandle = @model.Jhol_RightStance_mex;
RightStance_Domain.dJhol_funcHandle = @model.dJhol_RightStance_mex;

% Initialize Left Stance Domain
LeftStance_Domain = Simulator.GenericMechanicalDomain();
LeftStance_Domain.name = 'LeftStance';
LeftStance_Domain.D_funcHandle = @model.De_mat;
LeftStance_Domain.C_funcHandle = @model.Ce_mat;
LeftStance_Domain.G_funcHandle = @model.Ge_vec;
LeftStance_Domain.B_funcHandle = @model.Be_mat;
LeftStance_Domain.Jhol_funcHandle = @model.Jhol_LeftStance_mex;
LeftStance_Domain.dJhol_funcHandle = @model.dJhol_LeftStance_mex;

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
sim.nSteps = 20;
sim.currentDomain = RightStance_Domain;


%% Initialize Controller
sim.Controller = HZD_Controller();
sim.Controller.currentDomain = RightStance_Domain;

% Load optimized parameters
optimization = load('speed_0.75.mat');
HAlpha = reshape(optimization.outputs{1}.a(1,:),6,[])';
sim.Controller.HAlpha_RightStance = HAlpha;
sim.Controller.HAlpha_LeftStance = HAlpha([3:4,1:2],:);
sim.Controller.ct_RightStance = 1/optimization.outputs{1}.t(1); 
sim.Controller.ct_LeftStance = 1/optimization.outputs{1}.t(1); 
sim.Controller.H0_RightStance = [0,0,0,1,0,0,0; ...
                                 0,0,0,0,1,0,0; ...
                                 0,0,0,0,0,1,0; ...
                                 0,0,0,0,0,0,1];
sim.Controller.H0_LeftStance = [0,0,0,1,0,0,0; ...
                                 0,0,0,0,1,0,0; ...
                                 0,0,0,0,0,1,0; ...
                                 0,0,0,0,0,0,1];
                             
%% Run Simulator
q0 = optimization.outputs{1}.q(1,:)';
dq0 = optimization.outputs{1}.dq(1,:)';  

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


%% Plots









