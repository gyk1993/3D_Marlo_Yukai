function varargout = YawControl(varargin)
    % YAWCONTROL MATLAB code for YawControl.fig
    %      YAWCONTROL, by itself, creates a new YAWCONTROL or raises the existing
    %      singleton*.
    %
    %      H = YAWCONTROL returns the handle to a new YAWCONTROL or the handle to
    %      the existing singleton*.
    %
    %      YAWCONTROL('CALLBACK',hObject,eventData,handles,...) calls the local
    %      function named CALLBACK in YAWCONTROL.M with the given input arguments.
    %
    %      YAWCONTROL('Property','Value',...) creates a new YAWCONTROL or raises the
    %      existing singleton*.  Starting from the left, property value pairs are
    %      applied to the GUI before YawControl_OpeningFcn gets called.  An
    %      unrecognized property name or invalid value makes property application
    %      stop.  All inputs are passed to YawControl_OpeningFcn via varargin.
    %
    %      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
    %      instance to run (singleton)".
    %
    % See also: GUIDE, GUIDATA, GUIHANDLES
    
    % Edit the above text to modify the response to help YawControl
    
    % Last Modified by GUIDE v2.5 12-Feb-2015 11:14:08
    
    % Begin initialization code - DO NOT EDIT
    gui_Singleton = 1;
    gui_State = struct('gui_Name',       mfilename, ...
        'gui_Singleton',  gui_Singleton, ...
        'gui_OpeningFcn', @YawControl_OpeningFcn, ...
        'gui_OutputFcn',  @YawControl_OutputFcn, ...
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
    
    
    % --- Executes just before YawControl is made visible.
function YawControl_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to YawControl (see VARARGIN)
    
    % Choose default command line output for YawControl
    handles.output = hObject;
    
    Reconnect(hObject, handles);
    
    % UIWAIT makes YawControl wait for user response (see UIRESUME)
    % uiwait(handles.figure1);
    
    
    % --- Outputs from this function are returned to the command line.
function varargout = YawControl_OutputFcn(hObject, eventdata, handles)
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    % Get default command line output from handles structure
    varargout{1} = handles.output;
    
    
    % --- Executes on key press with focus on figure1 and none of its controls.
function KeyPressFcn(hObject, eventdata, handles)
    % hObject    handle to figure1 (see GCBO)
    % eventdata  structure with the following fields (see MATLAB.UI.FIGURE)
    %	Key: name of the key that was pressed, in lower case
    %	Character: character interpretation of the key(s) that was pressed
    %	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
    % handles    structure with handles and user data (see GUIDATA)
    switch eventdata.Key
        case {'leftarrow','s','j'}
            AdjustDesiredYawOffset(handles, 1);
        case {'rightarrow','f','l'}
            AdjustDesiredYawOffset(handles, -1);
    end
    
    
    
    % --- Executes on button press in TurnRight.
function TurnRight_Callback(hObject, eventdata, handles)
    % hObject    handle to TurnRight (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    AdjustDesiredYawOffset(handles, -1);
    
    
    % --- Executes on button press in TurnLeft.
function TurnLeft_Callback(hObject, eventdata, handles)
    % hObject    handle to TurnLeft (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    AdjustDesiredYawOffset(handles, 1);
    
function AdjustDesiredYawOffset(handles, direction)
    Increment = str2double(get(handles.Increment, 'String'));
    if ~isfinite(Increment)
        warnbeep
        warning('Increment value is non finite.');
        return
    end
    if ~isfield(handles.pid, 'DesiredYawOffset') || isempty(handles.pid.DesiredYawOffset)
        % Try to reconnect
        handles = Reconnect(handles.figure1, handles);
        
        if ~isfield(handles.pid, 'DesiredYawOffset') || isempty(handles.pid.DesiredYawOffset)
            % If it fails, bail out
            return
        end
    end
    DesiredYawOffset = getparam(handles.tg, handles.pid.DesiredYawOffset);
    DesiredYawOffset = DesiredYawOffset + Increment * pi/180 * direction;
    fprintf('DesiredYawOffset (deg): %f\n', DesiredYawOffset*180/pi);
    setparamsafe(handles.tg, handles.pid.DesiredYawOffset, DesiredYawOffset);
    
    
    % --- Executes during object creation, after setting all properties.
function Increment_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to Increment (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called
    
    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
    
    
    % --- Executes on button press in Reconnect.
function Reconnect_Callback(hObject, eventdata, handles)
    % hObject    handle to Reconnect (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    Reconnect(hObject, handles);

function handles = Reconnect(hObject, handles)
    handles.tg = connectToTarget();
    if strcmpi(handles.tg.Connected, 'Yes') && ~strcmpi(handles.tg.Application, 'loader')
        handles.pid = getAllParamIds(handles.tg);
    else
        handles.pid = [];
    end
    
    % Update handles structure
    guidata(hObject, handles);
