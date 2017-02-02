simlog.t     = tout;
simlog.p0    = q_out(:,1:3);
simlog.dp0   = dq_out(:,1:3);
simlog.q     = q_out(:,4:end);
simlog.dq    = dq_out(:,4:end);

Blocks = find_system(bdroot,'BlockType','ToWorkspace');
for k=1:length(Blocks)
    VariableName = get_param(Blocks{k}, 'VariableName');
    simlog.(VariableName) = evalin('base', VariableName);
end

simlog.SafetyState = zeros(size(simlog.t));

