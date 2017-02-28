function animateCompliantGround3d(q_sol,t_sol, view_angle, make_film_flag,even_sample_fs, foot_adjust_params,foot_geo,ground_terrain_data,leg,avifile_name)
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
    %       linux_flag: true -> animating on a Linux machine
    %
    % Outputs:
    %        -
    %
    % Update fields:
    %
    %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if nargin<10 || isempty(avifile_name)
        avifile_name = '3d_CompGrnd_simulation';
    end
    
    if nargin < 9 || isempty(leg)
        display_stance_leg = false;
    else
        display_stance_leg = true;
    end
    
    if nargin<8
        xLine = -3:1:10;
        yLine = -3:1:10;
        [X,Y] = meshgrid(xLine, yLine);
        Z = 0.*Y;
        ground_terrain_data{1} = X;
        ground_terrain_data{2} = Y;
        ground_terrain_data{3} = Z;
    end
    
    if nargin <7
        %Foot geometry for "sleeveless" prosthetic
        foot_length = .24; %length of the foot from heel to toe
        length_behind_heel = .07; %distance from the back of the heel to the ankle
        heel_width = .045; % width of the foot at the heel
        toe_width = .07; % width of the foot at the toes
        y_dist_ankle_to_toe = .22; %the y distance from the ankle point to the toe, along the foot midline
        z_dist_ankle_to_toe = .005; %the height of the toe above the ground, when the foot is flat on the ground
        %         foot_geo = [foot_length length_behind_heel heel_width toe_width y_dist_ankle_to_toe z_dist_ankle_to_toe];
        
        % Foot geometry for "point" feet
        foot_geo = zeros(1,6);
    end
    if nargin < 6
        %Foot adjustment parameters
        footX_param = 22*pi/180;
        footY_param = 0;
        footZ_param = -10*pi/180;
        foot_adjust_params = [footX_param;footY_param;footZ_param];
        
        % Foot geometry for "point" feet
        foot_adjust_params = zeros(3,1);
    end
    % if nargin < 6, slow_motion_flag = false; end
    % if nargin < 5, frame_skip_flag = false; end
    if nargin <5, even_sample_fs = 150; end
    if nargin < 4, make_film_flag = false; end
    if nargin < 3, view_angle=1; end
    
    %These should later become inputs
    draw_feet = true;
    draw_ground = true;
    
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
        case 7 % Yaw side
            setview = @(ax, view_angle_vect) view(ax,[view_angle_vect+90 0]);
		otherwise
            disp('Invalid view angle; using default 3d view')
            view_angle_vect =  [-37.5, 30];
            setview = @(ax) view(ax,view_angle_vect);
    end
    
    
    % % if frame_skip_flag
    % %     temp = 10;
    % % else
    temp = 1;
    % % end;
    % end of if
    
    %Even-sample the data
    % even_sample_fs = 150;
    [t_even, q_even] = even_sample(t_sol, q_sol, even_sample_fs);
    if display_stance_leg
        [~, leg_even] = even_sample(t_sol, single(leg), even_sample_fs);
        leg_even = round(leg_even);
    end
    
    h = figure(1000);clf;
    set(h,'Name', 'ATRIAS3D Simulator. By Alireza Ramezani, University of Michigan')
    
    % h = subplot(211);
    
    if view_angle==6
        set(h,'Position',[50 41 1800 960]);
    else
        set(h,'Position',[50 41 960*1.5 960]);
    end
    
    if make_film_flag
        if ispc
            %         anim_dir = 'D:\bgbuss\biped\video\animations\ATRIAS3D\FootPlacement';
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
    % end of if()
    
    % Populate terrain model
    if draw_ground
        %     [X_grnd,Y_grnd] = meshgrid(-1:.03:1);%meshgrid(-5:.03:5);
        %     board_y_placement = ground_terrain_data(1);
        %     board_height = ground_terrain_data(2);
        %     Z_grnd = board_height*(Y_grnd<=board_y_placement);
        
        X_grnd = ground_terrain_data.X;
        Y_grnd = ground_terrain_data.Y;
        Z_grnd = ground_terrain_data.Z;
        %     [X_grnd,Y_grnd] = meshgrid(-2:.2:2, -2:.2:2);
        %     Z_grnd = X_grnd .* exp(-X_grnd.^2 - Y_grnd.^2);
    end
    
    for i=1:temp:length(t_even)
        % for i = 1
        %     [pcm p0 p0T pHR p1R p2R p3R p4R pHL p1L p2L p3L p4L] =  ATRIAS3D_Primary_PointsHip(q_even(i,:));
        [pcm p0 p0T pHR p1R p2R p3R p4R pHL p1L p2L p3L p4L] =  ATRIAS3D_Positions_Hip(q_even(i,:));
        
        xr = [p1R(1) p2R(1) p3R(1) p4R(1);pHR(1) pHR(1) p1R(1) p2R(1)]; %x-coordinates of points on the right leg
        xl = [p1L(1) p2L(1) p3L(1) p4L(1);pHL(1) pHL(1) p1L(1) p2L(1)]; %x-coordinates of points on the left leg
        xh = [pHL(1);pHR(1)]; %x-coordinates of points on the hips
        xt = [p0T(1) ;(pHR(1)+pHL(1))/2]; %x-coordinates of points on the torso
        
        yr = [p1R(2) p2R(2) p3R(2) p4R(2);pHR(2) pHR(2) p1R(2) p2R(2)]; %y-coordinates of points on the right leg
        yl = [p1L(2) p2L(2) p3L(2) p4L(2);pHL(2) pHL(2) p1L(2) p2L(2)]; %y-coordinates of points on the left leg
        yh = [pHL(2);pHR(2)]; %y-coordinates of points on the hips
        yt = [p0T(2) ;(pHR(2)+pHL(2))/2]; %y-coordinates of points on the torso
        
        zr = [p1R(3) p2R(3) p3R(3) p4R(3);pHR(3) pHR(3) p1R(3) p2R(3)]; %z-coordinates of points on the right leg
        zl = [p1L(3) p2L(3) p3L(3) p4L(3);pHL(3) pHL(3) p1L(3) p2L(3)]; %z-coordinates of points on the left leg
        zh = [pHL(3);pHR(3)]; %z-coordinates of points on the hips
        zt = [p0T(3) ;(pHR(3)+pHL(3))/2]; %z-coordinates of points on the torso
        %                 pts = [pcm,pcmT,pcmHR,pcm1R,pcm2R,pcm3R,pcm4R,pcmHL,pcm1L,pcm2L,pcm3L,pcm4L];
        
        hips_connect_at_torso_base = 1; %If this is 1, we draw the more accurate rendition with hips connecting at the base of the torso
        if(hips_connect_at_torso_base)
            xh = [pHL(1); p0(1); pHR(1)]; %x-coordinates of points on the hips
            yh = [pHL(2); p0(2); pHR(2)]; %y-coordinates of points on the hips
            zh = [pHL(3); p0(3); pHR(3)]; %z-coordinates of points on the hips
            xt = [p0T(1) ;p0(1)]; %x-coordinates of points on the torso
            yt = [p0T(2) ;p0(2)]; %y-coordinates of points on the torso
            zt = [p0T(3) ;p0(3)]; %z-coordinates of points on the torso
        end
        clf(h); ax=axes('Parent',h);
        if draw_ground
            %         mesh(X_grnd,Y_grnd,Z_grnd,'Parent',ax)
            surface(X_grnd,Y_grnd,Z_grnd,'Parent',ax,'FaceColor','interp')
        end
        if draw_feet
            [p5L, p6L, p7L, p8L, p9L, p5R, p6R, p7R, p8R, p9R] = ATRIAS3D_Foot_Points(q_even(i,:),foot_adjust_params,foot_geo);
            %Line segments for the feet
            xfl_base = [p5L(1) p6L(1) p7L(1) p8L(1);p6L(1) p7L(1) p8L(1) p5L(1)];
            xfl_ankle = [p5L(1) p6L(1) p7L(1) p8L(1);p4L(1) p4L(1) p4L(1) p4L(1)];
            xfr_base = [p5R(1) p6R(1) p7R(1) p8R(1);p6R(1) p7R(1) p8R(1) p5R(1)];
            xfr_ankle = [p5R(1) p6R(1) p7R(1) p8R(1);p4R(1) p4R(1) p4R(1) p4R(1)];
            xfl_toe = [p5L(1) p6L(1);p9L(1) p9L(1)];
            xfr_toe = [p5R(1) p6R(1);p9R(1) p9R(1)];
            
            yfl_base = [p5L(2) p6L(2) p7L(2) p8L(2);p6L(2) p7L(2) p8L(2) p5L(2)];
            yfl_ankle = [p5L(2) p6L(2) p7L(2) p8L(2);p4L(2) p4L(2) p4L(2) p4L(2)];
            yfr_base = [p5R(2) p6R(2) p7R(2) p8R(2);p6R(2) p7R(2) p8R(2) p5R(2)];
            yfr_ankle = [p5R(2) p6R(2) p7R(2) p8R(2);p4R(2) p4R(2) p4R(2) p4R(2)];
            yfl_toe = [p5L(2) p6L(2);p9L(2) p9L(2)];
            yfr_toe = [p5R(2) p6R(2);p9R(2) p9R(2)];
            
            zfl_base = [p5L(3) p6L(3) p7L(3) p8L(3);p6L(3) p7L(3) p8L(3) p5L(3)];
            zfl_ankle = [p5L(3) p6L(3) p7L(3) p8L(3);p4L(3) p4L(3) p4L(3) p4L(3)];
            zfr_base = [p5R(3) p6R(3) p7R(3) p8R(3);p6R(3) p7R(3) p8R(3) p5R(3)];
            zfr_ankle = [p5R(3) p6R(3) p7R(3) p8R(3);p4R(3) p4R(3) p4R(3) p4R(3)];
            zfl_toe = [p5L(3) p6L(3);p9L(3) p9L(3)];
            zfr_toe = [p5R(3) p6R(3);p9R(3) p9R(3)];
            %Draw the feet
            if(1)
                line(xfl_base,yfl_base,zfl_base,'LineWidth',2,'Color','k','Parent',ax);
                line(xfl_ankle,yfl_ankle,zfl_ankle,'LineWidth',2,'Color','k','Parent',ax);
                line(xfr_base,yfr_base,zfr_base,'LineWidth',2,'Color','k','Parent',ax);
                line(xfr_ankle,yfr_ankle,zfr_ankle,'LineWidth',2,'Color','k','Parent',ax);
                line(xfl_toe,yfl_toe,zfl_toe,'LineWidth',2,'Color','k','Parent',ax);
                line(xfr_toe,yfr_toe,zfr_toe,'LineWidth',2,'Color','k','Parent',ax);
            else
                hold on
                plot3(ax,p5L(1),p5L(2),p5L(3),'.', 'MarkerSize',5,'Color','k')
                plot3(ax,p6L(1),p6L(2),p6L(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p7L(1),p7L(2),p7L(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p8L(1),p8L(2),p8L(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p9L(1),p9L(2),p9L(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p5R(1),p5R(2),p5R(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p6R(1),p6R(2),p6R(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p7R(1),p7R(2),p7R(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p8R(1),p8R(2),p8R(3),'.', 'MarkerSize',5,'Color','k');
                plot3(ax,p9R(1),p9R(2),p9R(3),'.', 'MarkerSize',5,'Color','k');
            end
            foot_depth(i,:) = [p5L(3) p6L(3) p7L(3) p8L(3) p9L(3) p5R(3) p6R(3) p7R(3) p8R(3) p9R(3)];
        end
        
        line(xr,yr,zr,'LineWidth',3,'Color','b','Parent',ax);line(xl,yl,zl,'LineWidth',3,'Color','r','Parent',ax);line(xh,yh,zh,'LineWidth',2,'Color','g','Parent',ax);
        line(xt,yt,zt,'LineWidth',3,'Color','g','Parent',ax);
        
        plotcom(pcm,eye(3),'coarse',ax);
        
        axis(ax,[-1 1 -1 1 -0.2-1 1.8+1]);
        nRate = 2;
        %     axis(ax,[-1 1 -1 1 -0.5 1]*nRate);
        xlim(ax,[pcm(1)-1*nRate pcm(1)+1*nRate]);
        ylim(ax,[pcm(2)-1*nRate pcm(2)+1*nRate]);
%         zlim(ax,[pcm(3)-0.2*nRate-1 pcm(3)+1.8*nRate-1]);
        xlabel(ax,'[m]');ylabel(ax, '[m]');zlabel(ax, '[m]');
		if view_angle ~= 7
			setview(ax);
		else
			setview(ax,q_even(i,4)*180/pi);
		end
        grid(ax, 'on');
        
        %Add time readout
        time_string = sprintf('time=%0.2f s',t_even(i));
        text('Units','normalized',...
            'String',time_string,...
            'Position',[.8 1.0],...
            'FontSize',16, ...
            'Parent', ax);
        %text('Units','default')
        
        %Add stance leg readout
        if display_stance_leg
            if leg_even(i) == 0
                stance_string = sprintf('stance=Right');
            else
                stance_string = sprintf('stance=Left');
            end
            text('Units','normalized',...
                'String',stance_string,...
                'Position',[.1 1.0],...
                'FontSize',16, ...
                'Parent',ax);
            %text('Units','default')
        end
        
        if make_film_flag
            F = getframe(gcf);
            %mov = addframe(mov,F);
            writeVideo(mov,F);
        end
        
        drawnow;
        
        %     if slow_motion_flag
        %         pause(.02);
        %     end
        
    end
    % end of for(.)
    
    
    rotate3d on
    
    %Plot foot height
    if(0)
        initial_foot_point_height = foot_depth(1,:)
        final_foot_point_height = foot_depth(end,:)
        figure; plot(t_even,foot_depth(:,1:5)); title('Heights of left foot corner points')
        legend('p5L front left foot point','p6L front right foot point','p7L right heel point','p8L left heel point','p9L toe point')
        xlabel('Time (s)');ylabel('Height wrt ground (m)'); grid on
        figure; plot(t_even,foot_depth(:,6:10)); title('Heights of right foot corner points')
        legend('p5R front left foot point','p6R front right foot point','p7R right heel point','p8R left heel point','p9R toe point')
        xlabel('Time (s)');ylabel('Height wrt ground (m)'); grid on
    end
    
    % Close AVI file.
    if make_film_flag
        %mov = close(mov);
        close(mov);
    end
    % end of if(.)
end