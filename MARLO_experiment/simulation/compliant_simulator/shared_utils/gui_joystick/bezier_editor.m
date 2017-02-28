function varargout = bezier_editor(varargin)
    % BEZIER_EDITOR MATLAB code for bezier_editor.fig
    %      BEZIER_EDITOR, by itself, creates a new BEZIER_EDITOR or raises the existing
    %      singleton*.
    %
    %      H = BEZIER_EDITOR returns the handle to a new BEZIER_EDITOR or the handle to
    %      the existing singleton*.
    %
    %      BEZIER_EDITOR('CALLBACK',hObject,eventData,handles,...) calls the local
    %      function named CALLBACK in BEZIER_EDITOR.M with the given input arguments.
    %
    %      BEZIER_EDITOR('Property','Value',...) creates a new BEZIER_EDITOR or raises the
    %      existing singleton*.  Starting from the left, property value pairs are
    %      applied to the GUI before bezier_editor_OpeningFcn gets called.  An
    %      unrecognized property name or invalid value makes property application
    %      stop.  All inputs are passed to bezier_editor_OpeningFcn via varargin.
    %
    %      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
    %      instance to run (singleton)".
    %
    % See also: GUIDE, GUIDATA, GUIHANDLES
    
    % Edit the above text to modify the response to help bezier_editor
    
    % Last Modified by GUIDE v2.5 04-Sep-2013 14:37:35
    
    % Begin initialization code - DO NOT EDIT
    gui_Singleton = 1;
    gui_State = struct('gui_Name',       mfilename, ...
        'gui_Singleton',  gui_Singleton, ...
        'gui_OpeningFcn', @bezier_editor_OpeningFcn, ...
        'gui_OutputFcn',  @bezier_editor_OutputFcn, ...
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
end
% End initialization code - DO NOT EDIT


% --- Executes just before bezier_editor is made visible.
function bezier_editor_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to bezier_editor (see VARARGIN)
    
    % Choose default command line output for bezier_editor
    handles.output = hObject;
    
    % Get a handle to a function which can get signal and parameter ids from
    % the desired xPC Target application
    if nargin>3 && isnumeric(varargin{1})
        handles.h_alpha_nom = varargin{1};
    else
        handles.h_alpha_nom = zeros(6,6);
    end
    if nargin>4 && isnumeric(varargin{2}) && all(size(varargin{2})==size(varargin{1}))
        handles.h_alpha_cur = varargin{2};
    else
        handles.h_alpha_cur = handles.h_alpha_nom;
    end
    if nargin>5 && isa(varargin{3},'function_handle')
        handles.applyFcn = varargin{3};
    else
        handles.applyFcn = @(alpha) [];
    end
    handles.h_alpha_new = handles.h_alpha_cur;
    handles.units_deg = get(handles.bez_unit_deg, 'Value');
    handles.which_displayed = [];
    handles.which_editable  = [];
    handles.edit_points = [];
    
    handles = update(hObject, handles);
    
    % Update handles structure
    guidata(hObject, handles);
    
    
    % UIWAIT makes bezier_editor wait for user response (see UIRESUME)
    % uiwait(handles.figure1);
end

% --- Outputs from this function are returned to the command line.
function varargout = bezier_editor_OutputFcn(hObject, eventdata, handles)
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    % Get default command line output from handles structure
    varargout{1} = handles.output;
end

function handles = update(hObject, handles)
    handles.units_deg = get(handles.bez_unit_deg, 'Value');
    if handles.units_deg
        K = 180/pi;
    else
        K = 1;
    end
    
    handles.which_editable = find(cell2mat(get([handles.bez_edit_1 handles.bez_edit_2 handles.bez_edit_3 handles.bez_edit_4 handles.bez_edit_5 handles.bez_edit_6], 'Value')));
    
    if numel(handles.which_editable)
        handles.which_editable   = handles.which_editable(1);
    else
        handles.which_editable   = 1;
    end
    main_idx = handles.which_editable;
    
    paired_indices = [2 1 4 3 6 5];
    colors = {'b','g','r','c','m',[0.8 0.8 0]};
    
    paired_idx = paired_indices(main_idx);
    
    alpha = handles.h_alpha_new(main_idx,:);
    M = length(alpha)-1;
    haxes = handles.bez_axes;
    
    cla(handles.bez_axes);
    
    s = 0:0.01:1;
    line(s, K*bezier_vec(handles.h_alpha_nom(paired_idx,:), s), 'LineStyle', ':', 'Color', colors{paired_idx}, 'Parent', haxes);
    line(s, K*bezier_vec(handles.h_alpha_new(paired_idx,:), s), 'LineStyle', '-', 'Color', colors{paired_idx}, 'Parent', haxes);
    line(s, K*bezier_vec(handles.h_alpha_nom(main_idx,:), s), 'LineStyle', ':', 'Color', colors{main_idx}, 'Parent', haxes);
    hline=line(s, K*bezier_vec(alpha, s), 'LineStyle', '-', 'Color', colors{main_idx}, 'Parent', haxes);
    set(haxes, 'Box', 'on'); grid on
    
    for k=1:length(alpha)
        hpoints(k)=impoint(haxes, [(k-1)/M K*alpha(k)]);
        setPositionConstraintFcn(hpoints(k), makeConstrainToRectFcn('impoint', [(k-1)/M (k-1)/M], [-inf inf]));
        addNewPositionCallback(hpoints(k), @(pos)updatePlot(haxes, hObject, handles));
        setColor(hpoints(k), colors{main_idx});
        
        hcmenu = get(hpoints(k), 'uicontextmenu');
        exportmenu = uimenu(hcmenu, 'Label', 'Export', 'Callback', @(a,b)export(haxes));
        set(hpoints(k), 'uicontextmenu', hcmenu);
    end
    
    setappdata(haxes, 'alpha', alpha);
    setappdata(haxes, 'impoints', hpoints);
    setappdata(haxes, 'hline', hline);
    updatePlot(haxes, hObject, handles);
end

function updatePlot(haxes, hObject, handles)
    hpoints = getappdata(haxes, 'impoints');
    hline = getappdata(haxes, 'hline');
    
    units_deg = get(handles.bez_unit_deg, 'Value');
    if units_deg
        K = 180/pi;
    else
        K = 1;
    end
    
    alpha = zeros(1, length(hpoints));
    for k=1:length(hpoints)
        pos = getPosition(hpoints(k));
        alpha(k) = pos(2)/K;
    end
    
    s = 0:0.01:1;
    set(hline, 'YData', bezier_vec(K*alpha, s));
    
    % Update tables
    handles.h_alpha_new(handles.which_editable, :) = alpha;
    set(handles.bez_param_table, 'Data', K*handles.h_alpha_new);
    set(handles.bez_diff_table, 'Data', round(1e12*K*(handles.h_alpha_new - handles.h_alpha_nom))/1e12);
    guidata(hObject, handles);
end



% --- Save the Bezier parameters for the currently editable curve
function export(haxes)
    units_deg  = getappdata(haxes, 'units_deg');
    hpoints = getappdata(haxes, 'impoints');
    hline = getappdata(haxes, 'hline');
    
    if units_deg
        K = 180/pi;
    else
        K = 1;
    end
    
    alpha = zeros(1, length(hpoints));
    for k=1:length(hpoints)
        pos = getPosition(hpoints(k));
        alpha(k) = pos(2);
    end
    
    name=inputdlg('Enter variable name:', 'Save Bezier parameters to base workspace', 1);
    while (~isvarname(name{1}) && ~isempty(name))
        name=inputdlg(sprintf('''%s'' is not a valid variable name.\nEnter variable name:', name{1}), 'Save Bezier parameters to workspace', 1);
    end
    if isvarname(name{1})
        assignin('base',name{1},alpha/K);
    end
end

% --- Evaluate a bezier polynomial at a vector of s values
function y = bezier_vec(alpha, s)
    y = zeros(size(alpha,1), size(s,2));
    for k=1:length(s)
        y(:,k) = bezier(alpha, s(k));
    end
end


% --- Executes when selected object is changed in uipanel3.
function uipanel3_SelectionChangeFcn(hObject, eventdata, handles)
    % hObject    handle to the selected object in uipanel3
    % eventdata  structure with the following fields (see UIBUTTONGROUP)
    %	EventName: string 'SelectionChanged' (read only)
    %	OldValue: handle of the previously selected object or empty if none was selected
    %	NewValue: handle of the currently selected object
    % handles    structure with handles and user data (see GUIDATA)
    % which_editable = find(cell2mat(get([handles.bez_edit_1 handles.bez_edit_2 handles.bez_edit_3 handles.bez_edit_4 handles.bez_edit_5 handles.bez_edit_6], 'Value')));
    % if ~isequal(which_editable, handles.which_editable)
    %     hpoints = getappdata(haxes, 'impoints');
    %     delete(hpoints);
    % end
    handles = update(hObject, handles);
    guidata(hObject, handles);
end


% --- Executes when selected object is changed in uipanel2.
function uipanel2_SelectionChangeFcn(hObject, eventdata, handles)
    % hObject    handle to the selected object in uipanel2
    % eventdata  structure with the following fields (see UIBUTTONGROUP)
    %	EventName: string 'SelectionChanged' (read only)
    %	OldValue: handle of the previously selected object or empty if none was selected
    %	NewValue: handle of the currently selected object
    % handles    structure with handles and user data (see GUIDATA)
    handles = update(hObject, handles);
    guidata(hObject, handles);
end


% --- Executes on button press
function bez_main_Callback(hObject, eventdata, handles)
    % hObject    handle to bez_ok (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    
    switch get(hObject, 'Tag')
        case 'bez_apply'
            if ~isequal(handles.h_alpha_new, handles.h_alpha_cur)
                handles.applyFcn(handles.h_alpha_new);
                handles.h_alpha_cur = handles.h_alpha_new;
                
            end
            
        case 'bez_ok'
            if ~isequal(handles.h_alpha_new, handles.h_alpha_cur)
                handles.applyFcn(handles.h_alpha_new);
                handles.h_alpha_cur = handles.h_alpha_new;
            end
            close(handles.figure1);
            
        case 'bez_cancel'
            if ~isequal(handles.h_alpha_new, handles.h_alpha_cur)
                button = questdlg('Discard unapplied changes?','Parameters Modified','Discard','Apply', 'Discard');
                if strcmp(button,'Discard')
                    close(handles.figure1);
                elseif strcmp(button,'Apply')
                    handles.applyFcn(handles.h_alpha_new);
                    handles.h_alpha_cur = handles.h_alpha_new;
                    close(handles.figure1);
                end
            else
                close(handles.figure1);
            end
            
            
        case 'bez_reset_to_nom'
            handles.h_alpha_new = handles.h_alpha_nom;
            guidata(hObject, handles);
            handles = update(hObject, handles);
            
        case 'bez_reset_to_cur'
            handles.h_alpha_new = handles.h_alpha_cur;
            guidata(hObject, handles);
            handles = update(hObject, handles);
    end
    if ishandle(hObject)
        guidata(hObject, handles);
    end
end


% --- Executes when entered data in editable cell(s) in bez_param_table.
function bez_param_table_CellEditCallback(hObject, eventdata, handles)
    % hObject    handle to bez_param_table (see GCBO)
    % eventdata  structure with the following fields (see UITABLE)
    %	Indices: row and column indices of the cell(s) edited
    %	PreviousData: previous data for the cell(s) edited
    %	EditData: string(s) entered by the user
    %	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
    %	Error: error string when failed to convert EditData to appropriate value for Data
    % handles    structure with handles and user data (see GUIDATA)
    
    bez_params = get(handles.bez_param_table, 'Data');
    
    units_deg = get(handles.bez_unit_deg, 'Value');
    if units_deg
        K = 180/pi;
    else
        K = 1;
    end
    
    handles.h_alpha_new = bez_params/K;
    guidata(hObject, handles);
    handles = update(hObject, handles);
    guidata(hObject, handles);
end


% --- Executes when entered data in editable cell(s) in bez_diff_table.
function bez_diff_table_CellEditCallback(hObject, eventdata, handles)
    % hObject    handle to bez_diff_table (see GCBO)
    % eventdata  structure with the following fields (see UITABLE)
    %	Indices: row and column indices of the cell(s) edited
    %	PreviousData: previous data for the cell(s) edited
    %	EditData: string(s) entered by the user
    %	NewData: EditData or its converted form set on the Data property. Empty if Data was not changed
    %	Error: error string when failed to convert EditData to appropriate value for Data
    % handles    structure with handles and user data (see GUIDATA)
    bez_diff = get(handles.bez_diff_table, 'Data');
    
    units_deg = get(handles.bez_unit_deg, 'Value');
    if units_deg
        K = 180/pi;
    else
        K = 1;
    end
    
    handles.h_alpha_new = bez_diff/K + handles.h_alpha_nom;
    guidata(hObject, handles);
    handles = update(hObject, handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function menu_load_from_ws_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_load_from_ws (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    var = inputdlg('Enter name of workspace variable:','Load From Workspace');
    if 1 %isvarname(var{1})
        temp = evalin('base',var{1});
        if isnumeric(temp) && isequal(size(temp), [6 6])
            handles.h_alpha_new = temp;
            guidata(hObject, handles);
            handles = update(hObject, handles);
            guidata(hObject, handles);
        end
    end
end


% --------------------------------------------------------------------
function menu_save_to_ws_Callback(hObject, eventdata, handles)
    % hObject    handle to menu_save_to_ws (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    var = inputdlg('Enter variable name:', 'Save Bezier parameters to base workspace', 1);
    if ~isempty(var)
        if ~isvarname(var{1})
            warndlg(sprintf('''%s'' is not a valid variable name.',var{1}));
        else
            assignin('base',var{1},handles.h_alpha_new);
        end
    end
end
