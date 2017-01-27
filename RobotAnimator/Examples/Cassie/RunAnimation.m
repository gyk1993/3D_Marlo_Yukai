load opt_45deg_turning

t_log = [];
q_log = [];

t_start = 0;
for i = 1:length(outputs)
    t_log = [t_log, linspace(t_start, outputs{i}.t(end) + t_start, length(outputs{i}.t))];
    q_log = [q_log, outputs{i}.q'];
    t_start = outputs{i}.t(end) + t_start;
end

%%

addpath(fullfile(pwd, '..\..\'));
addpath(genpath(fullfile(pwd, '..\..\..\Model-Generator\models\cassie')));
positions_function = @positions;

%%
f = figure;
anim = CassieAnimator(t_log, q_log, positions_function);
anim.Animate(true);
anim.isLooping = true;
anim.updateWorldPosition = true;
anim.endTime = 10;
anim.pov = Animator.AnimatorPointOfView.TopSouthEast;
conGUI = Animator.AnimatorControls();
conGUI.anim = anim;
