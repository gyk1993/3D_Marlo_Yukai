%% Initialization Scripts
clear; restoredefaultpath;
% Set all of the necessary paths
setpath;

% Simulation flag
isSim = 1;

% Load all of the model parameters
load_model_params
% Initialize xbox controller bus
xbox_bus_init
% Initialize ControlState bus
ControlState_bus_init
% Initialize ControlParams bus (Gait is loaded in here)
ControlParams_bus_init
% Initialize I/O buses (Output Data is specified here)
IO_bus_init
% Initialize DAQ Output bus
DAQ_bus_init
% Initialize the controller parameters
CompliantController.Controller_init

ControlState.s = 0;
ControlState.s_unsat = 0;

% Load Initial Condition
if isSim
    MAT_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\RobotOptimization\Examples\atrias\mat\';
    optimization = load([MAT_PATH,'walkingInPlace_v3']);

    q0_new = optimization.outputs{1}.q(1,:)';
    dq0_new = optimization.outputs{1}.dq(1,:)';
    
    % Change to old coordinates
    q0 = zeros(13,1);
    q0(1:3,:) = q0_new([6,5,4],:);
    q0(4:13,:) = q0_new([8,9,13,14,8,9,7,13,14,12],:);
    q0(13,:) = -q0(13,:);

    dq0 = zeros(13,1);
    dq0(1:3,:) = dq0_new([5,4,6],:);
    dq0(4:13,:) = dq0_new([8,9,13,14,8,9,7,13,14,12],:);
    dq0(13,:) = -dq0(13,:);

    q = [q0_new(1:3); q0];
    dq = [dq0_new(1:3); dq0];
    
%     dq=zeros(16,1);
    q(3)=1.1;
    q(4)=pi/2;
    xinit = [q; dq];
end

% if isSim
%     mdl = 'Controller_Sim';
%     load_system(mdl);
%     cs = getActiveConfigSet(mdl);
%     mdl_cs = cs.copy;
%     set_param(mdl_cs,'StopTime','20');
%     log_obj = sim(mdl, mdl_cs);
%     
%     log = struct();
%     log_params = log_obj.get();
%     for i = 1:length(log_params)
%         log.(char(log_params(i))) = log_obj.get(char(log_params(i)));
%     end
%     
%     log.DataVec = reshape(log.DataVec,size(log.DataVec,1),[])';
%     log = DataVec2Struct(log, Data);
% 
%     log = rmfield(log, {'DataVec'});
%     
%     beep;
% else
%     mdl = 'Controller_Exp';
%     open(mdl);
% end

ax = [];


%% Plot
close all;

ax = [];

f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.u'); title('u (saturated)');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.Data.u'); title('u (unsaturated)');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, rad2deg(log.Data.y)'); title('y');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, rad2deg(log.Data.dy)'); title('dy');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, rad2deg(log.Data.ya)'); title('ya');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, rad2deg(log.Data.yd)'); title('yd');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, rad2deg(log.Data.q(:,[4,11]))'); title('q hips');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, TorsoPosition(:, 3)');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.Data.vel');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.Data.s);
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.Data.s_unsat');
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, log.Data.Domain');
springDeflections = log.Data.q(:, [7:8, 14:15]) - log.Data.q(:, [5:6, 12:13]);
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, springDeflections');
figure; ax = [ax, subplot(3, 1, 1)]; hold on; plot(log.t, log.Data.InSingleSupport); ax = [ax, subplot(3, 1, 2)]; hold on; plot(log.t, log.Data.InDoubleSupport); ax = [ax, subplot(3, 1, 3)]; hold on; plot(log.t, log.Data.StanceLeg);
torsoAngle = log.Data.q(:, 1); rightLegAngle = (log.Data.q(:, 5) + log.Data.q(:, 6)) ./ 2; leftLegAngle = (log.Data.q(:, 12) + log.Data.q(:, 13)) ./ 2;
figure; ax = [ax, subplot(3, 1, 1)]; hold on; plot(log.t, torsoAngle); ax = [ax, subplot(3, 1, 2)]; hold on; plot(log.t, rightLegAngle); ax = [ax, subplot(3, 1, 3)]; hold on; plot(log.t, leftLegAngle);
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, [log.Data.fz_R, log.Data.fz_L]);
f = figure; ax = [ax, axes(f)]; hold on; plot(log.t, [log.Data.s_R, log.Data.s_L]);
% Velocities
figure; ax = [ax, subplot(1, 2, 1)]; hold on; plot(log.t, [log.Data.velFiltered(:,1), log.Data.velMeasured(:,1)]);
    ax = [ax, subplot(1, 2, 2)];  hold on; plot(log.t, [log.Data.velFiltered(:,2), log.Data.velMeasured(:,2)]);
% Foot Placements
figure; ax = [ax, subplot(1, 2, 1)]; hold on; plot(log.t, rad2deg(log.Data.swingHipAdjustment));
    ax = [ax, subplot(1, 2, 2)];  hold on; plot(log.t, rad2deg(log.Data.swingLegAdjustment));

linkaxes(ax, 'x');

%% Animate Step
% MODEL_PATH = 'C:\Users\oharib\Documents\GitHub\Model-Generator\models\atrias\gen\';
% ANIM_PATH = 'C:\Users\oharib\Documents\GitHub\RobotAnimator\';
% addpath(genpath(MODEL_PATH));
% addpath(ANIM_PATH);
% 
% f = figure;
% anim = AtriasAnimator(log.t, [log.q(:, 1:3), log.Data.q(:, [1:6, 9:13, 16:17])]');
% anim.isLooping = true;
% anim.updateWorldPosition = true;
% % anim.speed = 0.2;
% anim.pov = Animator.AnimatorPointOfView.TopSouthEast;
% anim.Animate(true);
% conGUI = Animator.AnimatorControls();
% conGUI.anim = anim;
%% Animate Simulation
% steps.t = t_out;
% steps.q = q_out;
% steps.u = reshape(u,6,[])';
% steps.vcm_average = log.Data.vel_step_average_last; 
% anim = RobotAnimator(steps,0.8,leg_length,torso_com_offset, terrain);
% anim.Play

MODEL_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\Model-Generator\models\atrias\gen\';
ANIM_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\RobotAnimator\';
addpath(genpath(MODEL_PATH));
addpath(ANIM_PATH);

f = figure;
anim = AtriasAnimator(log.t, [log.q(:, 1:3), log.Data.q(:, [1:6, 9:13, 16:17])]');
anim.Animate(true);
anim.isLooping = false;
anim.updateWorldPosition = true;
anim.pov = Animator.AnimatorPointOfView.North;
conGUI = Animator.AnimatorControls();
conGUI.anim = anim;

%% Simulation Logging
log.t = t_out;
log.q = q_out;
log.dq = dq_out;
log.DataVec = reshape(DataVec,size(DataVec,1),[])';
log.StateEstimatorVec = reshape(StateEstimatorVec,size(StateEstimatorVec,1),[])';
log = DataVec2Struct(log, Data);
log = StateEstimatorVec2Struct(log, StateEstimator);

%% Experiment Logging
% Run after logging (everytime)
% This converts DataVec -> Data
%datalogfilename = 'C:\Users\oharib\Dropbox (DynamicLegLocomotion)\TeamWide\Logs\Walking\2017-02-14\NoVideo02\NoVideo02.mat';
log = DataVec2Struct(log, Data, datalogfilename, 1);
log = DAQVec2Struct(log, DAQ, datalogfilename, 1);
beep;

%% Open GUI
tg = xpc
mdl = 'Controller_Exp';
hgui = control_gui(@getsignalids,mdl);
handles = guidata(hgui);
set(hgui,'Position',[30 -20 320 72])
tg.set('CommunicationTimeOut',20)

%% Open model
% run after changing the outputs in the model
open(mdl)
getCompiledPortWidths(mdl);

%% Connect to target
tg = connectToTarget();
id = getAllParamIds(tg)

%% Compiling Port Widths 
% run if you forget to compile after changing outputs in the model
getCompiledPortWidths(mdl);
log = parseModelData(log);
save(datalogfilename,'log','status')

%% Whats wrong
whatsWrong_v2(log);

%% Setting/Getting parameters
setparam(tg, id.commanded_u, [0,0,-0.8,0,0,-0.8]);
setparam(tg, id.regulate_velocity_ctrl, 1);

setparam(tg, id.deltaSwKA_ctrl, [0,0,deg2rad(10),deg2rad(10),deg2rad(-10),deg2rad(-10)]);
setparam(tg, id.deltaSwKA_ctrl, deg2rad(5).*ones(1,6));
setparam(tg, id.deltaStKA_ctrl, deg2rad(5).*ones(1,6));

setparam(tg, id.c_Kp_hip, 40);

setparam(tg, id.zero_error_ctrl, 1);

setparam(tg, id.GearOffsets, [0.4799,-0.3409,0.3498,-0.2576] + [-10,-2.5,-14,19]./100);

%%
getparam(tg, id.LegHipTorqueLimit)
getparam(tg, id.c_Kp_hip)
getparam(tg, id.GearOffsets)
getparam(tg, id.s_hold_ctrl)
getparam(tg, id.joint_test_freq_ctrl)
getparam(tg, id.joint_test_link_num_ctrl)
getparam(tg, id.joint_test_amp_ctrl)





