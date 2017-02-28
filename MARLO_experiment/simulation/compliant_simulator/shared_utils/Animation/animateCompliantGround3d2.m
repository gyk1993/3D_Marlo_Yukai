function animateCompliantGround3d2(q_sol, t_sol, view_angle, make_film_flag, even_sample_fs, FootPoints, leg, avifile_name)
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Based on the original animation function written by Alireza Ramezani and
    % Kaveh Akbari Hamed. (Modifications for compliant ground simulator and
    % nontrivial feet added by Kevin Galloway.)
    %
    % Inputs:
    %       q_sol: time-based matrix of q values, with each row
    %       taking the form
    %        [xT,yT,zT,qzT,qyT,qxT,q1R,q2R,q1L,q2L,qgr1R,qgr2R,q3R,qgr1L,qgr2L,q3L]
    %       t_sol: time series corresponding to q_sol
    %       view_angle_pref: 1=default 3-d; 2=front; 3=side; 4=overhead
    %       make_film_flag: true -> create avi file
    %       frame_skip_flag: true -> skips frames to make the animation run faster
    %       slow_motion_flag: true -> adds a delay in between frames to
    %           slow down motion; only affects the real-time playback, not the
    %           avi file
    %
    % Outputs:
    %        -
    %
    % Update fields:
    %
    %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if nargin<8 || isempty(avifile_name)
        avifile_name = '3d_CompGrnd_simulation';
    end
    
    if nargin < 7 || isempty(leg)
        display_stance_leg = false;
    else
        display_stance_leg = true;
    end
    if nargin <5, even_sample_fs = 150; end
    if nargin < 4, make_film_flag = false; end
    if nargin < 3, view_angle=1; end
    
    switch view_angle
        case 1 %Default 3d
            view_angle_vect =  [-37.5, 30];
            setview = @(ax) view(ax,view_angle_vect);
        case 2 %Front
            view_angle_vect =  [180, 0];
            setview = @(ax) view(ax,view_angle_vect);
        case 3 % Right side
            view_angle_vect =  [90, 0];
            setview = @(ax) view(ax,view_angle_vect);
        case 4 %Overhead
            view_angle_vect =  [0, 90];
            setview = @(ax) view(ax,view_angle_vect);
        case 5 % Left side
            view_angle_vect =  [270, 0];
            setview = @(ax) view(ax,view_angle_vect);
        case 6
            setview = @(ax) set(ax,'CameraPosition',[-15 -15 7],'CameraTarget',[0 0 1.2],'CameraViewAngle',12,...
                'XLim',[-3 3], 'YLim',[-3 3], 'ZLim',[0 2.5],'DataAspectRatio',[1 1 1]);
        otherwise
            disp('Invalid view angle; using default 3d view')
            view_angle_vect =  [-37.5, 30];
            setview = @(ax) view(ax,view_angle_vect);
    end
    
    
    temp = 1;
    
    %Even-sample the data
    % even_sample_fs = 150;
    [t_even, q_even] = even_sample(t_sol, q_sol, even_sample_fs);
    if display_stance_leg
        [~, leg_even] = even_sample(t_sol, single(leg), even_sample_fs);
        leg_even = round(leg_even);
    end
    
    % Prepare data to draw feet
    if size(FootPoints,2)>=3
        FootPointsAugR = [FootPoints; ones(1,size(FootPoints,2))];
        FootPointsAugL = diag([-1 1 1 1])*FootPointsAugR;
        FootTri = convhull(FootPoints(1,:)', FootPoints(2,:)', FootPoints(3,:)');
    end
    
    h = figure('Name', 'ATRIAS3D Simulator', 'Color', 'w');
    set(h, 'Position', [50 41 1920 1080]);
    if view_angle==6
        set(h,'Position',[50 41 1920 1080]);
    end
    
    if make_film_flag
        if ispc
%             anim_dir = 'D:\bgbuss\biped\video\animations\ATRIAS3D\FootPlacement';
            anim_dir = [pwd,'\animation'];
        else
            anim_dir = pwd;
        end
        avifile_name = fullfile(anim_dir,[avifile_name '_' ,datestr(now,'ddmmmyy_HHMMSS') '.avi']);
        
        fprintf('Creating <a href="matlab:winopen(''%s'');">%s</a>\n',avifile_name,avifile_name);
        fprintf('Open folder <a href="matlab:winopen(''%s'');">%s</a>\n',anim_dir,anim_dir);
        mov = VideoWriter(avifile_name); %,'MPEG-4');
        mov.FrameRate = 30;
        open(mov);
    end
    
    
    for i=1:temp:length(t_even)
        [pcm p0 p0T pHR p1R p2R p3R p4R pHL p1L p2L p3L p4L] =  ATRIAS3D_Primary_PointsHip(q_even(i,:));
        
        xr = [p1R(1) p2R(1) p3R(1) p4R(1);pHR(1) pHR(1) p1R(1) p2R(1)]; %x-coordinates of points on the right leg
        yr = [p1R(2) p2R(2) p3R(2) p4R(2);pHR(2) pHR(2) p1R(2) p2R(2)]; %y-coordinates of points on the right leg
        zr = [p1R(3) p2R(3) p3R(3) p4R(3);pHR(3) pHR(3) p1R(3) p2R(3)]; %z-coordinates of points on the right leg
        
        xl = [p1L(1) p2L(1) p3L(1) p4L(1);pHL(1) pHL(1) p1L(1) p2L(1)]; %x-coordinates of points on the left leg
        yl = [p1L(2) p2L(2) p3L(2) p4L(2);pHL(2) pHL(2) p1L(2) p2L(2)]; %y-coordinates of points on the left leg
        zl = [p1L(3) p2L(3) p3L(3) p4L(3);pHL(3) pHL(3) p1L(3) p2L(3)]; %z-coordinates of points on the left leg
        
        xh = [pHL(1); p0(1); pHR(1)]; %x-coordinates of points on the hips
        yh = [pHL(2); p0(2); pHR(2)]; %y-coordinates of points on the hips
        zh = [pHL(3); p0(3); pHR(3)]; %z-coordinates of points on the hips
        
        xt = [p0T(1) ;p0(1)]; %x-coordinates of points on the torso
        yt = [p0T(2) ;p0(2)]; %y-coordinates of points on the torso
        zt = [p0T(3) ;p0(3)]; %z-coordinates of points on the torso
        
        clf(h); ax=axes('Parent', h, 'Box', 'off'); hold on;
        
        % draw feet
        if size(FootPoints,2)>=3
            [p4R,R1,~,~,p4L,R5,~,~] =  FootPointPosJacobHip_FixParams(q_even(i,:));
            FR = [R1 p4R]*FootPointsAugR;
            FL = [R5 p4L]*FootPointsAugL;
            trisurf(FootTri, FR(1,:)', FR(2,:)', FR(3,:)');
            trisurf(FootTri, FL(1,:)', FL(2,:)', FL(3,:)');
        end
        
        % check
        %[pR, pL] = FootPointPos(q_even(i,:), FootPoints);
        %line(pR(1,:)', pR(2,:)', pR(3,:)', 'Marker', '*', 'Color', 'r');
        %line(pL(1,:)', pL(2,:)', pL(3,:)', 'Marker', '*', 'Color', 'm');
        
        line(xr,yr,zr,'LineWidth',3,'Color','b','Parent',ax);line(xl,yl,zl,'LineWidth',3,'Color','r','Parent',ax);line(xh,yh,zh,'LineWidth',2,'Color','g','Parent',ax);
        line(xt,yt,zt,'LineWidth',3,'Color','g','Parent',ax);
        
        plotcom(pcm,eye(3),'coarse',ax);
        
            axis(ax,[-1 1 -1 1 0 2]);
nRate = 2;
    axis(ax,[-1 1 -1 1 -0.1 1]*nRate);
    xlim(ax,[pcm(1)-1*nRate pcm(1)+1*nRate]);
    ylim(ax,[pcm(2)-1*nRate pcm(2)+1*nRate]);
        xlabel(ax,'[m]');ylabel(ax, '[m]');zlabel(ax, '[m]');
        setview(ax);
        grid(ax, 'on');
        %grid(ax,'off');
        %L = 0.5;
        %for k=-10:10, for l=-10:10, if mod(k+l,2), patch(L*(k+[0 0 1 1]), L*(l+[0 1 1 0]), [0 0 0 0],'k','Parent',ax); end, end, end
        
        %Add time readout
        stance_str = {'Right','Left'};
        if display_stance_leg
            time_string = sprintf('Time:   %0.2f s\nStance: %s',t_even(i),stance_str{leg_even(i)+1});
        else
            time_string = sprintf('t = %0.2f s',t_even(i));
        end
        text('Units','normalized',...
            'String',time_string,...
            'Position',[0.70 0.9],...
            'FontSize',14, ...
            'BackgroundColor', 'w', ...
            'Parent', ax);
        
        if make_film_flag
            F = getframe(gcf);
            writeVideo(mov,F);
        end
        
        drawnow;
    end
    
    rotate3d on
    
    
    % Close AVI file.
    if make_film_flag
        close(mov);
    end
    
end
