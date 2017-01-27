%% Script to generate functions used in simulator
%
%   Author: Ross Hartley
%   Date:   12/14/2016

%% Set paths
restoredefaultpath;
model_name = 'cassie';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_sim_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

%% Model Specifications
DOF = 22;
DOA = 10;
q = sym('q',[DOF,1]);
dq = sym('dq',[DOF,1]);

%% Generate Holonomic Constraint Simulation Functions

% 4 Bar Knee
c = q([11, 19]) + q([13, 21]) - [deg2rad(13); deg2rad(13)];
J = jacobian(c, q);
dJ = jacobian(J*dq,q);
symbolicToFunction('Jhol_4barKnee', {[q;dq]}, {J}, SIM_PATH)
symbolicToFunction('dJhol_4barKnee', {[q;dq]}, {dJ}, SIM_PATH)

% Constrain fixed joints
c = q([7,12,15,20]);
J = jacobian(c, q);
dJ = jacobian(J*dq,q);
symbolicToFunction('Jhol_fixed', {[q;dq]}, {J}, SIM_PATH)
symbolicToFunction('dJhol_fixed', {[q;dq]}, {dJ}, SIM_PATH)

