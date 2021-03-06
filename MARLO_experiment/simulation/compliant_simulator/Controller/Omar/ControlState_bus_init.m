%% Script to initialize the ControlState bus

ControlState.Ts = Ts;
ControlState.T0 = 0;
ControlState.stepNumber = 1;
ControlState.s = 0;
ControlState.s_unsat = 0;
ControlState.ds = 0;
ControlState.s_R = 0;
ControlState.s_L = 0;
ControlState.Domain = 0;
ControlState.HAlphaErrorFix = zeros(6, 6);
ControlState.HAlphaSpeedReg = zeros(6, 6);
ControlState.velocity_current = [0;0;0];
ControlState.velocity_average = [0;0;0];

ControlState.Options.Enable_dx_tgt = 1;
ControlState.Options.Enable_dy_tgt = 1;
ControlState.Options.EnableSideStep = 0;
ControlState.Options.EnableKicking = 0;

ControlState.Commands.EnableTransition = isSim; % Enable for simulation
ControlState.Commands.ResetStateEstimator = 0; % Enable for simulation
ControlState.Commands.Shutdown = 0;
ControlState.Commands.ActivateSideStepLeft = 0;
ControlState.Commands.ActivateKickingLeft = 0;
ControlState.Commands.dy_tgt = 0;
ControlState.Commands.dx_tgt = 0;
ControlState.Commands.TimeScale = 0;
ControlState.Commands.PauseTime = false;
ControlState.Commands.IntegralControl = false;

if isSim
    ControlState.Offsets.xOffset = 0;
    ControlState.Offsets.yOffset = 0.0175;
else
    ControlState.Offsets.xOffset = 0;
    ControlState.Offsets.yOffset = 0;
end

createBusObject(ControlState, 'ControlState_bus');