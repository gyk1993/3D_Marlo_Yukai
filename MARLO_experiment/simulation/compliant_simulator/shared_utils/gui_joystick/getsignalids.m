function [scopeconfig, paramid] = getsignalids(tg, model)
    
    scopeconfig = [];
    paramid     = [];
    
%     default_scopes = struct('signals',cell(6,1),'YLimit',[-30 30],'DisplayMode','Rolling','Decimation',1);
    
    if nargin<2
        model = tg.Application;
    end
    
    paramid = getAllParamIds(tg);
    
    switch model
        case {'Rocking01','Walking01'}
            
            
            %{
            paramid.medulla_cmd         = getparamid2(tg, fReplace('MedullaCommand'), 'Value');
            paramid.torque_sat_val      = getparamid2(tg, fReplace('BasicWalkingControl_v04/Continuous/Saturation/LegHipTorqueSat'), 'Value', 'LegHipTorqueLimit');
            paramid.enable_transition   = getparamid2(tg, fReplace('enable_transition'), 'Value');
            paramid.desired_velocity    = getparamid2(tg, fReplace('desired_velocity'), 'Value');
            paramid.IMUTorsoOffsets    = getparamid2(tg, fReplace('IMUTorsoOffsets'), 'Value');
            paramid.log_event           = getparamid2(tg, fReplace('Event'), 'Value');
            paramid.TorsoCOMOffsets     = getparamid2(tg, fReplace('TorsoCOMOffsets'), 'Value');
            
            paramid.gain_kp             = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kp'), 'Value');
            paramid.gain_kd             = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kd'), 'Value');
            paramid.gain_epsilon        = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/epsilon'), 'Value');
            paramid.u_ff_hip            = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/u_ff_hip'), 'Value');
            paramid.u_ff                = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/u_ff'), 'Value');
            paramid.ff_params           = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/ff_params'), 'Value');
            paramid.kd_torso            = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kd_torso'), 'Value');
            paramid.optimal_sat_weights = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/optimal_sat_weights'), 'Value');
            paramid.use2DOFHipControl   = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/use2DOFHipControl'), 'Value');
            paramid.kp_2dof             = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kp_2dof'), 'Value');
            paramid.kd_2dof             = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kd_2dof'), 'Value');
            paramid.k_precomp           = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/k_precomp'), 'Value');
            paramid.balanceParams       = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/balanceParams'), 'Value');
            paramid.lateralParams       = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/lateralParams'), 'Value');
            paramid.w_torso_lat         = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/w_torso_lat'), 'Value');
            
            paramid.hd_posing           = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/hd_posing'), 'Value');
            paramid.qTdesired           = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/qTdesired'), 'Value');
            paramid.kpFootPlacement     = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kpFootPlacement'), 'Value');
            paramid.kdFootPlacement     = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/kdFootPlacement'), 'Value');
            paramid.tStep               = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/tStep'), 'Value');
            paramid.tStepInitial        = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/tStepInitial'), 'Value');
            paramid.swap_params         = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/swap_params'), 'Value');
            paramid.step_params         = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/step_params'), 'Value');
            paramid.tmaxupdate          = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/TMaxUpdate'), 'Value');
            paramid.RunMode             = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/RunMode'), 'Value');
            paramid.useConstantDecoupling = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/useConstantDecoupling'), 'Value');
            paramid.useOptimalSaturation  = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/useOptimalSaturation'), 'Value');
            paramid.WalkingOutputParams   = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/WalkingOutputParams'), 'Value');
            paramid.AllowDoubleSupport    = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/AllowDoubleSupport'), 'Value');
            
            paramid.lat_bias        = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/lat_bias'), 'Value');
            paramid.lat_bias2       = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/lat_bias2'), 'Value');
            paramid.TorsoBackAngle  = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/TorsoBackAngle'), 'Value');
            paramid.TorsoBackOnStep = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/TorsoBackOnStep'), 'Value');
            paramid.EnergyControlGain = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/EnergyControlGain'), 'Value');
            paramid.EnergyControlPhi0 = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/EnergyControlPhi0'), 'Value');
            
            paramid.VelocityControlTorsoGain = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/VelocityControlTorsoGain'), 'Value');
            paramid.VelocityControlTorsoV0   = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/VelocityControlTorsoV0'), 'Value');
            paramid.VelocityControlTorsoMin  = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/VelocityControlTorsoMin'), 'Value');
            paramid.VelocityControlTorsoMax  = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/VelocityControlTorsoMax'), 'Value');
                        
            paramid.UsePosingControl          = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/UsePosingControl'), 'Value');
            paramid.TPosing                   = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/TPosing'), 'Value');
            paramid.TransitionOutputParams = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/TransitionOutputParams'), 'Value');
            
            paramid.UseKASaturation     = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/UseKASaturation'), 'Value');
            paramid.KASaturationS1      = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/KASaturationS1'), 'Value');
            paramid.KASaturationS2      = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/KASaturationS2'), 'Value');
            paramid.KASaturationEarly   = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/KASaturationEarly'), 'Value');
            paramid.KASaturationMax     = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/KASaturationMax'), 'Value');
            
            paramid.h_alpha_nom         = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/h_alpha_nom'), 'Value');
            paramid.theta_limits_nom    = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/theta_limits_nom'), 'Value');
            paramid.VBLAOptions         = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/VBLAOptions'), 'Value');
            paramid.transitionParams    = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/transitionParams'), 'Value');
            paramid.outputParams        = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/outputParams'), 'Value');
            paramid.h_alpha_transition  = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/h_alpha_transition'), 'Value');
            
            paramid.reset               = getparamid2(tg, fReplace('BasicWalkingControl_v04/Discrete/Reset'), 'Value');
            paramid.manual_swap         = getparamid2(tg, fReplace('BasicWalkingControl_v04/Discrete/ManualSwap'), 'Value');
            paramid.CommandSerialize    = getparamid2(tg, fReplace('BasicWalkingControl_v04/Discrete/CommandSerialize'), 'Value');
            
            paramid.use_imu              = getparamid2(tg, fReplace('DAQ_WITH_SAFETY/DAQ/use_imu'), 'Value');
            paramid.imu_up_compensation  = getparamid2(tg, fReplace('IMUCommand'), 'Value');
            
            paramid.StanceLegInit      = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/StanceLegInit'),'Value');
            paramid.ControllerModeInit = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/ControllerModeInit'), 'Value');
            
            paramid.useParameterizedH0 = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/useParameterizedH0'), 'Value');
  
            paramid.linkFeedback = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/linkFeedback'), 'Value');
            paramid.RIO          = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/RIO'), 'Value');
            
            paramid.ResetYaw  = getparamid2(tg,fReplace('DAQ_WITH_SAFETY/DAQ/ResetYaw'), 'Value');
            paramid.TareFT    = getparamid2(tg,fReplace('DAQ_WITH_SAFETY/DAQ/TareFT'), 'Value');
            
            paramid.ErrorZeroFactor = getparamid2(tg, fReplace('BasicWalkingControl_v04/ControlParameters/ErrorZeroFactor'), 'Value');
            %}
    end
    assignin('base','pid',paramid);
end

function id = getparamid2(tg, BlockName, ParamName, VarName)
    % This is a workaround for a new "feature" added in Simulink Real-Time
    % (R2014a). Before this release, all model parameters were indexed
    % according to the Block Name and Parameter Name, as expected. In
    % R2014a, however, if a model parameter refers to a workspace variable
    % (for example, if you have a constant block whose value is the name of
    % a workspace variable), the workspace variable is made a top level
    % model parameter; thus for these variables,
    %    BlockName = ''
    %    ParamName = <NameOfWorkspaceVariable>.
    %
    % Maddeningly, I could not find this documented anywhere. The MathWorks
    % just sprung this change on us without warning. I suppose this has
    % some advantages, since you could use the same variable in multiple
    % places and change them all at once. It also reduces the total number
    % of model parameters in this case, probably making the code generation
    % more efficient. But for backwards compatibility, it is a pain. Since
    % some of our parameters are set by workspace variables and some are
    % not, this function will first try the old naming scheme. If that
    % fails, it will try to look up the parameter using the new scheme. If
    % VarName is specified, it will look for a parameter with that name.
    % Otherwise, it will try to guess the parameter name from the block
    % name. The guess is simply the unqualified block name. (If the
    % qualified name is something like
    % 'BasicWalkingControl_v04/ControlParameters/TorsoBackOnStep' then the
    % unqualified or unmangled name is 'TorsoBackOnStep'.)
    
    id = getparamid(tg, BlockName, ParamName);
    if isempty(id)
        if nargin<4 || isempty(VarName)
            VarName = regexp(BlockName,'[^/]+$','match','once');
        end
        id = getparamid(tg, '', VarName);
    end
end
