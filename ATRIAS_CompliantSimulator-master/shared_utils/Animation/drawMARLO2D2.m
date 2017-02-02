function H = drawMARLO2D2(H, q, varargin)
    
    if nargin<1
        H = [];
        q = [0;-0.0700964678310098;-0.14226213154759;0.2+2.93641815812871;0.1+3.59566654200422;2.93575206008736;3.58576859099216;2.94708882809749;3.58275326854242;0.062686484508572;2.94998728017648;3.57802215088022;-0.0473683957715823];
    end
    
    if isempty(H) || ~isstruct(H)
        Options = parseOptions(varargin{:});
        H = initializeDrawing(Options);
    end
    
    Rx = @(t) [1 0 0 ; 0 cos(t) -sin(t); 0 sin(t) cos(t)];
    Ry = @(t) [cos(t) 0 sin(t); 0 1 0 ; -sin(t) 0 cos(t)];
    Rz = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
    
    % Key positions
    if length(q)==16
        p0 = q(1:3);
        q = q(4:end);
    else
        p0 = [0; 0; 0.95];
    end
    [pcm, p0, p0T, pHR, p1R, p2R, p3R, p4R, pHL, p1L, p2L, p3L, p4L] = CATRIAS3D_Positions_Hip([p0; q]);
    
    PleftF  = [pHL p2L p4L]';
    PleftB  = [pHL p1L p3L]';
    PrightF = [pHR p2R p4R]';
    PrightB = [pHR p1R p3R]';
    Ptorso  = [ p0 p0+H.LT*unit(p0T-p0)]';
    Plabel  = p0+(0.1+H.LT)*unit(p0T-p0);
    
    
    qxT   = q(3);
    qyT   = q(2);
    q3R   = q(10);
    q3L   = q(13);
    
    % Foot data
    if size(H.Options.FootPoints,2)>=3
        [p4R,R1,~,~,p4L,R5] =  ATRIAS3D_FootPointPosJacob_Hip([p0; q]);
        FR = [R1 p4R]*H.FootPointsAugR;
        FL = [R5 p4L]*H.FootPointsAugL;
    end
    
    % Define a dynamical system to smoothly track the robot position
    a = 0.0; % eigenvalue
    bSagittal = 0.3;  % normalized steady-state position of the robot in the view
    bFrontal  = 0.5;  % normalized steady-state position of the robot in the view
    
    if (H.Options.Sagittal)
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % SAGITTAL PLANE
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        
        Pbody = bsxfun(@plus, H.Sagittal.body.P*Rx(qxT)', p0');
        PmotR = bsxfun(@plus, H.Sagittal.motR.P, pHR');
        PmotL = bsxfun(@plus, H.Sagittal.motL.P, pHL');
        
        % Draw left leg
        set(H.Sagittal.leftF.line, 'XData', PleftF(:,1), 'YData', PleftF(:,2), 'ZData', PleftF(:,3));
        set(H.Sagittal.leftB.line, 'XData', PleftB(:,1), 'YData', PleftB(:,2), 'ZData', PleftB(:,3));
        set(H.Sagittal.motL.patch, 'XData', PmotL(:,1),  'YData', PmotL(:,2),  'ZData', PmotL(:,3));
        
        % Draw torso body and motors
        set(H.Sagittal.body.patch, 'XData', Pbody(:,1),  'YData', Pbody(:,2),  'ZData', Pbody(:,3));
        %set(H.Sagittal.torso.line, 'XData', Ptorso(:,1), 'YData', Ptorso(:,2), 'ZData', Ptorso(:,3));
        
        % Draw right leg
        set(H.Sagittal.rightF.line, 'XData', PrightF(:,1), 'YData', PrightF(:,2), 'ZData', PrightF(:,3));
        set(H.Sagittal.rightB.line, 'XData', PrightB(:,1), 'YData', PrightB(:,2), 'ZData', PrightB(:,3));
        set(H.Sagittal.motR.patch,  'XData', PmotR(:,1),   'YData', PmotR(:,2),   'ZData', PmotR(:,3));
        
        % Update label
        set(H.Sagittal.label, 'Position', Plabel);
        
        % Update feet
        if size(H.Options.FootPoints,2)>=3
            set(H.Sagittal.leftFoot, 'Vertices', FL');
            set(H.Sagittal.rightFoot, 'Vertices', FR');
        end
        
        % Horizontal axes limits
        H.Sagittal.YCenter = a*H.Sagittal.YCenter + (1-a)*p0(2);
        %set(H.Sagittal.ax, 'YLim', H.Sagittal.YWidth*[-bSagittal 1-bSagittal] + H.Sagittal.YCenter);
    end
    
    if (H.Options.Frontal)
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % FRONTAL PLANE
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        Pbody = bsxfun(@plus, H.Frontal.body.P*Ry(qyT)'*Rx(qxT)', p0');
        PmotR = bsxfun(@plus, H.Frontal.motR.P*Ry(qyT+q3R)', p0');
        PmotL = bsxfun(@plus, H.Frontal.motL.P*Ry(qyT-q3L)', p0');
        
        % Draw left leg
        set(H.Frontal.leftF.line, 'XData', PleftF(:,1), 'YData', PleftF(:,2), 'ZData', PleftF(:,3));
        set(H.Frontal.leftB.line, 'XData', PleftB(:,1), 'YData', PleftB(:,2), 'ZData', PleftB(:,3));
        set(H.Frontal.motL.patch, 'XData', PmotL(:,1),  'YData', PmotL(:,2),  'ZData', PmotL(:,3));
        
        % Draw torso body and motors
        set(H.Frontal.body.patch, 'XData', Pbody(:,1),  'YData', Pbody(:,2),  'ZData', Pbody(:,3));
        %set(H.Frontal.torso.line, 'XData', Ptorso(:,1), 'YData', Ptorso(:,2), 'ZData', Ptorso(:,3));
        
        % Draw right leg
        set(H.Frontal.rightF.line, 'XData', PrightF(:,1), 'YData', PrightF(:,2), 'ZData', PrightF(:,3));
        set(H.Frontal.rightB.line, 'XData', PrightB(:,1), 'YData', PrightB(:,2), 'ZData', PrightB(:,3));
        set(H.Frontal.motR.patch,  'XData', PmotR(:,1),   'YData', PmotR(:,2),   'ZData', PmotR(:,3));
        
        % Update label
        set(H.Frontal.label, 'Position', Plabel);
        
        % Update feet
        if size(H.Options.FootPoints,2)>=3
            set(H.Frontal.leftFoot, 'Vertices', FL');
            set(H.Frontal.rightFoot, 'Vertices', FR');
        end
        
        % Horizontal axes limits
        H.Frontal.XCenter = a*H.Frontal.XCenter + (1-a)*p0(1);
        %set(H.Frontal.ax, 'XLim', H.Frontal.XWidth*[-bFrontal 1-bFrontal] + H.Frontal.XCenter);
    end
end

function H = initializeDrawing(Options)
    
    % Define colors
    torsocolor = 'k';
    rightcolor = [0 0 1];
    leftcolor  = [0 0.7 0];
    motcolor   = [232 137 44]/255;
    bodycolor  = [0.8 0.8 0.8];
    
    % dimensions
    H.rmot = 0.12; % (m)
    H.LT   = 0.65;  % (m)
    
    ZLim = [-0.1 1.8];
    
    
    H.Options = Options;
    
    if size(H.Options.FootPoints,2)>=3
        % Prepare data to draw feet
        H.Options.FootPoints = [[0; 0; 0] H.Options.FootPoints];
        H.FootPointsAugR = [H.Options.FootPoints; ones(1,size(H.Options.FootPoints,2))];
        H.FootPointsAugL = diag([-1 1 1 1])*H.FootPointsAugR;
        H.FootPointsTri = convhull(H.Options.FootPoints(1,:)', H.Options.FootPoints(2,:)', H.Options.FootPoints(3,:)');
    end
    
    if (H.Options.Sagittal)
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % SAGITTAL PLANE
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        % Setup axes
        H.Sagittal.ax = H.Options.SagittalAxes;
        axis(H.Sagittal.ax, 'equal');
        view(H.Sagittal.ax, 90, 0);
        units = get(H.Sagittal.ax, 'Units');
        set(H.Sagittal.ax, 'ZLim', ZLim, 'Box', 'on', 'Units', 'pixels');
        pos = get(H.Sagittal.ax, 'Position');
        set(H.Sagittal.ax, 'PlotBoxAspectRatio', [1 pos(3)/pos(4) 1]);
        set(H.Sagittal.ax, 'Units', units);
        YLim = get(H.Sagittal.ax, 'YLim');
        H.Sagittal.YWidth  = YLim*[-1; 1];
        H.Sagittal.YCenter = YLim*[1; 1]/2;
        set(H.Sagittal.ax, 'YLim', H.Sagittal.YWidth*[-0.3 1-0.3] + H.Sagittal.YCenter);
        
        
        % Draw ground
        H.Sagittal.ground = patch([-10 -10 10 10], [-3 20 20 -3], [0 0 0 0], 0.4*[1 1 1], 'Parent', H.Sagittal.ax);
        
        % Torso body, motor, and foot shape data
        D     = diag([-1 1]);
        D3    = [0 1 0; 0 0 1];
        Pbody = [cumsum([0 -0.8*H.rmot; 0.33 0; 0 0.25; -0.13 0.13; 0 0.35; -0.09 0.05]); 0 0.7];
        Pbody = roundCorners([Pbody; flipud(Pbody(1:end-1,:))*D], 0.04);
        H.Sagittal.body.P = Pbody*D3;
        
        t    = (0:0.01:2*pi)';
        Pmot = H.rmot*[cos(t) sin(t)];
        H.Sagittal.motR.P = Pmot*D3;
        H.Sagittal.motL.P = Pmot*D3;
        
        % Draw left leg
        H.Sagittal.leftF.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', leftcolor, 'Parent', H.Sagittal.ax);
        H.Sagittal.leftB.line = line(NaN, NaN, NaN, 'LineWidth', 1.5, 'Color', leftcolor, 'Parent', H.Sagittal.ax);
        H.Sagittal.motL.patch = patch(NaN, NaN, NaN, motcolor, 'LineWidth', 2, 'EdgeColor', motcolor*0.5, 'Parent', H.Sagittal.ax);
        
        % Draw torso
        H.Sagittal.body.patch = patch(NaN, NaN, NaN, bodycolor, 'LineWidth', 2, 'EdgeColor', bodycolor*0.5, 'Parent', H.Sagittal.ax);
        H.Sagittal.torso.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', torsocolor, 'Parent', H.Sagittal.ax);
        
        % Draw right leg
        H.Sagittal.rightF.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', rightcolor, 'Parent', H.Sagittal.ax);
        H.Sagittal.rightB.line = line(NaN, NaN, NaN, 'LineWidth', 1.5, 'Color', rightcolor, 'Parent', H.Sagittal.ax);
        H.Sagittal.motR.patch  = patch(NaN, NaN, NaN, motcolor, 'LineWidth', 2, 'EdgeColor', motcolor*0.5, 'Parent', H.Sagittal.ax);
        
        % Add a label
        H.Sagittal.label = text(NaN, NaN, NaN, H.Options.Label, 'FontSize', 14, 'FontWeight', 'bold', 'Parent', H.Sagittal.ax);
        
        % Draw feet
        if size(H.Options.FootPoints,2)>=3
            hold(H.Sagittal.ax, 'on');
            H.Sagittal.leftFoot   = trisurf(H.FootPointsTri, H.FootPointsAugL(1,:)', H.FootPointsAugL(2,:)', H.FootPointsAugL(3,:)', 'FaceColor', leftcolor, 'Parent', H.Sagittal.ax);
            H.Sagittal.rightFoot  = trisurf(H.FootPointsTri, H.FootPointsAugR(1,:)', H.FootPointsAugR(2,:)', H.FootPointsAugR(3,:)', 'FaceColor', rightcolor, 'Parent', H.Sagittal.ax);
        end
        
    else
        H.Sagittal.ax = [];
    end
    
    if (H.Options.Frontal)
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % FRONTAL PLANE
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        % Setup axes
        H.Frontal.ax  = H.Options.FrontalAxes;
        axis(H.Frontal.ax, 'equal');
        view(H.Frontal.ax, 0, 0);
        units = get(H.Frontal.ax, 'Units');
        set(H.Frontal.ax, 'ZLim', ZLim, 'Box', 'on', 'Units', 'pixels');
        pos = get(H.Frontal.ax, 'Position');
        set(H.Frontal.ax, 'PlotBoxAspectRatio', [pos(3)/pos(4) 1 1]);
        set(H.Frontal.ax, 'Units', units);
        set(H.Frontal.ax, 'XTick', (-10:0.2:10));
        XLim = get(H.Frontal.ax, 'XLim');
        H.Frontal.XWidth  = XLim*[-1; 1];
        H.Frontal.XCenter = XLim*[1; 1]/2;
        set(H.Frontal.ax, 'XLim', H.Frontal.XWidth*[-0.5 1-0.5] + H.Frontal.XCenter);
        
        % Draw ground
        H.Sagittal.ground = patch([-10 -10 10 10], [-3 20 20 -3], [0 0 0 0], 0.4*[1 1 1], 'Parent', H.Frontal.ax);
        
        % Draw torso body and motors
        Dlr   = diag([-1 1]); % flip left-right
        D3    = [1 0 0; 0 0 1]; % map into 3D coordinates
        Pbody = [cumsum([0 -0.8*H.rmot; 0.06 0; 0 0.20; -0.03 0.08; 0 0.05; 0.18 0.10; 0 0.3]); 0 0.7];
        Pbody = roundCorners([Pbody; flipud(Pbody(1:end-1,:))*Dlr], 0.04);
        H.Frontal.body.P = Pbody*D3;
        
        Pmot = H.rmot*([0.5 -1; 2.1 -1; 2.1 1; 0.5 1]);
        Pmot = roundCorners(Pmot, 0.04);
        H.Frontal.motR.P = Pmot*D3;
        H.Frontal.motL.P = Pmot*Dlr*D3;
        
        % Draw left leg
        H.Frontal.leftF.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', leftcolor, 'Parent', H.Frontal.ax);
        H.Frontal.leftB.line = line(NaN, NaN, NaN, 'LineWidth', 1.5, 'Color', leftcolor, 'Parent', H.Frontal.ax);
        H.Frontal.motL.patch = patch(NaN, NaN, NaN, motcolor, 'LineWidth', 2, 'EdgeColor', motcolor*0.5, 'Parent', H.Frontal.ax);
        
        % Draw torso
        H.Frontal.body.patch = patch(NaN, NaN, NaN, bodycolor, 'LineWidth', 2, 'EdgeColor', bodycolor*0.5, 'Parent', H.Frontal.ax);
        H.Frontal.torso.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', torsocolor, 'Parent', H.Frontal.ax);
        
        % Draw right leg
        H.Frontal.rightF.line = line(NaN, NaN, NaN, 'LineWidth', 4, 'Color', rightcolor, 'Parent', H.Frontal.ax);
        H.Frontal.rightB.line = line(NaN, NaN, NaN, 'LineWidth', 1.5, 'Color', rightcolor, 'Parent', H.Frontal.ax);
        H.Frontal.motR.patch  = patch(NaN, NaN, NaN, motcolor, 'LineWidth', 2, 'EdgeColor', motcolor*0.5, 'Parent', H.Frontal.ax);
        
        % Add a label
        H.Frontal.label = text(NaN, NaN, NaN, H.Options.Label, 'FontSize', 14, 'FontWeight', 'bold', 'Parent', H.Frontal.ax);
        
        % Draw feet
        if size(H.Options.FootPoints,2)>=3
            hold(H.Frontal.ax, 'on');
            H.Frontal.leftFoot   = trisurf(H.FootPointsTri, H.FootPointsAugL(1,:)', H.FootPointsAugL(2,:)', H.FootPointsAugL(3,:)', 'FaceColor', leftcolor, 'Parent', H.Frontal.ax);
            H.Frontal.rightFoot  = trisurf(H.FootPointsTri, H.FootPointsAugR(1,:)', H.FootPointsAugR(2,:)', H.FootPointsAugR(3,:)', 'FaceColor', rightcolor, 'Parent', H.Frontal.ax);
        end
    else
        H.Frontal.ax = [];
    end
end

function N = unit(V,dim)
    if nargin<2
        dim = 1;
    end
    N = bsxfun(@rdivide, V, sqrt(sum(V.^2,dim)));
end

function Options = parseOptions(varargin)
    
    % Create some ananymouns functions for validating optional inputs
    checkView = @(v) ismember(v,{'Sagittal', 'Frontal', 'Both'});
    checkAxes = @(a) isempty(a) || ishandle(a) && strcmp(get(a,'Type'), 'axes');
    
    % Create input scheme and parse param/value inputs
    p = inputParser();
    p.addParamValue('View', 'Both', checkView);
    p.addParamValue('SagittalAxes', [], checkAxes);
    p.addParamValue('FrontalAxes',  [], checkAxes);
    p.addParamValue('Label',  '', @ischar);
    p.addParamValue('FootPoints',  []);
    p.addParamValue('SagittalFraction', 0.5);
    p.parse(varargin{:});
    Options = p.Results;
    
    Options.Sagittal = ismember(Options.View,{'Sagittal', 'Both'});
    Options.Frontal = ismember(Options.View,{'Frontal', 'Both'});
    
    % Setup axes if none specified
    if isempty(Options.SagittalAxes) && isempty(Options.FrontalAxes)
        curax = get(gcf,'Children');
        set(curax, 'Visible', 'off');
    end
    figure(gcf);
    set(gcf,'Color', 'w');
    
    if (Options.Sagittal && Options.Frontal)
        if isempty(Options.SagittalAxes)
            Options.SagittalAxes = axes('Position', [0.025 0.15 0.9*Options.SagittalFraction 0.75]);
        end
        if isempty(Options.FrontalAxes)
            Options.FrontalAxes  = axes('Position', [0.075+0.9*Options.SagittalFraction 0.15 0.9*(1-Options.SagittalFraction) 0.75]);
        end
    elseif (Options.Sagittal && isempty(Options.SagittalAxes))
        Options.SagittalAxes = axes('Position', [0.025 0.15 0.95 0.75]);
    elseif (Options.Frontal && isempty(Options.FrontalAxes))
        Options.FrontalAxes  = axes('Position', [0.025 0.15 0.95 0.75]);
    end
end
