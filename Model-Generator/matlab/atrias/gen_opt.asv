tic
% Set paths
restoredefaultpath
model_name = 'atrias';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_opt_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

% Model Specifications
DOF = 16;
DOA = 6;
M = 5;
nOutputs = 6;
nHolonomicConstraints = 7;
actuatedIndices = [7,8,9,12,13,14];
q = sym('q',[DOF,1]);
dq = sym('dq',[DOF,1]);
ddq = sym('ddq',[DOF,1]);
x = [q;dq];

q1 = sym('q1_',[DOF,1]);
q2 = sym('q2_',[DOF,1]);
dq1 = sym('dq1_',[DOF,1]);
dq2 = sym('dq2_',[DOF,1]);
x1 = [q1;dq1];
x2 = [q2;dq2];

%% Holonomic constraint symbolic

% Four Bar Knee
c = q([10,11,15,16]) - (q([9,8,14,13]) - q([8,9,13,14]));
h = sym('h',[length(c),1]);
Fe = sym('Fe',[length(c),1]);
Fimp = sym('Fimp',[length(c),1]);
J = jacobian(c, q);
dJ = jacobian(J*dq,q);

constraint = c - h;
vars = [q;h].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrPosition_fourBar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrPosition_fourBar', {vars}, {J_constraint}, OPT_PATH)

constraint = J*dq;
vars = [q;dq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrVelocity_fourBar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrVelocity_fourBar', {vars}, {J_constraint}, OPT_PATH)

constraint = J*ddq + dJ*dq;
vars = [q;dq;ddq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrAcceleration_fourBar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrAcceleration_fourBar', {vars}, {J_constraint}, OPT_PATH)

constraint = J'*Fe;
vars = [q;Fe].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrExternalForce_fourBar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrExternalForce_fourBar', {vars}, {J_constraint}, OPT_PATH)

constraint = J'*Fimp;
vars = [q;Fimp].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrImpactForce_fourBar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrImpactForce_fourBar', {vars}, {J_constraint}, OPT_PATH)

% Initialization
h = sym('h',[nHolonomicConstraints,1]);
constraint = h;
vars = [h].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction(['f_h0_','RightStance'], {vars}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','RightStance'], {vars}, {J_constraint}, OPT_PATH)
symbolicToFunction(['f_h0_','LeftStance'], {vars}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','LeftStance'], {vars}, {J_constraint}, OPT_PATH)


%% Integration Constraints
disp('Generating integration constraints ...')
integration_constraints(DOF, OPT_PATH, 'RightStance');
integration_constraints(DOF, OPT_PATH, 'LeftStance');

%% Parameter Consistancy
disp('Generating parameter consitancy constraints ...')
parameter_consistancy_constraints(DOF, M, nOutputs, nHolonomicConstraints, OPT_PATH, 'RightStance');
parameter_consistancy_constraints(DOF, M, nOutputs, nHolonomicConstraints, OPT_PATH, 'LeftStance');

%% Virtual Constraints
disp('Generating virtual constraints ...')
outputs_sym = q(actuatedIndices);
virtual_constraints(DOF, outputs_sym, M, OPT_PATH, 'RightStance');
virtual_constraints(DOF, outputs_sym, M, OPT_PATH, 'LeftStance');

%% Physical Constraints
disp('Generating physical constraints ...')
physical_constraints(DOF, OPT_PATH, 'RightStance');
physical_constraints(DOF, OPT_PATH, 'LeftStance');


%% Symmetry constraint

% Bezier parameter Consistancy Constraint
a1 = sym('a1_',[nOutputs,(M+1)]);
a2 = sym('a2_',[nOutputs,(M+1)]);
a2_tmp = a2;
a2_tmp([1,4],:) = -a2_tmp([1,4],:);
a2_tmp = [a2_tmp(end/2+1:end,:); a2_tmp(1:end/2,:)];
constraint_matrix = a2_tmp - a1;
constraint = reshape(constraint_matrix,[],1);
vars = [reshape(a1.',[],1); reshape(a2.',[],1)].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_aSymmetry_RightStance', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_aSymmetry_RightStance', {vars}, {J_constraint}, OPT_PATH)


%% Costs
disp('Generating torque costs ...')
torque_costs(DOA, OPT_PATH, 'RightStance');
torque_costs(DOA, OPT_PATH, 'LeftStance');



