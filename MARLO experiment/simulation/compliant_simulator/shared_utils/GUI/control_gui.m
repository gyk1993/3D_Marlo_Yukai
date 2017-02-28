function varargout = control_gui(varargin)
    % CONTROL_GUI MATLAB code for control_gui.fig
    %      CONTROL_GUI, by itself, creates a new CONTROL_GUI or raises the existing
    %      singleton*.
    %
    %      H = CONTROL_GUI returns the handle to a new CONTROL_GUI or the handle to
    %      the existing singleton*.
    %
    %      CONTROL_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
    %      function named CALLBACK in CONTROL_GUI.M with the given input arguments.
    %
    %      CONTROL_GUI('Property','Value',...) creates a new CONTROL_GUI or raises the
    %      existing singleton*.  Starting from the left, property value pairs are
    %      applied to the GUI before control_gui_OpeningFcn gets called.  An
    %      unrecognized property name or invalid value makes property application
    %      stop.  All inputs are passed to control_gui_OpeningFcn via varargin.
    %
    %      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
    %      instance to run (singleton)".
    %
    % See also: GUIDE, GUIDATA, GUIHANDLES
    
    % Edit the above text to modify the response to help control_gui
    
    % Last Modified by GUIDE v2.5 26-Mar-2013 21:57:14
    
    % Begin initialization code - DO NOT EDIT
    gui_Singleton = 1;
    gui_State = struct('gui_Name',       mfilename, ...
        'gui_Singleton',  gui_Singleton, ...
        'gui_OpeningFcn', @control_gui_OpeningFcn, ...
        'gui_OutputFcn',  @control_gui_OutputFcn, ...
        'gui_LayoutFcn',  [] , ...
        'gui_Callback',   []);
    if nargin && ischar(varargin{1})
        gui_State.gui_Callback = str2func(varargin{1});
    end
    
    if nargout
        [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
    else
        gui_mainfcn(gui_State, varargin{:});
    end
    % End initialization code - DO NOT EDIT
    
    
    % --- Executes just before control_gui is made visible.
function control_gui_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to control_gui (see VARARGIN)
    
    % Choose default command line output for control_gui
    handles.output = hObject;
    
    % Options
    handles.options.verbosity = 'v';
    
    % Get a handle to a function which can get signal and parameter ids from
    % the desired xPC Target application
    if nargin>3 && isa(varargin{1},'function_handle')
        handles.getsignalids = varargin{1};
    elseif exist('getsignalids','file')==2
        handles.getsignalids = @getsignalids;
    else
        handles.getsignalids = @(model)deal([],[]);
    end
    if nargin>4 && ischar(varargin{2})
        handles.mdlpattern = varargin{2};
    else
        handles.mdlpattern = 'BasicWalking_.*_xpc';
    end
    
    handles.cd = pwd;
    % handles.mdlpattern = 'BasicWalking_v01_xpc.mdl';
    
    d1 = dir([handles.mdlpattern '.mdl']);
    d2 = dir([handles.mdlpattern '.slx']);
    d = [d1; d2];
    dl = dir('Lib*.mdl');
    models = regexprep(setdiff({d.name}',{dl.name}.'), {'\.mdl', '\.slx'}, {'', ''});
    if isempty(models)
        models = {'Change directory to find models'};
    end
    set(handles.xpc_application, 'String', models);
    
    % Store xpc object handle
    handles.tg = xpc;
    
    % Update handles structure
    guidata(hObject, handles);
    
    % UIWAIT makes control_gui wait for user response (see UIRESUME)
    % uiwait(handles.figure1);
    
    
    % --- Outputs from this function are returned to the command line.
function varargout = control_gui_OutputFcn(hObject, eventdata, handles)
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    % Get default command line output from handles structure
    varargout{1} = handles.output;
    
    
function main_Callback(hObject, eventdata, handles)
    % hObject    handle to gain_epsilon (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    
    if ~checkstate(handles,'paramid','q')
        try
            handles = init_xpc(handles,false);
            guidata(hObject, handles);
        catch
        end
    end
    
    switch get(hObject, 'Tag')
        
        % MEDULLAS ------------------------------------------------------------
        case {'med_estop'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.MedullaCommand, 4); % 4=HALT
            setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
            
        case {'med_enable'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
            LegHipTorqueLimit = getparam(handles.tg, handles.paramid.LegHipTorqueLimit);
            set(handles.sat_leg_torque, 'String', num2str(LegHipTorqueLimit(1), '%0.0f'));
            set(handles.sat_hip_torque, 'String', num2str(LegHipTorqueLimit(2), '%0.0f'));
            
            setparamsafe(handles.tg, handles.paramid.MedullaCommand, 6); % 6=RESET
            pause(0.1);
            setparamsafe(handles.tg, handles.paramid.MedullaCommand, 2); % 2=RUN
            
            % SATURATION ----------------------------------------------------------
        case {'sat_zero_fast'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
            LegHipTorqueLimit = getparam(handles.tg, handles.paramid.LegHipTorqueLimit);
            set(handles.sat_leg_torque, 'String', num2str(LegHipTorqueLimit(1), '%0.0f'));
            set(handles.sat_hip_torque, 'String', num2str(LegHipTorqueLimit(2), '%0.0f'));
            
        case {'sat_zero_leg_torque'}
            if ~checkstate(handles,'paramid'), return, end
            LegHipTorqueLimit = getparam(handles.tg, handles.paramid.LegHipTorqueLimit);
            setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; min(1.2, LegHipTorqueLimit(2))]);
            setparamramp(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0], 0.25, handles.options.verbosity);
            LegHipTorqueLimit = getparam(handles.tg, handles.paramid.LegHipTorqueLimit);
            set(handles.sat_leg_torque, 'String', num2str(LegHipTorqueLimit(1), '%0.0f'));
            set(handles.sat_hip_torque, 'String', num2str(LegHipTorqueLimit(2), '%0.0f'));
            
        case {'sat_leg_torque', 'sat_hip_torque'}
            if ~checkstate(handles,'paramid'), return, end
            LegHipTorqueLimit = str2double(get([handles.sat_leg_torque; handles.sat_hip_torque],'String'));
            LegHipTorqueLimit = max(0, LegHipTorqueLimit);
            if (abs(LegHipTorqueLimit(2)) < 1)
                LegHipTorqueLimit(1) = 0;
            end
            [canceled,oldval] = setparamramp(handles.tg, handles.paramid.LegHipTorqueLimit, LegHipTorqueLimit, 2, handles.options.verbosity);
            if canceled
                set(handles.sat_leg_torque, 'String', num2str(oldval(1),'%0.0f'));
                set(handles.sat_hip_torque, 'String', num2str(oldval(2),'%0.0f'));
            else
                set(handles.sat_leg_torque, 'String', num2str(oldval(1),'%0.0f'));
                set(handles.sat_hip_torque, 'String', num2str(oldval(2),'%0.0f'));
            end
            
        case {'useOptimalSaturation'}
            if ~checkstate(handles,'paramid'), return, end
            useOptimalSaturation = get(handles.useOptimalSaturation,'Value');
            setparamsafe(handles.tg, handles.paramid.useOptimalSaturation, useOptimalSaturation);
            
        case {'optimal_sat_weight_stance','optimal_sat_weight_swing'}
            if ~checkstate(handles,'paramid'), return, end
            optimal_sat_weights = str2double(get([handles.optimal_sat_weight_stance; handles.optimal_sat_weight_swing],'String'));
            setparamramp(handles.tg, handles.paramid.optimal_sat_weights, optimal_sat_weights, 0.5, handles.options.verbosity);
            
        case {'UseKASaturation','KASaturationS1','KASaturationEarly'}
            if ~checkstate(handles,'paramid'), return, end
            UseKASaturation = get(handles.UseKASaturation,'Value');
            setparamsafe(handles.tg, handles.paramid.UseKASaturation, UseKASaturation);
            KASaturationS1 = str2double(get(handles.KASaturationS1,'String'));
            setparamsafe(handles.tg, handles.paramid.KASaturationS1, KASaturationS1);
            KASaturationEarly = str2double(get(handles.KASaturationEarly,'String'));
            setparamsafe(handles.tg, handles.paramid.KASaturationEarly, KASaturationEarly);
            
            
            % GAINS ---------------------------------------------------------------
        case {'gain_stance_legangle_p', 'gain_stance_legshape_p', 'gain_stance_hip_p', 'gain_swing_legangle_p', 'gain_swing_legshape_p', 'gain_swing_hip_p'}
            if ~checkstate(handles,'paramid'), return, end
            kp = str2double(get([handles.gain_stance_legangle_p; handles.gain_swing_legangle_p; handles.gain_stance_legshape_p; handles.gain_swing_legshape_p; handles.gain_stance_hip_p; handles.gain_swing_hip_p],'String'));
            setparamramp(handles.tg, handles.paramid.kp, kp, 100, handles.options.verbosity);
            
        case {'gain_stance_legangle_d', 'gain_stance_legshape_d', 'gain_stance_hip_d', 'gain_swing_legangle_d', 'gain_swing_legshape_d', 'gain_swing_hip_d'}
            if ~checkstate(handles,'paramid'), return, end
            kd = str2double(get([handles.gain_stance_legangle_d; handles.gain_swing_legangle_d; handles.gain_stance_legshape_d; handles.gain_swing_legshape_d; handles.gain_stance_hip_d; handles.gain_swing_hip_d],'String'));
            setparamramp(handles.tg, handles.paramid.kd, kd, 20, handles.options.verbosity);
            
        case {'gain_stance_epsilon', 'gain_swing_epsilon'}
            if ~checkstate(handles,'paramid'), return, end
            epsilon = str2double(get([handles.gain_stance_epsilon; handles.gain_swing_epsilon],'String'));
            setparamramp(handles.tg, handles.paramid.epsilon, epsilon, 0.1, handles.options.verbosity);
            
        case {'kd_torso_stance','kd_torso_swing'}
            if ~checkstate(handles,'paramid'), return, end
            kd_torso = str2double(get([handles.kd_torso_stance; handles.kd_torso_swing],'String'));
            setparamramp(handles.tg, handles.paramid.kd_torso, kd_torso, 10, handles.options.verbosity);
            
        case {'use2DOFHipControl','kp_2dof','kd_2dof','k_precomp'}
            if ~checkstate(handles,'paramid'), return, end
            use2DOFHipControl = get(handles.use2DOFHipControl, 'Value');
            kp_2dof = str2double(get(handles.kp_2dof,'String'));
            kd_2dof = str2double(get(handles.kd_2dof,'String'));
            k_precomp = str2double(get(handles.k_precomp,'String'));
            setparamsafe(handles.tg, handles.paramid.use2DOFHipControl, use2DOFHipControl);
            setparamsafe(handles.tg, handles.paramid.kp_2dof, kp_2dof);
            setparamsafe(handles.tg, handles.paramid.kd_2dof, kd_2dof);
            setparamsafe(handles.tg, handles.paramid.k_precomp, k_precomp);
            
            % LEG SWAPPING
        case {'swap_kaaccel','swap_kaspring','swap_s','swap_thresh_kaaccel','swap_thresh_kaspring_def','swap_thresh_kaspring_hyst','swap_thresh_s','swap_tmaxupdate'}
            if ~checkstate(handles,'paramid'), return, end
            swap_params = [cell2mat(get([handles.swap_kaaccel; handles.swap_kaspring; handles.swap_s],'Value')); str2double(get([handles.swap_thresh_kaaccel; handles.swap_thresh_kaspring_def; handles.swap_thresh_kaspring_hyst; handles.swap_thresh_s],'String'))];
            setparamsafe(handles.tg, handles.paramid.swap_params, swap_params);
            TMaxUpdate = str2double(get(handles.swap_tmaxupdate,'String'));
%            setparamsafe(handles.tg, handles.paramid.tmaxupdate, TMaxUpdate);
            
        case {'AllowDoubleSupport'}
            if ~checkstate(handles,'paramid'), return, end
            AllowDoubleSupport = get(handles.AllowDoubleSupport, 'Value');
            setparamsafe(handles.tg, handles.paramid.AllowDoubleSupport, AllowDoubleSupport);
            
        case {'manual_swap'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.ManualSwap, 1);
            pause(0.02);
            setparamsafe(handles.tg, handles.paramid.ManualSwap, 0);
            
            % Gait Tweaks  --------------------------------------------------------
        case {'fp_kpy', 'fp_gain_kpx'}
            if ~checkstate(handles,'paramid'), return, end
            fp_kp = str2double(get([handles.fp_gain_kpy; handles.fp_gain_kpx],'String'));
            setparamramp(handles.tg, handles.paramid.kpFootPlacement, fp_kp, 100, handles.options.verbosity);
            
        case {'fp_gain_kdy', 'fp_gain_kdx'}
            if ~checkstate(handles,'paramid'), return, end
            fp_kd = str2double(get([handles.fp_gain_kdy; handles.fp_gain_kdx],'String'));
            setparamramp(handles.tg, handles.paramid.kdFootPlacement, fp_kd, 20, handles.options.verbosity);
            
        case {'fp_torso_offset_y', 'fp_torso_offset_x'}
            if ~checkstate(handles,'paramid'), return, end
            fp_qTdesired = str2double(get([handles.fp_torso_offset_y; handles.fp_torso_offset_x],'String'));
            setparamramp(handles.tg, handles.paramid.qTdesired, fp_qTdesired, 10, handles.options.verbosity);
            
        case {'fp_vdes_y', 'fp_vdes_x'}
            if ~checkstate(handles,'paramid'), return, end
            fp_desired_velocity = str2double(get([handles.fp_vdes_y; handles.fp_vdes_x],'String'));
            setparamsafe(handles.tg, handles.paramid.desired_velocity, fp_desired_velocity);
            
        case {'enableVBLA','fp_kth','fp_min_theta_final','fp_max_theta_final','fp_min_delta_theta','fp_qT'}
            if ~checkstate(handles,'paramid'), return, end
            VBLAOptions = [get(handles.enableVBLA, 'Value'); str2double(get([handles.fp_kth, handles.fp_min_theta_final, handles.fp_max_theta_final, handles.fp_min_delta_theta, handles.fp_qT],'String'))];
            setparamsafe(handles.tg, handles.paramid.VBLAOptions, VBLAOptions);
            
        case {'lat_select','lat_kp','lat_kd','lat_q3dmin','lat_q3dmax','w_torso_lat'}
            if ~checkstate(handles,'paramid'), return, end
            lat_select = get(handles.lat_select, 'Value')-1;
            lateralParams = [lat_select; str2double(get([handles.lat_kp; handles.lat_kd; handles.lat_q3dmin; handles.lat_q3dmax],'String'))];
            w_torso_lat = str2double(get(handles.w_torso_lat, 'String'));
            setparamsafe(handles.tg, handles.paramid.lateralParams, lateralParams);
            setparamsafe(handles.tg, handles.paramid.w_torso_lat, w_torso_lat);
            setparamsafe(handles.tg, handles.paramid.outputParams, [lat_select; 0; 0; 0]);
            
        case {'ActuatedCoordsSwingHipTorso','ActuatedCoordsSwingHipStanceHip','ActuatedCoordsSwingLegAngleTorso','LateralTorsoControlWeight','useParameterizedH0'}
            if ~checkstate(handles,'paramid'), return, end
            WalkingOutputParams = str2double(get([handles.ActuatedCoordsSwingHipTorso; handles.ActuatedCoordsSwingHipStanceHip; handles.ActuatedCoordsSwingLegAngleTorso; handles.LateralTorsoControlWeight; handles.LateralSBeta; handles.LateralSPhi0], 'String'));
            setparamsafe(handles.tg, handles.paramid.WalkingOutputParams, WalkingOutputParams);
            
            useParameterizedH0 = get(handles.useParameterizedH0, 'Value');
            setparamsafe(handles.tg, handles.paramid.useParameterizedH0, useParameterizedH0);
            
        case {'fp_tstep_initial', 'fp_tstep'}
            if ~checkstate(handles,'paramid'), return, end
            fp_tstep_initial = str2double(get(handles.fp_tstep_initial,'String'));
            setparamsafe(handles.tg, handles.paramid.tStepInitial, fp_tstep_initial);
            fp_tstep = str2double(get(handles.fp_tstep,'String'));
%            setparamsafe(handles.tg, handles.paramid.tStep, fp_tstep);
            
        case {'fp_ff_hip_L', 'fp_ff_hip_R'}
            if ~checkstate(handles,'paramid'), return, end
            fp_u_ff_hip = str2double(get([handles.fp_ff_hip_R; handles.fp_ff_hip_L],'String'));
            setparamramp(handles.tg, handles.paramid.u_ff_hip, fp_u_ff_hip, 0.2, handles.options.verbosity);
            
        case {'ff_stance_la', 'ff_stance_ls', 'ff_stance_hip', 'ff_swing_la', 'ff_swing_ls', 'ff_swing_hip'}
            if ~checkstate(handles,'paramid'), return, end
            u_ff = str2double(get([handles.ff_stance_la; handles.ff_swing_la; handles.ff_stance_ls; handles.ff_swing_ls; handles.ff_stance_hip; handles.ff_swing_hip],'String'));
            u_ff = max(-2, min(u_ff, 2));
            setparamramp(handles.tg, handles.paramid.u_ff, u_ff, 0.2, handles.options.verbosity);
            
        case {'fp_step_stance', 'fp_step_swing1', 'fp_step_swing2', 'fp_step_swing3', 'fp_torso_offset'}
            if ~checkstate(handles,'paramid'), return, end
            fp_step_params = str2double(get([handles.fp_step_stance; handles.fp_step_swing1; handles.fp_step_swing2; handles.fp_step_swing3; handles.fp_torso_offset],'String'));
            fp_step_params = max([-8; 0; 0; 0; -25], min(fp_step_params, [25; 25; 25; 25; 25]));
            if length(getparam(handles.tg, handles.paramid.step_params))==7
                setparamsafe(handles.tg, handles.paramid.step_params, [fp_step_params; 0; 0]);
            else
                setparamsafe(handles.tg, handles.paramid.step_params, fp_step_params);
            end
            
        case {'ff_la_decoupling','ff_gravity_compensation_legs','ff_gravity_compensation_hips','ff_gravity_compensation_ramp_width','ff_hip_decoupling'}
            ff_params = str2double(get([handles.ff_la_decoupling; handles.ff_gravity_compensation_legs; handles.ff_gravity_compensation_hips; handles.ff_gravity_compensation_ramp_width; handles.ff_hip_decoupling],'String'));
            setparamramp(handles.tg, handles.paramid.ff_params, ff_params, 0.4, handles.options.verbosity);
            
        case {'fp_enable_transition'}
            if ~checkstate(handles,'paramid'), return, end
            fprintf('Resetting yaw before enabling transition.\n');
            setparamsafe(handles.tg, handles.paramid.ResetYaw, 1);
            pause(0.2);
            setparamsafe(handles.tg, handles.paramid.ResetYaw, get(handles.ResetYaw, 'Value'));
            
            enable_pose = get(handles.enable_pose, 'Value');
            EnableTransitionDelay = str2double(get(handles.EnableTransitionDelay, 'String'));
            if ~isfinite(EnableTransitionDelay)
                EnableTransitionDelay = 10;
            end
            if (EnableTransitionDelay>0)
                % Get GUI position in normalized units
                prevunitsgui = get(handles.figure1, 'Units');
                set(handles.figure1, 'Units', 'normalized');
                pgui = get(handles.figure1, 'Position');
                set(handles.figure1, 'Units', prevunitsgui);
                
                % Set waitbar position based on GUI position
                hwait = waitbar(0, sprintf('Enable Transition in %4.1f (sec)', EnableTransitionDelay));
                prevunitswait = get(hwait, 'Units');
                set(hwait, 'Units', 'normalized');
                pwait = get(hwait, 'Position');
                set(hwait, 'Position', [pgui(1:2)+pgui(3:4)/2-pwait(3:4)/2  pwait(3:4)], 'Units', prevunitswait);
                
                Tmax = EnableTransitionDelay;
                Tstep = 0.05;
                Nstep = floor(Tmax/Tstep);
                for k=1:Nstep
                    pause(Tstep);
                    waitbar(k/Tmax*Tstep, hwait, sprintf('Enable Transition in %d (sec)', ceil((Nstep-k)*Tstep)));
                end
                close(hwait);
            end
            if enable_pose
                enable_cmd = 2;
            else
                enable_cmd = 4;
            end
            setparamsafe(handles.tg, handles.paramid.EnableTransition, enable_cmd);
            %YawControl
            %pause(0.02);
            %setparamsafe(handles.tg, handles.paramid.EnableTransition, 0);
            
        case {'fp_RunMode'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.RunMode, get(handles.fp_RunMode, 'Value')-1);
            if get(handles.fp_RunMode, 'Value')-1==0
                setparamsafe(handles.tg, handles.paramid.ResetControl, 1);
                pause(0.1);
                setparamsafe(handles.tg, handles.paramid.ResetControl, 0);
            end
            
        case {'fp_theta_min','fp_theta_max'}
            theta_limits = str2double(get([handles.fp_theta_min; handles.fp_theta_max],'String'))';
            setparamsafe(handles.tg, handles.paramid.theta_limits_nom, ones(6,1)*theta_limits);
            
        case 'edit_bezier_curves'
            if ~isfield(handles, 'h_alpha_nom') || isempty(handles.h_alpha_nom)
                handles.h_alpha_nom = evalin('base','h_alpha_nom');
            end
            if strcmp(handles.tg.Connected, 'No') || strcmp(handles.tg.Status, 'stopped')
                handles.h_alpha_cur = get(handles.h_alpha_cur_table, 'Data');
            else
                if ~checkstate(handles,'paramid'), return, end
                handles.h_alpha_cur = getparam(handles.tg, handles.paramid.h_alpha_nom);
            end
            bezier_editor(handles.h_alpha_nom, handles.h_alpha_cur, @(h_alpha_new)update_h_alpha(handles.tg, handles, h_alpha_new));
            
            
        case {'reset'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.ResetControl, 1);
            setparamsafe(handles.tg, handles.paramid.EnableTransition, 0);
            set(handles.fp_RunMode, 'Value', 0+1);
            setparamsafe(handles.tg, handles.paramid.RunMode, get(handles.fp_RunMode, 'Value')-1);
            pause(0.1);
            setparamsafe(handles.tg, handles.paramid.ResetControl, 0);
            
        case {'log_event'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.log_event, get(handles.log_event, 'Value'));
            
        case {'ResetYaw'}
            if ~checkstate(handles,'paramid'), return, end
            setparamsafe(handles.tg, handles.paramid.ResetYaw, get(handles.ResetYaw, 'Value'));
            
        case {'DecouplingMode'}
            if ~checkstate(handles,'paramid'), return, end
            DecouplingMode = get(handles.DecouplingMode,'Value');
            setparamsafe(handles.tg, handles.paramid.DecouplingMode, DecouplingMode);
            
            
            % POSING --------------------------------------------------------------
        case {'hd_LA_R', 'hd_LA_L', 'hd_KA_R', 'hd_KA_L', 'hd_hip_R', 'hd_hip_L', 'hd_torso_offset'}
            if ~checkstate(handles,'paramid'), return, end
            hd = str2double(get([handles.hd_LA_R; handles.hd_LA_L; handles.hd_KA_R; handles.hd_KA_L; handles.hd_hip_R; handles.hd_hip_L],'String'));
            torso_offset = str2double(get(handles.hd_torso_offset,'String'));
            hd(1:2) = hd(1:2) - torso_offset;
            %setparamramp(handles.tg, handles.paramid.hd_posing, hd, 10, handles.options.verbosity);
            setparamsafe(handles.tg, handles.paramid.hd_posing, hd);
            
        case {'enable_pose','transition_ka_injection_stance','transition_ka_injection_swing','transition_pitch_rate_threshold','numTransitionSteps'}
            if ~checkstate(handles,'paramid'), return, end
            enable_pose = get(handles.enable_pose, 'Value');
            transitionParams = [enable_pose; str2double(get([handles.transition_ka_injection_stance; handles.transition_ka_injection_swing; handles.transition_pitch_rate_threshold; handles.numTransitionSteps],'String'))];
            setparamsafe(handles.tg, handles.paramid.transitionParams, transitionParams);
            %if ~enable_pose
            %    setparamsafe(handles.tg, handles.paramid.ControllerModeInit, 4);
            %end
            
        case {'UsePosingControl','TPosing','TransitionFinalSwingKA','TransitionFinalSwingHip','LateralTorsoControlWeightTransition'}
            if ~checkstate(handles,'paramid'), return, end
            UsePosingControl = get(handles.UsePosingControl, 'Value');
            setparamsafe(handles.tg, handles.paramid.UsePosingControl, UsePosingControl);
            
            TPosing = str2double(get(handles.TPosing,'String'));
            setparamsafe(handles.tg, handles.paramid.TPosing, TPosing);
            
            TransitionOutputParams = str2double(get([handles.TransitionFinalSwingKA; handles.TransitionFinalSwingHip; handles.LateralTorsoControlWeightTransition],'String'));
            setparamsafe(handles.tg, handles.paramid.TransitionOutputParams, TransitionOutputParams);
            
        case {'TorsoBackOnStep','TorsoBackAngle'}
            if ~checkstate(handles,'paramid'), return, end
            TorsoBackOnStep = str2double(get(handles.TorsoBackOnStep, 'String'));
            setparamsafe(handles.tg, handles.paramid.TorsoBackOnStep, TorsoBackOnStep);
            TorsoBackAngle = str2double(get(handles.TorsoBackAngle, 'String'));
            setparamsafe(handles.tg, handles.paramid.TorsoBackAngle, TorsoBackAngle);
            
        case {'lat_bias', 'lat_bias2', 'EnergyControlGain', 'EnergyControlPhi0'}
            if ~checkstate(handles,'paramid'), return, end
            lat_bias = str2double(get(handles.lat_bias, 'String'));
            setparamsafe(handles.tg, handles.paramid.lat_bias, lat_bias);
            lat_bias2 = str2double(get(handles.lat_bias2, 'String'));
            setparamsafe(handles.tg, handles.paramid.lat_bias2, lat_bias2);
            EnergyControlGain = str2double(get(handles.EnergyControlGain, 'String'));
            setparamsafe(handles.tg, handles.paramid.EnergyControlGain, EnergyControlGain);
            EnergyControlPhi0 = str2double(get(handles.EnergyControlPhi0, 'String'));
            setparamsafe(handles.tg, handles.paramid.EnergyControlPhi0, EnergyControlPhi0);
            
        case {'VelocityControlTorsoGain', 'VelocityControlTorsoV0', 'VelocityControlTorsoMin', 'VelocityControlTorsoMax'}
            if ~checkstate(handles,'paramid'), return, end
            VelocityControlTorsoGain = str2double(get(handles.VelocityControlTorsoGain, 'String'));
            setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoGain, VelocityControlTorsoGain);
            VelocityControlTorsoV0 = str2double(get(handles.VelocityControlTorsoV0, 'String'));
            setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoV0, VelocityControlTorsoV0);
            VelocityControlTorsoMin = str2double(get(handles.VelocityControlTorsoMin, 'String'));
            setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoMin, VelocityControlTorsoMin);
            VelocityControlTorsoMax = str2double(get(handles.VelocityControlTorsoMax, 'String'));
            setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoMax, VelocityControlTorsoMax);
            
            
        case {'bc_enable','bc_roll_des','bc_pitch_des','bc_roll_kpsetpoint','bc_pitch_kpsetpoint','bc_roll_kdsetpoint','bc_pitch_kdsetpoint','bc_roll_kptorque','bc_pitch_kptorque','bc_roll_kdtorque','bc_pitch_kdtorque','bc_sat_setpoint','bc_sat_torque'}
            bc_enable = get(handles.bc_enable, 'Value');
            balanceParams = [bc_enable; str2double(get([handles.bc_roll_des; handles.bc_pitch_des; handles.bc_roll_kpsetpoint; handles.bc_pitch_kpsetpoint; handles.bc_roll_kdsetpoint; handles.bc_pitch_kdsetpoint; handles.bc_roll_kptorque; handles.bc_pitch_kptorque; handles.bc_roll_kdtorque; handles.bc_pitch_kdtorque; handles.bc_sat_setpoint; handles.bc_sat_torque],'String'))];
            setparamsafe(handles.tg, handles.paramid.balanceParams, balanceParams);
            
            
            % IMU OFFSETS ---------------------------------------------------------
        case {'UseIMU'}
            if ~checkstate(handles,'paramid'), return, end
            UseIMU = get(handles.UseIMU,'Value');
            setparamsafe(handles.tg, handles.paramid.UseIMU, UseIMU);
            
        case {'imu_roll_offset', 'imu_pitch_offset'}
            if ~checkstate(handles,'paramid'), return, end
            torso_offsets = str2double(get([handles.imu_roll_offset; handles.imu_pitch_offset],'String'));
            setparamsafe(handles.tg, handles.paramid.IMUTorsoOffsets, torso_offsets);
            
        case {'TorsoCOMRollOffset', 'TorsoCOMPitchOffset'}
            if ~checkstate(handles,'paramid'), return, end
            TorsoCOMOffsets = str2double(get([handles.TorsoCOMRollOffset; handles.TorsoCOMPitchOffset],'String'));
            setparamsafe(handles.tg, handles.paramid.TorsoCOMOffsets, TorsoCOMOffsets);
            
        case {'imu_up_compensation'}
            if ~checkstate(handles,'paramid'), return, end
            imu_up_compensation = str2double(get(handles.imu_up_compensation,'String'));
            if (imu_up_compensation>=0 && imu_up_compensation<=1000)
                setparamsafe(handles.tg, handles.paramid.imu_up_compensation, imu_up_compensation);
            end
            if strcmp(handles.tg.Status, 'running')
                imu_up_compensation = getparam(handles.tg, handles.paramid.imu_up_compensation);
                set(handles.imu_up_compensation, 'String', num2str(imu_up_compensation, '%d'));
            end
            
            % SCOPES -------------------------------------------------------------
        case {'scope_torques'}
            if ~checkstate(handles,'scopeconfig'), return, end
            %setscopes(handles.tg, handles.scopeconfig(1));
            %set(handles.scope_menu, 'Value', 1);
            
        case {'scope_errors'}
            %if ~checkstate(handles,'scopeconfig'), return, end
            %setscopes(handles.tg, handles.scopeconfig(2));
            %set(handles.scope_menu, 'Value', 2);
            xpctargetspy;
            
        case {'scope_menu'}
            if ~checkstate(handles,'scopeconfig'), return, end
            %setscopes(handles.tg, handles.scopeconfig(get(handles.scope_menu, 'Value')));
            
        case {'scopes_ylimit', 'scopes_decimation'}
            %{
            if ~checkstate(handles,'paramid'), return, end
            ylim_dec{1} = str2double(get(handles.scopes_ylimit, 'String'));
            if isnan(ylim_dec{1})
                ylim_dec{1} = 'auto';
            else
                ylim_dec{1} = ylim_dec{1}*[-1 1];
            end
            ylim_dec{2} = str2double(get(handles.scopes_decimation,'String'));
            
            setscopes(handles.tg, ylim_dec);
            %}
            % APPLICATION ---------------------------------------------------------
        case {'xpc_application'}
            set(handles.xpc_application, 'Enable', 'off'); drawnow;
            handles = init_xpc(handles,false);
            guidata(hObject, handles);
            set(handles.xpc_load, 'Enable', 'on')
            set(handles.xpc_application, 'Enable', 'on')
            set(handles.xpc_start, 'Enable', 'on')
            set(handles.xpc_logdata, 'Enable', 'on')
            
        case {'xpc_load'}
            set(handles.xpc_load, 'Enable', 'off'); drawnow;
            handles = init_xpc(handles,true);
            guidata(hObject, handles);
            set(handles.xpc_load, 'Enable', 'on')
            set(handles.xpc_application, 'Enable', 'on')
            set(handles.xpc_start, 'Enable', 'on')
            set(handles.xpc_logdata, 'Enable', 'on')
            
        case {'xpc_start'}
            set(handles.xpc_start, 'Enable', 'off'); drawnow;
            connectToTarget;
            try
                if isfield(handles,'paramid') && isfield(handles,'model') && ~isempty(handles.model)
                    setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
                    setparamsafe(handles.tg, handles.paramid.MedullaCommand, 6); % 6=RESET
                    SampleTime = str2double(get(handles.SampleTime,'String'));
                    handles.tg.SampleTime = SampleTime;
                    handles.tg.start();
                else
                    warndlg('Model reload required.');
                end
                if strcmp(handles.tg.Mode, 'Target not ready due to a model initialization error')
                    warndlg('Model reload required.');
                end
            catch err
                
            end
            for k=1:0
                try
                    pause(0.5);
                    handles.tg.display;
                catch err2
                    warning('Caught %s. Trying to reconnect to target.', err2.message);
                end
            end
            setall(handles.tg, handles);
            %StartCallbackWalking();
            while strcmp(handles.tg.Status, 'running') && (handles.tg.ExecTime < 12)
                pause(0.2);
            end
            if ~strcmp(handles.tg.Status, 'running')
                warndlg('Model halted.');
            end
            set(handles.xpc_start, 'Enable', 'on')
            Fs=8000;
            ts=0:1/Fs:0.5;
            y = sin(2*pi*(500+1000*ts).*ts);
            sound(y,Fs); pause(0.4);
            sound(y,Fs); pause(0.4);
            sound(y,Fs);
            
        case {'xpc_stop'}
            connectToTarget;
            if checkstate(handles,'paramid','silent') && ~strcmpi(handles.tg.Application, 'loader')
                setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
                setparamsafe(handles.tg, handles.paramid.MedullaCommand, 4); % 4=HALT
                pause(0.5);
                setparamsafe(handles.tg, handles.paramid.MedullaCommand, 6); % 6=RESET
                pause(0.5);
            end
            if ~strcmpi(handles.tg.Application, 'loader')
                handles.tg.stop();
            end
            set(handles.xpc_load, 'Enable', 'on')
            set(handles.xpc_application, 'Enable', 'on')
            set(handles.xpc_start, 'Enable', 'on')
            set(handles.xpc_logdata, 'Enable', 'on')
            
        case {'xpc_logdata'}
            set(handles.xpc_logdata, 'Enable', 'off'); drawnow;
            connectToTarget;
            if checkstate(handles,'paramid','silent') && ~strcmpi(handles.tg.Application, 'loader')
                setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
                setparamsafe(handles.tg, handles.paramid.MedullaCommand, 4); % 4=HALT
                pause(0.5);
                setparamsafe(handles.tg, handles.paramid.MedullaCommand, 6); % 6=RESET
                pause(0.5);
            end
            if ~strcmpi(handles.tg.Application, 'loader')
                handles.tg.stop();
            end
            [time, output, status, log] = getExperimentData(handles.tg, handles.figure1);
            assignin('base','time',time);
            assignin('base','output',output);
            assignin('base','status',status);
            assignin('base','log',log);
            set(handles.xpc_logdata, 'Enable', 'on')
    end
    
    ignorePattern = '(^scope_)|(^xpc_)|(^med_)';
    tag = get(hObject, 'Tag');
    if isempty(regexp(tag, ignorePattern, 'once')) && strcmp(handles.tg.Status, 'running')
        commandSerialize(handles);
    end
    
    try
        ExpNum = regexp(getlogdir, '(?<=Experiment)(\d+)$', 'match', 'once');
        set(handles.xpc_logdata, 'String', ['Log Data (' ExpNum ')']);
    catch
    end
    
    
function handles = init_xpc(handles,reload)
    handles.model = getListItem(handles.xpc_application);
    handles.tg = connectToTarget(1);
    if reload
        if ~strcmp(handles.tg.Application,'loader') && ~strcmp(handles.tg.Status,'stopped')
            warndlg('INIT_XPC cannot reload the application until the target is stopped.');
            return
        end
        handles.tg.load(handles.model);
    end
    
    SampleTime = str2double(get(handles.SampleTime,'String'));
    handles.tg.SampleTime = SampleTime;
    
    [handles.scopeconfig, handles.paramid] = getsignalids(handles.tg, handles.model);
    if reload && checkstate(handles,'paramid','q')
        setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
    end
    if checkstate(handles,'scopeconfig','q')
        set(handles.scope_menu, 'String', {handles.scopeconfig.name},'Value',1);
        setscopes(handles.tg, handles.scopeconfig(1));
    end
    
    %{
    if checkstate(handles,'paramid','q')
        handles.h_alpha_nom = getparam(handles.tg, handles.paramid.h_alpha_nom);
        if ~any(any(get(handles.h_alpha_cur_table, 'Data')))
            handles.h_alpha_cur = getparam(handles.tg, handles.paramid.h_alpha_nom);
        else
            handles.h_alpha_cur = get(handles.h_alpha_cur_table, 'Data');
        end
        
        theta_limits = str2double(get([handles.fp_theta_min; handles.fp_theta_max],'String'))';
        if ~any(theta_limits)
            theta_limits = getparam(handles.tg, handles.paramid.theta_limits_nom);
            theta_limits = theta_limits(1,:);
        end
        %setparamsafe(handles.tg, handles.paramid.theta_limits_nom, ones(6,1)*theta_limits);
        %theta_limits = getparam(handles.tg, handles.paramid.theta_limits_nom);
        set(handles.fp_theta_min,'String',sprintf('%0.4f',theta_limits(1,1)));
        set(handles.fp_theta_max,'String',sprintf('%0.4f',theta_limits(1,2)));
        
    else
        handles.h_alpha_nom = get(handles.h_alpha_nom_table, 'Data'); %zeros(6,6);
        handles.h_alpha_cur = get(handles.h_alpha_cur_table, 'Data'); %zeros(6,6);
    end
    set(handles.h_alpha_nom_table, 'Data', handles.h_alpha_nom);
    set(handles.h_alpha_cur_table, 'Data', handles.h_alpha_cur);
    update_h_alpha(handles.tg, handles, handles.h_alpha_cur);
    %}
    
    if reload
        setall(handles.tg, handles);
    end
    
    
function setscopes(tg, varargin)
    %{
    scs = tg.getscope();
    if isempty(scs);
        tg.addscope('target',1:6);
        scs = getscope(tg);
        set(scs(1:6), ...
            'NumSamples', 200, ...
            'Decimation', 4, ...
            'TriggerMode', 'Freerun'...
            );
    end
    scs(1:6).stop();
    if isstruct(varargin{1})
        scopeconfig = varargin{1};
        for k=1:min(length(scopeconfig.scope),6)
            scs(k).remsignal();
            if ~isempty(scopeconfig.scope(k).signals)
                scs(k).addsignal(scopeconfig.scope(k).signals);
                PV = getPropValPairs(scopeconfig.scope(k));
                if ~isempty(PV)
                    set(scs(k), PV{:});
                end
            end
        end
    else
        ylim_dec = varargin{1};
        set(scs,'YLimit',ylim_dec{1}, 'Decimation', ylim_dec{2});
    end
    scs(1:6).start();
    %}
    
    
function PV = getPropValPairs(scfg)
    fields = fieldnames(scfg);
    fields = setdiff(fields,'signals');
    PV = [fields(:); cell(length(fields),1)];
    for k=1:length(fields)
        PV{k,2} = scfg.(fields{k});
    end
    PV(cellfun(@isempty,PV(:,2)),:) = [];
    PV = PV';
    
    
function ok = checkstate(handles,var,option)
    ok = true;
    if ~isfield(handles,var) || isempty(handles.(var))
        if 0 %nargin<3 || option(1)=='v' % verbose
            warndlg('CONTROL_GUI is missing ids for model signals or parameters. You may need to load the model or supply a GETSIGNALIDS function for your model.');
        end
        ok = false;
    end
    
    
function str = getListItem(handle)
    list = get(handle,'String');
    num  = get(handle,'Value');
    str = list{num};
    
    
function update_h_alpha(tg,handles,h_alpha_new)
    if ~checkstate(handles,'paramid'), return, end
    handles.h_alpha_cur = h_alpha_new;
    setparamsafe(tg,handles.paramid.h_alpha_nom, h_alpha_new);
    set(handles.h_alpha_cur_table, 'Data', h_alpha_new);
    guidata(handles.figure1, handles);
    
    
    
function setall(tg, handles)
    if ~checkstate(handles,'paramid'), return, end
    
    if ~strcmp(tg.Status,'stopped') && any(getparam(handles.tg, handles.paramid.LegHipTorqueLimit))
        warndlg('SETALL cannot set new parameter values until the target is stopped or saturation is zero.');
        return
    end
    
    setparamsafe(handles.tg, handles.paramid.MedullaCommand, 5); % 5=ERROR (E-STOP)
    setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
    
    % MEDULLAS ------------------------------------------------------------
    setparamsafe(handles.tg, handles.paramid.MedullaCommand, 5); % 5=ERROR (E-STOP)
    
    % SATURATION ----------------------------------------------------------
    setparamsafe(handles.tg, handles.paramid.LegHipTorqueLimit, [0; 0]);
    set(handles.sat_leg_torque, 'String', '0');
    set(handles.sat_hip_torque, 'String', '0');
    
    optimal_sat_weights = str2double(get([handles.optimal_sat_weight_stance; handles.optimal_sat_weight_swing],'String'));
    setparamsafe(handles.tg, handles.paramid.optimal_sat_weights, optimal_sat_weights);
    
    useOptimalSaturation = get(handles.useOptimalSaturation,'Value');
    setparamsafe(handles.tg, handles.paramid.useOptimalSaturation, useOptimalSaturation);
    
    UseKASaturation = get(handles.UseKASaturation,'Value');
    setparamsafe(handles.tg, handles.paramid.UseKASaturation, UseKASaturation);
    KASaturationS1 = str2double(get(handles.KASaturationS1,'String'));
    setparamsafe(handles.tg, handles.paramid.KASaturationS1, KASaturationS1);
    KASaturationEarly = str2double(get(handles.KASaturationEarly,'String'));
    setparamsafe(handles.tg, handles.paramid.KASaturationEarly, KASaturationEarly);
    
    % GAINS ---------------------------------------------------------------
    kp = str2double(get([handles.gain_stance_legangle_p; handles.gain_swing_legangle_p; handles.gain_stance_legshape_p; handles.gain_swing_legshape_p; handles.gain_stance_hip_p; handles.gain_swing_hip_p],'String'));
    setparamsafe(handles.tg, handles.paramid.kp, kp);
    
    kd = str2double(get([handles.gain_stance_legangle_d; handles.gain_swing_legangle_d; handles.gain_stance_legshape_d; handles.gain_swing_legshape_d; handles.gain_stance_hip_d; handles.gain_swing_hip_d],'String'));
    setparamsafe(handles.tg, handles.paramid.kd, kd);
    
    epsilon = str2double(get([handles.gain_stance_epsilon; handles.gain_swing_epsilon],'String'));
    setparamsafe(handles.tg, handles.paramid.epsilon, epsilon);
    
    kd_torso = str2double(get([handles.kd_torso_stance; handles.kd_torso_swing],'String'));
    setparamsafe(handles.tg, handles.paramid.kd_torso, kd_torso);
    
    use2DOFHipControl = get(handles.use2DOFHipControl, 'Value');
    kp_2dof = str2double(get(handles.kp_2dof,'String'));
    kd_2dof = str2double(get(handles.kd_2dof,'String'));
    k_precomp = str2double(get(handles.k_precomp,'String'));
    setparamsafe(handles.tg, handles.paramid.use2DOFHipControl, use2DOFHipControl);
    setparamsafe(handles.tg, handles.paramid.kp_2dof, kp_2dof);
    setparamsafe(handles.tg, handles.paramid.kd_2dof, kd_2dof);
    setparamsafe(handles.tg, handles.paramid.k_precomp, k_precomp);
    
    % LEG SWAPPING
    swap_params = [cell2mat(get([handles.swap_kaaccel; handles.swap_kaspring; handles.swap_s],'Value')); str2double(get([handles.swap_thresh_kaaccel; handles.swap_thresh_kaspring_def; handles.swap_thresh_kaspring_hyst; handles.swap_thresh_s],'String'))];
    setparamsafe(handles.tg, handles.paramid.swap_params, swap_params);
    TMaxUpdate = str2double(get(handles.swap_tmaxupdate,'String'));
%    setparamsafe(handles.tg, handles.paramid.tmaxupdate, TMaxUpdate);
    
    AllowDoubleSupport = get(handles.AllowDoubleSupport, 'Value');
    setparamsafe(handles.tg, handles.paramid.AllowDoubleSupport, AllowDoubleSupport);
    
    setparamsafe(handles.tg, handles.paramid.ManualSwap, 0);
    
    % FOOT PLACEMENT ------------------------------------------------------
    %fp_kp = str2double(get([handles.fp_gain_kpy; handles.fp_gain_kpx],'String'));
    %setparamsafe(handles.tg, handles.paramid.kpFootPlacement, fp_kp);
    
    %fp_kd = str2double(get([handles.fp_gain_kdy; handles.fp_gain_kdx],'String'));
    %setparamsafe(handles.tg, handles.paramid.kdFootPlacement, fp_kd);
    
    %fp_qTdesired = str2double(get([handles.fp_torso_offset_y; handles.fp_torso_offset_x],'String'));
    %setparamsafe(handles.tg, handles.paramid.qTdesired, fp_qTdesired);
    
    fp_desired_velocity = str2double(get([handles.fp_vdes_y; handles.fp_vdes_x],'String'));
%    setparamsafe(handles.tg, handles.paramid.desired_velocity, fp_desired_velocity);
    
    VBLAOptions = [get(handles.enableVBLA, 'Value'); str2double(get([handles.fp_kth, handles.fp_min_theta_final, handles.fp_max_theta_final, handles.fp_min_delta_theta, handles.fp_qT],'String'))];
%    setparamsafe(handles.tg, handles.paramid.VBLAOptions, VBLAOptions);
    
%    lat_select = get(handles.lat_select, 'Value')-1;
%    lateralParams = [lat_select; str2double(get([handles.lat_kp; handles.lat_kd; handles.lat_q3dmin; handles.lat_q3dmax],'String'))];
%    setparamsafe(handles.tg, handles.paramid.lateralParams, lateralParams);
%    setparamsafe(handles.tg, handles.paramid.outputParams, [lat_select; 0; 0; 0]);
%    w_torso_lat = str2double(get(handles.w_torso_lat, 'String'));
%    setparamsafe(handles.tg, handles.paramid.w_torso_lat, w_torso_lat);
    
%    WalkingOutputParams = str2double(get([handles.ActuatedCoordsSwingHipTorso; handles.ActuatedCoordsSwingHipStanceHip; handles.ActuatedCoordsSwingLegAngleTorso; handles.LateralTorsoControlWeight; handles.LateralSBeta; handles.LateralSPhi0], 'String'));
%    setparamsafe(handles.tg, handles.paramid.WalkingOutputParams, WalkingOutputParams);
    
%    useParameterizedH0 = get(handles.useParameterizedH0, 'Value');
%    setparamsafe(handles.tg, handles.paramid.useParameterizedH0, useParameterizedH0);
            
    %fp_u_ff_hip = str2double(get([handles.fp_ff_hip_R; handles.fp_ff_hip_L],'String'));
    %setparamsafe(handles.tg, handles.paramid.u_ff_hip, fp_u_ff_hip);
    
    u_ff = str2double(get([handles.ff_stance_la; handles.ff_swing_la; handles.ff_stance_ls; handles.ff_swing_ls; handles.ff_stance_hip; handles.ff_swing_hip],'String'));
    u_ff = max(-2, min(u_ff, 2));
    setparamsafe(handles.tg, handles.paramid.u_ff, u_ff);
    
    ff_params = str2double(get([handles.ff_la_decoupling; handles.ff_gravity_compensation_legs; handles.ff_gravity_compensation_hips; handles.ff_gravity_compensation_ramp_width; handles.ff_hip_decoupling],'String'));
    setparamsafe(handles.tg, handles.paramid.ff_params, ff_params);
    
    fp_step_params = str2double(get([handles.fp_step_stance; handles.fp_step_swing1; handles.fp_step_swing2; handles.fp_step_swing3; handles.fp_torso_offset],'String'));
    fp_step_params = max([0; 0; 0; 0; -25], min(fp_step_params, [25; 25; 25; 25; 25]));
    if length(getparam(handles.tg, handles.paramid.step_params))==7
        setparamsafe(handles.tg, handles.paramid.step_params, [fp_step_params; 0; 0]);
    else
        setparamsafe(handles.tg, handles.paramid.step_params, fp_step_params);
    end
%    theta_limits = str2double(get([handles.fp_theta_min; handles.fp_theta_max],'String'))';
%    setparamsafe(handles.tg, handles.paramid.theta_limits_nom, ones(6,1)*theta_limits);
    
%    h_alpha_cur = get(handles.h_alpha_cur_table, 'Data');
%    setparamsafe(tg,handles.paramid.h_alpha_nom, h_alpha_cur);
    
    set(handles.fp_enable_transition, 'Value', 0);
    setparamsafe(handles.tg, handles.paramid.EnableTransition, 0);
    setparamsafe(handles.tg, handles.paramid.ResetControl, 1);
    pause(0.02);
    setparamsafe(handles.tg, handles.paramid.ResetControl, 0);
    
%    setparamsafe(handles.tg, handles.paramid.log_event, 0);
    
    setparamsafe(handles.tg, handles.paramid.ResetYaw, get(handles.ResetYaw, 'Value'));
    
    DecouplingMode = get(handles.DecouplingMode,'Value');
    setparamsafe(handles.tg, handles.paramid.DecouplingMode, DecouplingMode);
    
    fp_tstep_initial = str2double(get(handles.fp_tstep_initial,'String'));
    setparamsafe(handles.tg, handles.paramid.tStepInitial, fp_tstep_initial);
    fp_tstep = str2double(get(handles.fp_tstep,'String'));
%    setparamsafe(handles.tg, handles.paramid.tStep, fp_tstep);
    RunMode = get(handles.fp_RunMode,'Value')-1;
    setparamsafe(handles.tg, handles.paramid.RunMode, RunMode);
    
    % POSING --------------------------------------------------------------
    hd = str2double(get([handles.hd_LA_R; handles.hd_LA_L; handles.hd_KA_R; handles.hd_KA_L; handles.hd_hip_R; handles.hd_hip_L],'String'));
    torso_offset = str2double(get(handles.hd_torso_offset,'String'));
    hd(1:2) = hd(1:2) - torso_offset;
    setparamsafe(handles.tg, handles.paramid.hd_posing, hd);
    
    enable_pose = get(handles.enable_pose, 'Value');
    transitionParams = [enable_pose; str2double(get([handles.transition_ka_injection_stance; handles.transition_ka_injection_swing; handles.transition_pitch_rate_threshold; handles.numTransitionSteps],'String'))];
    setparamsafe(handles.tg, handles.paramid.transitionParams, transitionParams);
    %if ~enable_pose
    %    setparamsafe(handles.tg, handles.paramid.ControllerModeInit, 4);
    %    setparamsafe(handles.tg, handles.paramid.ResetControl, 1);
    %    pause(0.1);
    %    setparamsafe(handles.tg, handles.paramid.ResetControl, 0);
    %end
    
    UsePosingControl = get(handles.UsePosingControl, 'Value');
    setparamsafe(handles.tg, handles.paramid.UsePosingControl, UsePosingControl);
    
    TPosing = str2double(get(handles.TPosing,'String'));
    setparamsafe(handles.tg, handles.paramid.TPosing, TPosing);
    
    TransitionOutputParams = str2double(get([handles.TransitionFinalSwingKA; handles.TransitionFinalSwingHip; handles.LateralTorsoControlWeightTransition],'String'));
%    setparamsafe(handles.tg, handles.paramid.TransitionOutputParams, TransitionOutputParams);
    
    TorsoBackOnStep = str2double(get(handles.TorsoBackOnStep, 'String'));
%    setparamsafe(handles.tg, handles.paramid.TorsoBackOnStep, TorsoBackOnStep);
    TorsoBackAngle = str2double(get(handles.TorsoBackAngle, 'String'));
%    setparamsafe(handles.tg, handles.paramid.TorsoBackAngle, TorsoBackAngle);
    
    lat_bias = str2double(get(handles.lat_bias, 'String'));
%    setparamsafe(handles.tg, handles.paramid.lat_bias, lat_bias);
    lat_bias2 = str2double(get(handles.lat_bias2, 'String'));
%    setparamsafe(handles.tg, handles.paramid.lat_bias2, lat_bias2);
    EnergyControlGain = str2double(get(handles.EnergyControlGain, 'String'));
%    setparamsafe(handles.tg, handles.paramid.EnergyControlGain, EnergyControlGain);
    EnergyControlPhi0 = str2double(get(handles.EnergyControlPhi0, 'String'));
%    setparamsafe(handles.tg, handles.paramid.EnergyControlPhi0, EnergyControlPhi0);
    
    VelocityControlTorsoGain = str2double(get(handles.VelocityControlTorsoGain, 'String'));
%    setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoGain, VelocityControlTorsoGain);
    VelocityControlTorsoV0 = str2double(get(handles.VelocityControlTorsoV0, 'String'));
%    setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoV0, VelocityControlTorsoV0);
    VelocityControlTorsoMin = str2double(get(handles.VelocityControlTorsoMin, 'String'));
%    setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoMin, VelocityControlTorsoMin);
    VelocityControlTorsoMax = str2double(get(handles.VelocityControlTorsoMax, 'String'));
%    setparamsafe(handles.tg, handles.paramid.VelocityControlTorsoMax, VelocityControlTorsoMax);
    
    bc_enable = get(handles.bc_enable, 'Value');
    balanceParams = [bc_enable; str2double(get([handles.bc_roll_des; handles.bc_pitch_des; handles.bc_roll_kpsetpoint; handles.bc_pitch_kpsetpoint; handles.bc_roll_kdsetpoint; handles.bc_pitch_kdsetpoint; handles.bc_roll_kptorque; handles.bc_pitch_kptorque; handles.bc_roll_kdtorque; handles.bc_pitch_kdtorque; handles.bc_sat_setpoint; handles.bc_sat_torque],'String'))];
%    setparamsafe(handles.tg, handles.paramid.balanceParams, balanceParams);
    
    % IMU OFFSETS ---------------------------------------------------------
    torso_offsets = str2double(get([handles.imu_roll_offset; handles.imu_pitch_offset],'String'));
    setparamsafe(handles.tg, handles.paramid.IMUTorsoOffsets, torso_offsets);
    
    TorsoCOMOffsets = str2double(get([handles.TorsoCOMRollOffset; handles.TorsoCOMPitchOffset],'String'));
    setparamsafe(handles.tg, handles.paramid.TorsoCOMOffsets, TorsoCOMOffsets);
    
    UseIMU = get(handles.UseIMU,'Value');
%    setparamsafe(handles.tg, handles.paramid.UseIMU, UseIMU);
%{    
    imu_up_compensation = str2double(get(handles.imu_up_compensation,'String'));
    if (imu_up_compensation>=2 && imu_up_compensation<=1000)
        setparamsafe(handles.tg, handles.paramid.imu_up_compensation, imu_up_compensation);
    end
    if strcmp(handles.tg.Status, 'running')
        imu_up_compensation = getparam(handles.tg, handles.paramid.imu_up_compensation);
        set(handles.imu_up_compensation, 'String', num2str(imu_up_compensation, '%d'));
    end
%}

function menu_cd_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_load (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    PathName = uigetdir(handles.cd);
    if PathName~=0
        handles.cd = PathName;
        addpath(handles.cd);
        d = dir('BasicWalking_v01_xpc.mdl');
        %d = dir('*.mdl');
        d = dir(handles.mdlpattern);
        dl = dir('Lib*.mdl');
        models = regexprep(setdiff({d.name}',{dl.name}.'),'\.mdl','');
        if isempty(models)
            set(handles.xpc_application, 'Value',1,'String', ' ');
        else
            set(handles.xpc_application, 'Value',1,'String', models);
        end
    end
    
    
function menu_open_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_load (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    [FileName,PathName] = uigetfile(fullfile(mylogdir(),'*.mat'));
    if ~isnumeric(FileName)
        data = load(fullfile(PathName,FileName), 'guivalues');
        setguivalues(hObject,data.guivalues);
    end
    setall(handles.tg, handles);
    set(handles.xpc_logdata, 'Value', 0);
    
    
    % --------------------------------------------------------------------
function menu_saveas_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_saveas (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    guivalues = getguivalues(hObject);
    [FileName,PathName] = uiputfile(fullfile(getlogdir(),'*.mat'));
    if ~isnumeric(FileName)
        save(fullfile(PathName,FileName), 'guivalues');
    end
    
    
    % --- Executes during object creation, after setting all properties.
function edit_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to gain_epsilon (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called
    
    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
    
    
    % --------------------------------------------------------------------
function menu_toworkspace_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_saveas (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    setalltoworkspace(handles);

    
function commandSerialize(handles)
    
    setparamsafe(handles.tg, handles.paramid.CommandSerialize, 1);
    pause(0.1);
    setparamsafe(handles.tg, handles.paramid.CommandSerialize, 0);
