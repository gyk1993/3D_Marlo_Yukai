function S = parseModelData(varargin)
    
    if nargin<2
        if nargin==1 && isstruct(varargin{1})
            % Single input, structure S with Time, Output, TET, and mdl
            S = varargin{1};
        else
            % Single intput with tg or no input at all
            if nargin==1 && (isa(varargin{1}, 'xpctarget.xpc') || isa(varargin{1}, 'SimulinkRealTime.target'))
                tg = varargin{1};
            else
                tg = xpc;
            end
            S.Time   = tg.TimeLog;
            S.Output = tg.OutputLog;
            S.TET    = tg.TETLog;
            S.mdl    = tg.Application;
        end
    elseif nargin>=3
        S.Time   = varargin{1};
        S.Output = varargin{2};
        S.mdl      = varargin{3};
        if nargin>3
            S.TET    = varargin{4};
        else
            S.TET = [];
        end
    end
    
    if isempty(S.TET)
        S.TET = {[]};
    end
    
    try
        % Get port widths structure
        getPorts = str2func([S.mdl '_compiledPortWidths']);
        Ports   = getPorts();
        
        % Create structure
        Names = ['Model' 'TET' 't' regexp({Ports.PortName},'[^/]+$','match','once') ];
        Values = [S.mdl S.TET S.Time mat2cell(S.Output, size(S.Output,1), [Ports.PortWidth])];
        S = cell2struct(Values, Names,2);
        
        S = parseControlData(S);
    catch err
        warning(err.message);
    end
end
