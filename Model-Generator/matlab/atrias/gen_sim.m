%% Script to generate functions used in simulator
%
%   Author: Ross Hartley
%   Date:   12/14/2016

%% Set paths
restoredefaultpath;
model_name = 'atrias';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_sim_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

%% Model Specifications
DOF = 16;
DOA = 6;
q = sym('q',[DOF,1]);
dq = sym('dq',[DOF,1]);

%% Generate Holonomic Constraint Simulation Functions

% Four Bar Linkage Constraints
c = q([10,11,15,16]) - (q([9,8,14,13]) - q([8,9,13,14]));
J = jacobian(c, q);
dJ = jacobian(J*dq,q);
symbolicToFunction('Jhol_FourBar', {[q;dq]}, {J}, SIM_PATH)
symbolicToFunction('dJhol_FourBar', {[q;dq]}, {dJ}, SIM_PATH)

