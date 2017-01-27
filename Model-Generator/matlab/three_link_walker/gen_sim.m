%% Script to generate functions used in simulator
%
%   Author: Ross Hartley
%   Date:   12/14/2016

%% Set paths
restoredefaultpath;
model_name = 'three_link_walker';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_sim_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

%% Model Specifications
DOF = 5;
DOA = 2;
M = 5;
nOutputs = 2;
nHolonomicConstraints = 2;
q = sym('q',[DOF,1]);
dq = sym('dq',[DOF,1]);

%% Generate Holonomic Constraint Simulation Functions

% Right Stance
tmp = p_rightFoot(q).';
c = tmp(1:2);
J = jacobian(c, q);
dJ = jacobian(J*dq,q)*dq;
symbolicToFunction('Jhol_RightStance', {[q;dq]}, {J}, SIM_PATH)
symbolicToFunction('dJhol_RightStance', {[q;dq]}, {dJ}, SIM_PATH)

% Left Stance
tmp = p_leftFoot(q).';
c = tmp(1:2);
J = jacobian(c, q);
dJ = jacobian(J*dq,q)*dq;
symbolicToFunction('Jhol_LeftStance', {[q;dq]}, {J}, SIM_PATH)
symbolicToFunction('dJhol_LeftStance', {[q;dq]}, {dJ}, SIM_PATH)
