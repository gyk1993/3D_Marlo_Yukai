function generate_special_opt_constains()

OPT_PATH = '.\opt_func\gen\';

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

domains = {'RightStance', 'LeftStance'};

for i = 1:length(domains)

    vars = [q].';
    constraint = q(4);
    J_constraint = jacobian(constraint,vars);
    symbolicToFunction(['f_torsoPitch_', domains{i}], {vars}, {constraint}, OPT_PATH)
    symbolicToFunction(['J_torsoPitch_', domains{i}], {vars}, {J_constraint}, OPT_PATH)

    vars = [q].';
    constraint = q(5);
    J_constraint = jacobian(constraint,vars);
    symbolicToFunction(['f_torsoRoll_', domains{i}], {vars}, {constraint}, OPT_PATH)
    symbolicToFunction(['J_torsoRoll_', domains{i}], {vars}, {J_constraint}, OPT_PATH)

    vars = [q].';
    constraint = [q(7), q(12)];
    J_constraint = jacobian(constraint,vars);
    symbolicToFunction(['f_hipAngles_', domains{i}], {vars}, {constraint}, OPT_PATH)
    symbolicToFunction(['J_hipAngles_', domains{i}], {vars}, {J_constraint}, OPT_PATH)

    vars = [q].';
    constraint = [q(7) + q(12); q(8:9) - q(13:14)];
    J_constraint = jacobian(constraint,vars);
    symbolicToFunction(['f_symmetry_', domains{i}], {vars}, {constraint}, OPT_PATH)
    symbolicToFunction(['J_symmetry_', domains{i}], {vars}, {J_constraint}, OPT_PATH)

end

end
