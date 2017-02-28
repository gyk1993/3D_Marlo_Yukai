function varargout = loggui(varargin)
% LOGGUI MATLAB code for loggui.fig
%      LOGGUI, by itself, creates a new LOGGUI or raises the existing
%      singleton*.
%
%      H = LOGGUI returns the handle to a new LOGGUI or the handle to
%      the existing singleton*.
%
%      LOGGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LOGGUI.M with the given input arguments.
%
%      LOGGUI('Property','Value',...) creates a new LOGGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before loggui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to loggui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help loggui

% Last Modified by GUIDE v2.5 14-Mar-2013 22:46:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @loggui_OpeningFcn, ...
                   'gui_OutputFcn',  @loggui_OutputFcn, ...
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


% --- Executes just before loggui is made visible.
function loggui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to loggui (see VARARGIN)

% Defaults
handles.input.logname = 'Experiment';
handles.input.lognum  = NaN;

if nargin>3 && isnumeric(varargin{1})
    handles.input.lognum  = varargin{1};
    set(handles.lognum, 'String', sprintf('%02d',handles.input.lognum));
    
    if nargin>4 && ischar(varargin{2})
        handles.input.logname = strtrim(varargin{2});
        alllognames = cellfun(@strtrim, get(handles.logname, 'String'), 'Uni', 0);
        if ~ismember(handles.input.logname, alllognames)
            set(handles.logname, 'String', [alllognames; handles.input.logname],'Value',length(alllognames)+1);
        end
    end
else
    [logdir, lognum] = getlogdir(strtrim(getselectedvalue(handles.logname)));
    set(handles.lognum, 'String', sprintf('%02d',lognum));
end

% Choose default command line output for loggui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes loggui wait for user response (see UIRESUME)
uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = loggui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
%varargout{1} = handles.output;
if nargout==1
    out.FootType        = getselectedvalue(handles.foottype);
    out.PowerSource     = getselectedvalue(handles.powersource);
    out.Goal            = gettext(handles.goal);
    out.Results         = gettext(handles.results);
    out.HardwareIssues  = gettext(handles.hardwareissues);
    out.LogName         = strtrim(getselectedvalue(handles.logname));
    out.LogNum          = str2double(get(handles.lognum, 'String'));
    varargout{1} = out;
elseif nargout>1
    varargout{1} = getselectedvalue(handles.foottype);
    varargout{2} = getselectedvalue(handles.powersource);
    varargout{3} = gettext(handles.goal);
    varargout{4} = gettext(handles.results);
    varargout{5} = gettext(handles.hardwareissues);
    varargout{6} = strtrim(getselectedvalue(handles.logname));
    varargout{7} = str2double(get(handles.lognum, 'String'));
end

% The figure can be deleted now
delete(handles.figure1);

% --- Executes on button press in button_ok.
function button_ok_Callback(hObject, eventdata, handles)
% hObject    handle to button_ok (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close(handles.figure1);

% --- Executes during object creation, after setting all properties.
function ui_CreateFcn(hObject, eventdata, handles)
% hObject    handle to goal (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes when user attempts to close figure1.
function loggui_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if isequal(get(hObject, 'waitstatus'), 'waiting')
    % The GUI is still in UIWAIT, us UIRESUME
    uiresume(hObject);
else
    % The GUI is no longer waiting, just close it
    delete(hObject);
end

% --- Executes when logname or lognum is changed
function main_CallbackFcn(hObject, eventdata, handles)
switch get(hObject,'Tag')
    case 'logname'
        [logdir, lognum] = getlogdir(strtrim(getselectedvalue(handles.logname)));
        set(handles.lognum, 'String', sprintf('%02d',lognum));
        
    case 'lognum'
        newlogname = strtrim(getselectedvalue(handles.logname));
        [logdir, lognum] = getlogdir(newlogname);
        newlognum = str2double(get(handles.lognum, 'String'));
        
        if strcmp(newlogname, handles.input.logname)
            if (newlognum<lognum) && (newlognum~=handles.input.lognum)
                warndlg(sprintf('The new log number must be greater than (%02d) or equal to (%02d).',lognum-1,handles.input.lognum));
                set(handles.lognum, 'String', sprintf('%02d',lognum-1));
            end
        elseif (newlognum<lognum)
            warndlg(sprintf('The new log number must be greater than (%02d).',lognum-1));
            set(handles.lognum, 'String', sprintf('%02d',lognum));
        end
end

    

function str = getselectedvalue(h)
strings = get(h,'String');val = get(h,'Value');
str = strings{val};


function str = gettext(h)
c = cellstr(get(h,'String'));
str = strtrim(sprintf('%s\n',c{:}));
