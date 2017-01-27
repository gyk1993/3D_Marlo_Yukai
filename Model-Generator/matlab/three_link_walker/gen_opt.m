tic
% Set paths
restoredefaultpath
model_name = 'three_link_walker';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_opt_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

%% Model Specifications
DOF = 5;
DOA = 2;
M = 5;
nOutputs = 2;
nHolonomicConstraints = 2;
q = sym('q',[DOF,1]);

%% Hermite-Simpson Collocation Constraints
disp('Generating integration constraints ...')
hermite_simpson_integration_constraints(DOF, OPT_PATH, 'RightStance');
hermite_simpson_integration_constraints(DOF, OPT_PATH, 'LeftStance');

%% Parameter Consistancy
disp('Generating parameter consitancy constraints ...')
parameter_consistancy_constraints(DOF, M, nOutputs, nHolonomicConstraints, OPT_PATH, 'RightStance');
parameter_consistancy_constraints(DOF, M, nOutputs, nHolonomicConstraints, OPT_PATH, 'LeftStance');

%% Holonomic Constraints
% initialize h
h = sym('h',[nHolonomicConstraints,1]);
h_des = sym('h_des',[nHolonomicConstraints,1]);
constraint = h - h_des;
vars = [h].';
extra = [h_des].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction(['f_h0_','RightStance'], {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','RightStance'], {vars,extra}, {J_constraint}, OPT_PATH)
symbolicToFunction(['f_h0_','LeftStance'], {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','LeftStance'], {vars,extra}, {J_constraint}, OPT_PATH)

%% Holonomic Constraints
% disp('Generating holonomic constraints ...')
% 
% tmp = p_rightFoot(q).';
% holonomic_constraint_sym = tmp(1:2);
% holonomic_constraints(DOF, holonomic_constraint_sym, OPT_PATH, 'RightStance');
% 
% tmp = p_leftFoot(q).';
% holonomic_constraint_sym = tmp(1:2);
% holonomic_constraints(DOF, holonomic_constraint_sym, OPT_PATH, 'LeftStance');

%% Dynamics Constriants
% disp('Generating dynamic constraints ...')
% 
% q1 = sym('q1_',[DOF,1]);
% q2 = sym('q2_',[DOF,1]);
% 
% tmp = p_rightFoot(q1).'; h1_sym = tmp(1:2);
% tmp = p_leftFoot(q2).'; h2_sym = tmp(1:2);
% dynamics_constraints(DOF, DOA, h1_sym, h2_sym, OPT_PATH, 'RightStance');
% 
% tmp = p_leftFoot(q1).'; h1_sym = tmp(1:2);
% tmp = p_rightFoot(q2).'; h2_sym = tmp(1:2);
% dynamics_constraints(DOF, DOA, h1_sym, h2_sym, OPT_PATH, 'LeftStance');

%% Virtual Constraints
disp('Generating virtual constraints ...')

outputs_sym = [q(4); q(5)];
virtual_constraints(DOF, outputs_sym, M, OPT_PATH, 'RightStance');
virtual_constraints(DOF, outputs_sym, M, OPT_PATH, 'LeftStance');

%% Guard Constraints
% disp('Generating guard constraints ...')
% 
% tmp = p_leftFoot(q).';
% swingFootHeight = tmp(2);
% guard_constraints(DOF, swingFootHeight, OPT_PATH, 'RightStance');
% 
% tmp = p_rightFoot(q).';
% swingFootHeight = tmp(2);
% guard_constraints(DOF, swingFootHeight, OPT_PATH, 'LeftStance');

%% Physical Constraints
disp('Generating physical constraints ...')
physical_constraints(DOF, OPT_PATH, 'RightStance');
physical_constraints(DOF, OPT_PATH, 'LeftStance');

%% Costs
disp('Generating torque costs ...')

torque_costs(DOA, OPT_PATH, 'RightStance');
torque_costs(DOA, OPT_PATH, 'LeftStance');

toc
