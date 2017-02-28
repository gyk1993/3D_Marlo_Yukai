function animateMARLO(log, varargin)
    
    [Options, DrawOptions] = parseOptions(log, varargin{:});
    [T, Q] = prepareData(log, Options);
    fanim = @(H,q) animateMultiple(H, q, DrawOptions);
    filename = anim(fanim, T, Q, Options);
    if ~isempty(filename)
        [fp,fn] = fileparts(filename);
        save(fullfile(fp,fn), 'log', 'Options', 'DrawOptions', 'varargin');
    end
end

function H = animateMultiple(Hin, q, DrawOptions)
    nLogs = length(q)/16;
    for k=1:nLogs
        if isempty(Hin)
            Htmp = [];
            if (k>1)
                DrawOptions(k).SagittalAxes = H(k-1).Sagittal.ax;
                DrawOptions(k).FrontalAxes = H(k-1).Frontal.ax;
            end
        else
            Htmp = Hin(k);
        end
        H(k) = drawMARLO2D2(Htmp, q((1:16)+(k-1)*16), DrawOptions(k));
    end
    
    % Define a dynamical system to smoothly track the robot position in the
    % axes position
    aSagittal = 0.0; % eigenvalue
    bSagittal = 0.3;  % normalized steady-state position of the robot in the view
    aFrontal  = 0.1; % eigenvalue
    bFrontal  = 0.5;  % normalized steady-state position of the robot in the view
    if isempty(Hin)
        if (H(1).Options.Sagittal)
            H(nLogs+1).Sagittal.ax = H(1).Sagittal.ax;
            H(nLogs+1).Sagittal.YCenter = mean(arrayfun(@(h)h.Sagittal.YCenter, H(1:nLogs)));
        end
        if (H(1).Options.Frontal)
            H(nLogs+1).Frontal.XCenter = mean(arrayfun(@(h)h.Frontal.XCenter, H(1:nLogs)));
        end
    else
        H(nLogs+1) = Hin(nLogs+1);
    end
    if (H(1).Options.Sagittal)
        % Horizontal axes limits
        H(nLogs+1).Sagittal.YCenter = aSagittal*H(nLogs+1).Sagittal.YCenter + (1-aSagittal)*max(arrayfun(@(h)h.Sagittal.YCenter, H(1:nLogs)));
        set(H(nLogs+1).Sagittal.ax, 'YLim', H(1).Sagittal.YWidth*[-bSagittal 1-bSagittal] + H(nLogs+1).Sagittal.YCenter);
    end
    if (H(1).Options.Frontal)
        % Horizontal axes limits
        H(nLogs+1).Frontal.XCenter = aFrontal*H(nLogs+1).Frontal.XCenter + (1-aFrontal)*mean(arrayfun(@(h)h.Frontal.XCenter, H(1:nLogs)));
        set(H(1).Frontal.ax, 'XLim', H(1).Frontal.XWidth*[-bFrontal 1-bFrontal] + H(nLogs+1).Frontal.XCenter);
    end
end

function [T, Q] = prepareData(log, Options)
    % Compute absolute positions by assuming stance foot (point foot)
    % position is fixed. Sample if needed for creating a video.
    
    % LOG may actually be an array of logs, in which
    % case the animations are drawn simultaneously
    
    % Compute frame sample times
    t0 = min(arrayfun(@(l)l.t(1), log));
    tf = max(arrayfun(@(l)l.t(end), log));
    T  = t0:Options.Speed/Options.FrameRate:tf;
    
    n = length(log);
    X = 1.0*((1:n)-(n+1)/2);
    Q = cell(1,n);
    for k=1:n
        if ~isfield(log, 'p0') || isempty(log(k).p0)
            [log(k).p0, log(k).dp0] = computeAbsolutePosition(log(k));
            % HACK: Adjust height for feet
            %log(k).p0(:,3) = log(k).p0(:,3) + 0.07; %max(FootPoints(3,:));
        end
        
        log(k) = unroll(log(k));
        
        idx = interp1(log(k).t, 1:length(log(k).t), T, 'nearest', 'extrap');
        %idx = true(size(log.t)); T = log(k).t;
        Q{k} = [log(k).p0(idx,:) log(k).q(idx,:)];
        Q{k}(:,1) = Q{k}(:,1) - Q{k}(1,1) + X(k);
    end
    Q = cell2mat(Q);
end

function [Options, DrawOptions] = parseOptions(log,varargin)
    p = inputParser();
    p.FunctionName = mfilename;
    p.KeepUnmatched = true;
    addParamValue(p, 'MakeVideo', false);
    addParamValue(p, 'FrameRate', 30);
    addParamValue(p, 'Speed', 1);
    addParamValue(p, 'FrameSize', [1900 900]);
    addParamValue(p, 'FilePrefix', 'Animation');
    
    p.parse(varargin{:});
    Options = p.Results;
    
    % Create one DrawOptions struct for each log
    DrawOptions = repmat(p.Unmatched, size(log));
    
    % If labels are specified, we need to assign one tag to each element of
    % the struct array instead of having the cell array of tags in each
    % element of the struct array DrawOptions
    if isfield(DrawOptions, 'Label')
        [DrawOptions.Label] = DrawOptions(1).Label{:};
    end
end

function log = unroll(log)
    % We wish to animate planar views of the robot. We define the sagittal
    % plane to be the vertical plane whose normal makes and angle of qzT
    % with the world frame x-axis. The frontal plane is the vertical plane
    % whose normal makes an angle of qzT with the world frame y-axis. We
    % need to "unroll" the absolute position and "untwist" the orientation
    % so that the coordinates describe motion in these two planes.
    
    if isfield(log, 'dp0') && ~isempty(log.dp0)
        v0 = log.dp0;
    else
        v0 = deriv_filt(log.p0, log.t(2)-log.t(1), 2, 7, 4);
    end
    % Compute components v1 of velocity v0 in sagittal and frontal planes
    % For each v0, qzT, this is computed as 
    %    v1 = Rz(-qzT)v0
    % To compute this efficiently, we do not use matrix multiplication as
    % the matrix changes for each time step.
    qzT = log.q(:,1);
    v1 = ([v0(:,1:2) v0(:,1:2)].*[cos(qzT) sin(qzT) -sin(qzT) cos(qzT)])*[1 1 0 0; 0 0 1 1]';
    % Now integrate the projected velocities to get the position
    log.p0 = [cumtrapz(log.t, v1) log.p0(:,3)];
    % Compute angle of velocity vector relative to positive y-axis
    %theta = atan2(-v0(:,1), v0(:,2));
    % Compute difference between velocity angle and heading
    %phi = theta - log.q(:,1);
    % Convert difference in angle to vectors and integrate
    %log.p0 = [cumtrapz(log.t, [-sin(phi) cos(phi)]) log.p0(:,3)];
    % Zero yaw
    log.q(:,1) = 0;
end

function R = Rz(theta)
    R = [cos(theta) -sin(theta) 0;
        sin(theta)  cos(theta) 0;
        0 0 1];
end
