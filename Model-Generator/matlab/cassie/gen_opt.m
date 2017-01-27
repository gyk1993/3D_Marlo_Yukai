tic
% Set paths
restoredefaultpath
model_name = 'cassie';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'matlab');
addpath('gen_opt_functions')
addpath(genpath([MODEL_PATH,'/gen/mathematica']))

% Model Specifications
DOF = 22;
DOA = 10;
M = 5;
nOutputs = 10;
nHolonomicConstraints = 12;
actuatedIndices = [8,9,10,11,14,16,17,18,19,22];
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

% Constrain fixed joints
c1 = q([7,12,15,20]);
h1 = sym('h',[length(c1),1]);
Fe1 = sym('Fe',[length(c1),1]);
Fimp1 = sym('Fimp',[length(c1),1]);
J1 = jacobian(c1, q);
dJ1 = jacobian(J1*dq,q);

constraint = c1-h1;
vars = [q;h1].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrPosition_fixed', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrPosition_fixed', {vars}, {J_constraint}, OPT_PATH)

constraint = J1*dq;
vars = [q;dq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrVelocity_fixed', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrVelocity_fixed', {vars}, {J_constraint}, OPT_PATH)

constraint = J1*ddq + dJ1*dq;
vars = [q;dq;ddq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrAcceleration_fixed', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrAcceleration_fixed', {vars}, {J_constraint}, OPT_PATH)

constraint = J1'*Fe1;
vars = [q;Fe1].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrExternalForce_fixed', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrExternalForce_fixed', {vars}, {J_constraint}, OPT_PATH)

constraint = J1'*Fimp1;
vars = [q;Fimp1].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrImpactForce_fixed', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrImpactForce_fixed', {vars}, {J_constraint}, OPT_PATH)


% 4 Bar Knee
c2 = q([11, 19]) + q([13, 21]) - [deg2rad(13); deg2rad(13)];
h2 = sym('h',[length(c2),1]);
Fe2 = sym('Fe',[length(c2),1]);
Fimp2 = sym('Fimp',[length(c2),1]);
J2 = jacobian(c2, q);
dJ2 = jacobian(J2*dq,q);

constraint = c2 - h2;
vars = [q;h2].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrPosition_fourbar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrPosition_fourbar', {vars}, {J_constraint}, OPT_PATH)

constraint = J2*dq;
vars = [q;dq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrVelocity_fourbar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrVelocity_fourbar', {vars}, {J_constraint}, OPT_PATH)

constraint = J2*ddq + dJ2*dq;
vars = [q;dq;ddq].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrAcceleration_fourbar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrAcceleration_fourbar', {vars}, {J_constraint}, OPT_PATH)

constraint = J2'*Fe2;
vars = [q;Fe2].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrExternalForce_fourbar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrExternalForce_fourbar', {vars}, {J_constraint}, OPT_PATH)

constraint = J2'*Fimp2;
vars = [q;Fimp2].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_holConstrImpactForce_fourbar', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_holConstrImpactForce_fourbar', {vars}, {J_constraint}, OPT_PATH)


% Initialization
h = sym('h',[nHolonomicConstraints,1]);
h_des = sym('h_des',[nHolonomicConstraints,1]);
constraint = h - h_des; constraint(10) = 0;
vars = h.';
extra = h_des.';
J_constraint = jacobian(constraint,vars);
symbolicToFunction(['f_h0_','RightStance'], {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','RightStance'], {vars,extra}, {J_constraint}, OPT_PATH)
symbolicToFunction(['f_h0_','LeftStance'], {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction(['J_h0_','LeftStance'], {vars,extra}, {J_constraint}, OPT_PATH)

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
outputs_sym = q(actuatedIndices);
virtual_constraints(DOF, outputs_sym, M, OPT_PATH, 'LeftStance');

%% Physical Constraints
disp('Generating physical constraints ...')
physical_constraints(DOF, OPT_PATH, 'RightStance');
physical_constraints(DOF, OPT_PATH, 'LeftStance');

%% Costs
disp('Generating torque costs ...')
torque_costs(DOA, OPT_PATH, 'RightStance');
torque_costs(DOA, OPT_PATH, 'LeftStance');

additional_costs(OPT_PATH, 'RightStance');
additional_costs(OPT_PATH, 'LeftStance');

%% Symmetry constraints

% Bezier parameter Consistancy Constraint
a1 = sym('a1_',[nOutputs,(M+1)]);
a2 = sym('a2_',[nOutputs,(M+1)]);
a2_tmp = a2;
a2_tmp([1,2,6,7],:) = -a2_tmp([1,2,6,7],:);
a2_tmp = [a2_tmp(end/2+1:end,:); a2_tmp(1:end/2,:)];
constraint_matrix = a2_tmp - a1;
constraint_matrix(6:end,:) = [];
constraint = reshape(constraint_matrix,[],1);
vars = [reshape(a1.',[],1); reshape(a2.',[],1)].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_aSymmetry_RightStance', {vars}, {constraint}, OPT_PATH)
symbolicToFunction('J_aSymmetry_RightStance', {vars}, {J_constraint}, OPT_PATH)

%% Constrain to externally provided state
selected = sym('s',[2*DOF,1]);
constraint = selected.*(x1-x2);
vars = [x1].';
extra = [selected; x2].';
J_constraint = jacobian(constraint,vars);
symbolicToFunction('f_xConstrainExternal_RightStance', {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction('J_xConstrainExternal_RightStance', {vars,extra}, {J_constraint}, OPT_PATH)
symbolicToFunction('f_xConstrainExternal_LeftStance', {vars,extra}, {constraint}, OPT_PATH)
symbolicToFunction('J_xConstrainExternal_LeftStance', {vars,extra}, {J_constraint}, OPT_PATH)


weight = sym('w',[2*DOF,1]);
cost = sum(weight.*(x1-x2).^2);
vars = [x1].';
extra = [weight; x2].';
J_cost = jacobian(cost,vars);
symbolicToFunction('f_xCostExternal_RightStance', {vars,extra}, {cost}, OPT_PATH)
symbolicToFunction('J_xCostExternal_RightStance', {vars,extra}, {J_cost}, OPT_PATH)
symbolicToFunction('f_xCostExternal_LeftStance', {vars,extra}, {cost}, OPT_PATH)
symbolicToFunction('J_xCostExternal_LeftStance', {vars,extra}, {J_cost}, OPT_PATH)


toc

