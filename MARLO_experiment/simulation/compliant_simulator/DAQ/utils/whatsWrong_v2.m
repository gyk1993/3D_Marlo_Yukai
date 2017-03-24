function whatsWrong(log, F0)
    % Originally written by Brian Buss.
    % Modifications:
    %   20140908 BAG: automatic trim log and red points at initial safety
    %   violation on phase plots.
    %
    %   2014-11-13 BGB: Check EtherCAT Status, Controller State, Medulla
    %   State, DAQReset and generate a sequence of Events.
    
    if nargin<2
        F0 = 180;
    end
%     
%     %log = trimLog(log);
%     newEvent(); % Initialize Events structure
%     
%     % Check DAQ resets
%     if isfield(log, 'DAQReset')
%         DAQReset = log.DAQReset;
%     else
%         DAQReset = all(log.q == 0, 2);
%     end
%     
%     if isfield(log, 'ControlParams')
%         % Check norm of error and error velocity
%         ErrorNormBound = max(abs(log.y),[],2) > log.ControlParams(end).Supervisory.MaxError*pi/180;
%         ErrorVelNormBound = max(abs(log.dy),[],2) > log.ControlParams(end).Supervisory.MaxErrorVel*pi/180;
%         getVariableChanges(log.t, ErrorNormBound, sprintf('norm(y, inf) > %0.0f (degrees)? %%d', log.ControlParams(end).Supervisory.MaxError), 1);
%         getVariableChanges(log.t, ErrorVelNormBound, sprintf('norm(dy, inf) > %0.0f (degrees/sec)? %%d', log.ControlParams(end).Supervisory.MaxErrorVel), 1);
%     end
%     
%     % Check EtherCAT, Control State, Medulla E-Stop, and Reset changes
%     % getVariableChanges(log.t, log.EtherCATStatus(:,1), @(v) sprintf('EtherCAT Error: (%d) "%s"', v, EtherCATError(v)));
%     % getVariableChanges(log.t, log.EtherCATStatus(:,2), 'EtherCAT Master State: %d');
%     % getVariableChanges(log.t, log.EtherCATStatus(:,3), @(v) sprintf('DC Error: (%d) "%s"', v, EtherCATDCError(v)));
%     % getVariableChanges(log.t, log.EtherCATStatus(:,5), 'DC Init State: %d');
%     
%     if isfield(log, 'ControlState')
%         %getVariableChanges(log.t, log.ControlState.SupportState, 'SupportState: %d');
%         getVariableChanges(log.t, log.ControlState.StepCount, 'StepCount: %d');
%         getVariableChanges(log.t, log.ControlState.ControllerMode, 'ControllerMode: %d');
%         getVariableChanges(log.t, log.ControlState.Error, 'Controller Error: %d');
%     end
%     getVariableChanges(log.t, DAQReset, 'DAQ Reset: %d');
%     getVariableChanges(log.t, any(log.MotorCurrentSafe,2), 'MotorCurrentSafe (any): %d');
%     getVariableChanges(log.t, log.CPUOverloadRegulator, 'CPUOverloadRegulator: %d');
%     
%    
%     for k=1:size(log.CPUOverloadCounter, 2)
%         getVariableChanges(log.t, log.CPUOverloadCounter, sprintf('CPUOverloadCounter (%d): %%d', k));
%     end
%     
%     for k=1:6
%         getVariableChanges(log.t, log.MedullaState(:,k), sprintf('Medulla (%d) State: %%d', k));
%         getVariableChanges(log.t, bitget(log.ErrorFlags(:,k), 1), sprintf('Medulla (%d) E-Stop: %%d', k));
%         getVariableChanges(log.t, bitget(log.ErrorFlags(:,k), 2), sprintf('Medulla (%d) LimitSwitch: %%d', k));
%     end
    
    %decodeErrorFlags(log, [], F0+1);
    %decodeSwitches(log, [], F0+2);
    checkSafetyLimits(log, F0+3);
    %try
    %    checkForceTorqueSensors(log, F0+4);
    %catch
    %end
    
%     Events = newEvent();
%     [~,idx] = sort([Events.t]);
%     Events = Events(idx);
%     
%     fprintf('\n');
%     fprintf('Event Sequence:\n');
%     fprintf('Initial state at (t = %8.4f)\n', log.t(1));
%     tlast = -inf;
%     for k=1:length(Events)
%         if (Events(k).t == log.t(1))
%             fprintf('[Initial State]  %s\n',  Events(k).String);
%         elseif (Events(k).t > tlast)
%             fprintf('(t = %8.4f)   %s\n', Events(k).t, Events(k).String);
%         else
%             fprintf('                 %s\n', Events(k).String);
%         end
%         tlast = Events(k).t;
%     end
%     fprintf('\n');
end

function getVariableChanges(t, var, fstr, direction)
    if nargin<4
        direction = 0;
    end
    if ischar(fstr)
        % Create a function handle to generate an event description
        str = fstr;
        fstr = @(v) sprintf(str, v);
    end
    
    % Log initial state
    newEvent(t(1), fstr(var(1)));
    
    % Check for changes, and log them as new events
    if (direction == 0)
        idx = find(diff(var)) + 1;
    else
        idx = find(diff(var) * direction > 0) + 1;
    end
    if length(idx)>100
        warning('Variable %s has too many changes (%d) to include in the event log.', fstr(0), length(idx));
    else
        for k=1:length(idx)
            newEvent(t(idx(k)), fstr(var(idx(k))));
        end
    end
end

function checkSafetyLimits(log,F0)
    [violation, qmin, qmax, dqmin, dqmax, qminv, qmaxv, T] = MARLOBasicSafetyLimits6(log.q(1,:).', log.dq(1,:).');
    Limits = [qmin, qmax, dqmin, dqmax, qminv, qmaxv];
    
    % Get coordinate labels
    CoordList = MARLOBasicSafetyCoords();
    
    CoordName = @(k) CoordList{k}(1:end);
    plotLims = @(Lims) plot(Lims([1 1 6 2 2 5 1]), [0 Lims([4 4]) 0 Lims([3 3]) 0], 'k', 'LineWidth', 2);
    
    LINKEDDATA.T  = log.t;
    LINKEDDATA.Q  = zeros(length(log.t), length(CoordList));
    LINKEDDATA.DQ = zeros(length(log.t), length(CoordList));
    LINKEDDATA.Violation = log.DAQ.SafetyState>0;
    
    % Find first safety count earlier than before and use this to plot
    % initial safety count as red on plots.
    % Compute SafetyCount and determine which limits actually caused the
    % soft stop
    qbar  = log.q * T.' * 180/pi;
    dqbar = log.dq * T.' * 180/pi;
    Violation = ...
        bsxfun(@le, qbar, qmin.') ...
        | bsxfun(@ge, qbar, qmax.') ...
        | bsxfun(@le, dqbar, dqmin.') ...
        | bsxfun(@ge, dqbar, dqmax.') ...
        | bsxfun(@le, bsxfun(@times, dqbar, (qminv - qmin).'), bsxfun(@times, dqmin.', bsxfun(@minus, qbar, qmin.'))) ...
        | bsxfun(@ge, bsxfun(@times, dqbar, (qmax - qmaxv).'), bsxfun(@times, dqmax.', bsxfun(@minus, qmax.', qbar)));
    
    SafetyCountThresh = 4;
    n = size(Violation,1);
    SafetyCount = zeros(n,1);
    SafetyCount(1) = any(Violation(1,:));
    for k=2:n
        if any(Violation(k,:))
            SafetyCount(k) = min(SafetyCount(k-1) + 1, 10);
        else
            SafetyCount(k) = max(0, SafetyCount(k-1) - 1);
        end
    end
    idx = find(SafetyCount >= SafetyCountThresh, 1, 'first');
    
    if ~isempty(idx)
        %fprintf('SOFT-STOP at t=%7.3f:\n', log.t(idx));
        %fprintf('\t%s\n', CoordList{Violation(idx,:)>0});
        newEvent(log.t(idx), ['SOFT-STOP:  ' sprintf('%s  ', CoordList{Violation(idx,:)>0})]);
    else
        newEvent(inf, sprintf('No soft stop (SafetyCount >= %d) detected in the selected time range.', SafetyCountThresh));
    end
    
    FN = F0;
    for k=1:length(CoordList)
        if mod(k-1,12)==0
            figure(FN); FN = FN+1;
            set(gcf, 'Name', CoordName(k));
        end
        
        LINKEDDATA.Q(:,k)  = log.q*T(k,:).'*180/pi;
        LINKEDDATA.DQ(:,k) = log.dq*T(k,:).'*180/pi;
        
        subplot(3,4,mod(k-1,12)+1);
        plot(LINKEDDATA.Q(:,k), LINKEDDATA.DQ(:,k), '.b', 'XDataSource', sprintf('LINKEDDATA.Q(:,%d)', k), 'YDataSource', sprintf('LINKEDDATA.DQ(:,%d)', k)); hold on;
        % Next line added to indicate where each link is at first safety
        % violation.
        plot(LINKEDDATA.Q(idx,k), LINKEDDATA.DQ(idx,k), 'xr', 'MarkerSize',15,'LineWidth',2.5);
        plotLims(Limits(k,:));
        hold off;
        xlabel([CoordList{k} ' (deg)']);
        ylabel(['d' CoordList{k} ' (deg/s)']);
    end
    
    
    % Time plots
    figure(FN); FN = FN+1;
    h = subplot(4,1,1:2);
    plot(LINKEDDATA.T, LINKEDDATA.Q(:,1:4), 'XDataSource', 'LINKEDDATA.T', 'YDataSource', 'LINKEDDATA.Q(:,1:4)'); hold on;
    plot(LINKEDDATA.T, LINKEDDATA.Q(:,9:12), '--', 'XDataSource', 'LINKEDDATA.T', 'YDataSource', 'LINKEDDATA.Q(:,9:12)');
    title('Leg link (-) and gear (--) angles'); ylabel('(deg)');
    
    h(2) = subplot(4,1,3);
    plot(LINKEDDATA.T, LINKEDDATA.Q(:,25:26), 'XDataSource', 'LINKEDDATA.T', 'YDataSource', 'LINKEDDATA.Q(:,25:26)'); hold on;
    title('Hip angles'); ylabel('(deg)');
    
    h(3) = subplot(4,1,4);
    plot(LINKEDDATA.T, LINKEDDATA.Violation, 'XDataSource', 'LINKEDDATA.T', 'YDataSource', 'LINKEDDATA.Violation');
    title('Safety Violation'); ylabel('(deg)');
    
    linkaxes(h,'x');
    
    assignin('base','LINKEDDATA',LINKEDDATA);
    %    for f=F0:FN-1
    %        linkdata(f, 'on');
    %        brush(f, 'on');
    %    end
    
end

function EventsOut = newEvent(t, String)
    persistent Events
    if isempty(Events) || (nargin==0 && nargout==0)
        Events = struct('t', cell(0,1), 'String', cell(0,1));
    end
    if nargin
        Events(end+1) = struct('t', t, 'String', String);
    end
    EventsOut = Events;
end
