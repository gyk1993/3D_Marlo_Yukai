%% Initialization Scripts
clear; clc; restoredefaultpath;
% Set all of the necessary paths
setpath;

% Simulation flag
isSim = 1;

% Initialize the controller parameters
Controller_init

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

% Load Initial Condition
if isSim
    MAT_PATH = 'D:\Graduate\robots\GitHub\3D_Marlo_Yukai\RobotOptimization\Examples\atrias\mat\';
    optimization = load([MAT_PATH,'walkingInPlace_v1']);

    q0_new = optimization.outputs{1}.q(1,:)';
    dq0_new = optimization.outputs{1}.dq(1,:)';
    
    % Change to old coordinates
    q0 = zeros(13,1);
    q0(1:3,:) = q0_new([5,4,6],:);
    q0(4:13,:) = q0_new([8,9,13,14,8,9,7,13,14,12],:);
    q0(13,:) = -q0(13,:);

    dq0 = zeros(13,1);
    dq0(1:3,:) = dq0_new([5,4,6],:);
    dq0(4:13,:) = dq0_new([8,9,13,14,8,9,7,13,14,12],:);
    dq0(13,:) = -dq0(13,:);

    q = [q0_new(1:3); q0];
    dq = [dq0_new(1:3); dq0];

    xinit = [q; dq];
end


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
anim = AtriasAnimator(log.t, [TorsoPosition(:, 1:3), log.Data.q(:, [1:6, 9:13, 16:17])]');
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
log = DataVec2Struct(log, Data, datalogfilename, 1);
log = DAQVec2Struct(log, DAQ, datalogfilename, 1);
log = StateEstimatorVec2Struct(log, StateEstimator, datalogfilename, 1);

%% Open GUI
tg = xpc
mdl = 'Controller_Exp';
hgui = control_gui(@getsignalids,mdl);
handles = guidata(hgui);
set(hgui,'Position',[300 1 350 72.0000])
tg.set('CommunicationTimeOut',20)

%% Open model
open(mdl)
getCompiledPortWidths(mdl);

%% Connect to target
tg = connectToTarget();
id = getAllParamIds(tg)

%% Compiling Port Widths 
getCompiledPortWidths(mdl);
log = parseModelData(log);
save(datalogfilename,'log','status')

%% Setting/Getting parameters
setparam(tg, id.param, param);  
getparam(tg, id.param)





