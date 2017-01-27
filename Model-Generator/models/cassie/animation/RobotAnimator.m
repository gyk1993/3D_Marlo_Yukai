classdef RobotAnimator < handle
    %ANIMATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        leg1Color = 'r';
        leg2Color = 'b';
        torsoColor = 'k';
        groundColor = 'g';
		
		axis1;
		axis2;
		axis3;
		axis4;
		views;
		
        FactorTime;
        positions_function;
    end
    
    properties (Access = private)
        figure;

		axisCells;
        ground;

        torso;
        
        l1l;
        l2l;
        l3l;
        l4l;
        l5l;
        l6l;
        l7l;
        l8l;
        l9l;
        l10l;
        l11l;
        l12l;

        l1r;
        l2r;
        l3r;
        l4r;
        l5r;
        l6r;
        l7r;
        l8r;
        l9r;
        l10r;
        l11r;
        l12r;
        
        
        
        text;
        sys;
        video;
        play;
        
        step;
        starting_index;
        next_frame_time;
        
        timer;
        DeltaTime;
        WorldPosition;
        InitialWorldPosition;
        q;
        updateWorldPosition;
        q_all;
        t_all;
    end
    
    methods
        function obj = RobotAnimator(t, q, positions_function, FactorTime, updateWorldPosition ,varargin)
            obj.figure = figure('DeleteFcn', @(~, ~) obj.closefigurefcn());
            obj.axis1 = axes('Parent', obj.figure);
    
            obj.step.q = q;
            obj.step.t = t;
            obj.positions_function = positions_function;
            obj.updateWorldPosition = updateWorldPosition;
            
            if isempty(varargin)
                [terrain.Tx, terrain.Ty] = meshgrid(-10:1:10, -10:1:10);
                terrain.Tz = 0.*terrain.Tx;
            else
                terrain = varargin{1};
            end
            
            figure(obj.figure);
            obj.axisCells = {obj.axis1};
            
            obj.InitialWorldPosition = obj.step.q(1,1:6)';
            obj.WorldPosition = obj.InitialWorldPosition;
            
            % Initialization
            [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
            kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
            fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
            fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = obj.positions_function(obj.step.q(1,:));
            
            % Define Terrain
            obj.ground = surf(terrain.Tx,terrain.Ty,terrain.Tz); hold on;
%             obj.ground = line([-100 100],[0 0]);
%             set(obj.ground,'LineWidth',3,'Color',obj.groundColor);

            scale = 10;
            [x,y,z] = sphere(10); x = x./scale; y = y./scale; z = z./scale;
            obj.torso = surf(x+pelvis(1),y+pelvis(2),z+pelvis(3), zeros([size(x,1),size(x,2),3]));
            
            axis(obj.axisCells{1},[pelvis(1)-1, pelvis(1)+1, pelvis(2)-1, pelvis(2)+1,pelvis(3)-1.5, pelvis(3)+0.5]);
            
            obj.l1l = line([pelvis(1) fixedleft(1)],[pelvis(2) fixedleft(2)],[pelvis(3) fixedleft(3)]);
            obj.l2l = line([fixedleft(1) hipabductionleft(1)],[fixedleft(2) hipabductionleft(2)],[hipabductionleft(3) fixedleft(3)]);
            obj.l3l = line([hipabductionleft(1) hiprotationleft(1)],[hipabductionleft(2) hiprotationleft(2)],[hipabductionleft(3) hiprotationleft(3)]);
            obj.l4l = line([hiprotationleft(1) hipflexionleft(1)],[hiprotationleft(2) hipflexionleft(2)],[hiprotationleft(3) hipflexionleft(3)]);
            obj.l5l = line([hipflexionleft(1) kneejointleft(1)],[hipflexionleft(2) kneejointleft(2)],[hipflexionleft(3) kneejointleft(3)]);
            obj.l6l = line([kneejointleft(1) fixedkneetoshinleft(1)],[kneejointleft(2) fixedkneetoshinleft(2)],[kneejointleft(3) fixedkneetoshinleft(3)]);
            obj.l7l = line([fixedkneetoshinleft(1) anklejointleft(1)],[fixedkneetoshinleft(2) anklejointleft(2)],[fixedkneetoshinleft(3) anklejointleft(3)]);
            obj.l8l = line([anklejointleft(1) toejointleft(1)],[anklejointleft(2) toejointleft(2)],[anklejointleft(3) toejointleft(3)]);
            obj.l9l = line([toejointleft(1) toebottomleft(1)],[toejointleft(2) toebottomleft(2)],[toejointleft(3) toebottomleft(3)]);
            obj.l10l = line([toejointleft(1) toebottomleftback(1)],[toejointleft(2) toebottomleftback(2)],[toejointleft(3) toebottomleftback(3)]);
            obj.l11l = line([toejointleft(1) toebottomleftfront(1)],[toejointleft(2) toebottomleftfront(2)],[toejointleft(3) toebottomleftfront(3)]);
            obj.l12l = line([toebottomleftback(1) toebottomleftfront(1)],[toebottomleftback(2) toebottomleftfront(2)],[toebottomleftback(3) toebottomleftfront(3)]);
            
            obj.l1r = line([pelvis(1) fixedright(1)],[pelvis(2) fixedright(2)],[pelvis(3) fixedright(3)]);
            obj.l2r = line([fixedright(1) hipabductionright(1)],[fixedright(2) hipabductionright(2)],[fixedright(3) hipabductionright(3)]);
            obj.l3r = line([hipabductionright(1) hiprotationright(1)],[hipabductionright(2) hiprotationright(2)],[hipabductionright(3) hiprotationright(3)]);
            obj.l4r = line([hiprotationright(1) hipflexionright(1)],[hiprotationright(2) hipflexionright(2)],[hiprotationright(3) hipflexionright(3)]);
            obj.l5r = line([hipflexionright(1) kneejointright(1)],[hipflexionright(2) kneejointright(2)],[hipflexionright(3) kneejointright(3)]);
            obj.l6r = line([kneejointright(1) fixedkneetoshinright(1)],[kneejointright(2) fixedkneetoshinright(2)],[kneejointright(3) fixedkneetoshinright(3)]);
            obj.l7r = line([fixedkneetoshinright(1) anklejointright(1)],[fixedkneetoshinright(2) anklejointright(2)],[fixedkneetoshinright(3) anklejointright(3)]);
            obj.l8r = line([anklejointright(1) toejointright(1)],[anklejointright(2) toejointright(2)],[anklejointright(3) toejointright(3)]);
            obj.l9r = line([toejointright(1) toebottomright(1)],[toejointright(2) toebottomright(2)],[toejointright(3) toebottomright(3)]);
            obj.l10r = line([toejointright(1) toebottomrightback(1)],[toejointright(2) toebottomrightback(2)],[toejointright(3) toebottomrightback(3)]);
            obj.l11r = line([toejointright(1) toebottomrightfront(1)],[toejointright(2) toebottomrightfront(2)],[toejointright(3) toebottomrightfront(3)]);
            obj.l12r = line([toebottomrightback(1) toebottomrightfront(1)],[toebottomrightback(2) toebottomrightfront(2)],[toebottomrightback(3) toebottomrightfront(3)]);

            
            set(obj.l1l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l2l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l3l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l4l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l5l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l6l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l7l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l8l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l9l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l10l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l11l,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.l12l,'LineWidth',3,'Color',obj.leg1Color);

            set(obj.l1r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l2r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l3r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l4r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l5r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l6r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l7r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l8r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l9r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l10r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l11r,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.l12r,'LineWidth',3,'Color',obj.leg2Color);

            
            obj.starting_index = 1;
            obj.next_frame_time = 0;
            obj.FactorTime = FactorTime;
            obj.DeltaTime = 0.04; % 40 ms
            obj.q_all = obj.step.q(1,:);
            obj.t_all = 0;
            
            obj.timer = timer; %#ok<CPROP>
            obj.timer.Period = obj.DeltaTime;
            obj.timer.ExecutionMode = 'fixedDelay';
            obj.timer.TimerFcn = @(~, ~) obj.Animate();
        end
        
        function Play(obj)
            
            votype = 'VideoWriter';
            vo = VideoWriter('Video', 'MPEG-4');
            set(vo, 'FrameRate', 30);
            open(vo);
            
            while true
                if ~obj.Animate()
                    break;
                end
                F = getframe(gcf);
                writeVideo(vo, F);
            end
            
            close(vo);
            
            if ishandle(obj.figure)
                start(obj.timer);
            end
        end
        
        function Pause(obj)
            stop(obj.timer);
        end
        
        function flag = IsRunning(obj)
            flag = strcmp(obj.timer.Running, 'on');
        end
        
        function [q_all, t_all] = ReturnTrajectory(obj)
            q_all = obj.q_all;
            t_all = obj.t_all;
        end
                    
        function flag = Animate(obj)
            flag = true;
                            
            Rz = @(th) [cos(th), -sin(th), 0; sin(th), cos(th), 0; 0,0,1];
            Ry = @(th) [cos(th), 0, sin(th); 0, 1, 0; -sin(th), 0, cos(th)];
            Rx = @(th) [1,0,0; 0, cos(th), -sin(th); 0, sin(th), cos(th)];
                
            n = length(obj.step.t);
            for i = obj.starting_index:n
                if obj.next_frame_time > obj.step.t(i)
                    continue;
                end

                obj.q = obj.step.q(i,:)';
                % Transformation from new initial frame to original one
                r1 = obj.WorldPosition(1:3) - obj.InitialWorldPosition(1:3);
                th1 = obj.WorldPosition(4:6) - obj.InitialWorldPosition(4:6);
                H1 = [Rx(th1(1))*Ry(th1(2))*Rz(th1(3)), r1; 0,0,0,1];
                % Transform from current position to new initial frame
                r2 = obj.q(1:3) - obj.InitialWorldPosition(1:3);
                th2 = obj.q(4:6) - obj.InitialWorldPosition(4:6);
                H2 = [Rx(th2(1))*Ry(th2(2))*Rz(th2(3)), r2; 0,0,0,1];
                % Transformation from current position to original frame
                H = H1*H2;
                T = H(1:3,4);
                roll = atan2(-H(2,3),H(3,3));
                pitch = asin(H(1,3));
                yaw = atan2(-H(1,2),H(1,1));
                
                obj.q(1:6) = obj.InitialWorldPosition(1:6) + [T;roll;pitch;yaw]; 
                
                obj.q_all = vertcat(obj.q_all, obj.q');
                obj.t_all = vertcat(obj.t_all, obj.step.t(i));
                
                % Update Positions
                [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
                  kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
                  fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
                  fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = obj.positions_function(obj.q);
                
                axis(obj.axisCells{1},[pelvis(1)-1, pelvis(1)+1, pelvis(2)-1, pelvis(2)+1,pelvis(3)-1.5, pelvis(3)+0.5]);
                % 					view(obj.views{j})
                
                scale = 10;
                [x,y,z] = sphere(10); x = x./scale; y = y./scale; z = z./scale;
                set(obj.torso,'XData',x+pelvis(1),'YData',y+pelvis(2),'ZData',z+pelvis(3));
               
                set(obj.l1l,'XData',[pelvis(1) fixedleft(1)],'YData',[pelvis(2) fixedleft(2)],'ZData',[pelvis(3) fixedleft(3)]);
                set(obj.l2l,'XData',[fixedleft(1) hipabductionleft(1)],'YData',[fixedleft(2) hipabductionleft(2)],'ZData',[hipabductionleft(3) fixedleft(3)]);
                set(obj.l3l,'XData',[hipabductionleft(1) hiprotationleft(1)],'YData',[hipabductionleft(2) hiprotationleft(2)],'ZData',[hipabductionleft(3) hiprotationleft(3)]);
                set(obj.l4l,'XData',[hiprotationleft(1) hipflexionleft(1)],'YData',[hiprotationleft(2) hipflexionleft(2)],'ZData',[hiprotationleft(3) hipflexionleft(3)]);
                set(obj.l5l,'XData',[hipflexionleft(1) kneejointleft(1)],'YData',[hipflexionleft(2) kneejointleft(2)],'ZData',[hipflexionleft(3) kneejointleft(3)]);
                set(obj.l6l,'XData',[kneejointleft(1) fixedkneetoshinleft(1)],'YData',[kneejointleft(2) fixedkneetoshinleft(2)],'ZData',[kneejointleft(3) fixedkneetoshinleft(3)]);
                set(obj.l7l,'XData',[fixedkneetoshinleft(1) anklejointleft(1)],'YData',[fixedkneetoshinleft(2) anklejointleft(2)],'ZData',[fixedkneetoshinleft(3) anklejointleft(3)]);
                set(obj.l8l,'XData',[anklejointleft(1) toejointleft(1)],'YData',[anklejointleft(2) toejointleft(2)],'ZData',[anklejointleft(3) toejointleft(3)]);
                set(obj.l9l,'XData',[toejointleft(1) toebottomleft(1)],'YData',[toejointleft(2) toebottomleft(2)],'ZData',[toejointleft(3) toebottomleft(3)]);
                set(obj.l10l,'XData',[toejointleft(1) toebottomleftback(1)],'YData',[toejointleft(2) toebottomleftback(2)],'ZData',[toejointleft(3) toebottomleftback(3)]);
                set(obj.l11l,'XData',[toejointleft(1) toebottomleftfront(1)],'YData',[toejointleft(2) toebottomleftfront(2)],'ZData',[toejointleft(3) toebottomleftfront(3)]);
                set(obj.l12l,'XData',[toebottomleftback(1) toebottomleftfront(1)],'YData',[toebottomleftback(2) toebottomleftfront(2)],'ZData',[toebottomleftback(3) toebottomleftfront(3)]);

                set(obj.l1r,'XData',[pelvis(1) fixedright(1)],'YData',[pelvis(2) fixedright(2)],'ZData',[pelvis(3) fixedright(3)]);
                set(obj.l2r,'XData',[fixedright(1) hipabductionright(1)],'YData',[fixedright(2) hipabductionright(2)],'ZData',[fixedright(3) hipabductionright(3)]);
                set(obj.l3r,'XData',[hipabductionright(1) hiprotationright(1)],'YData',[hipabductionright(2) hiprotationright(2)],'ZData',[hipabductionright(3) hiprotationright(3)]);
                set(obj.l4r,'XData',[hiprotationright(1) hipflexionright(1)],'YData',[hiprotationright(2) hipflexionright(2)],'ZData',[hiprotationright(3) hipflexionright(3)]);
                set(obj.l5r,'XData',[hipflexionright(1) kneejointright(1)],'YData',[hipflexionright(2) kneejointright(2)],'ZData',[hipflexionright(3) kneejointright(3)]);
                set(obj.l6r,'XData',[kneejointright(1) fixedkneetoshinright(1)],'YData',[kneejointright(2) fixedkneetoshinright(2)],'ZData',[kneejointright(3) fixedkneetoshinright(3)]);
                set(obj.l7r,'XData',[fixedkneetoshinright(1) anklejointright(1)],'YData',[fixedkneetoshinright(2) anklejointright(2)],'ZData',[fixedkneetoshinright(3) anklejointright(3)]);
                set(obj.l8r,'XData',[anklejointright(1) toejointright(1)],'YData',[anklejointright(2) toejointright(2)],'ZData',[anklejointright(3) toejointright(3)]);
                set(obj.l9r,'XData',[toejointright(1) toebottomright(1)],'YData',[toejointright(2) toebottomright(2)],'ZData',[toejointright(3) toebottomright(3)]);
                set(obj.l10r,'XData',[toejointright(1) toebottomrightback(1)],'YData',[toejointright(2) toebottomrightback(2)],'ZData',[toejointright(3) toebottomrightback(3)]);
                set(obj.l11r,'XData',[toejointright(1) toebottomrightfront(1)],'YData',[toejointright(2) toebottomrightfront(2)],'ZData',[toejointright(3) toebottomrightfront(3)]);
                set(obj.l12r,'XData',[toebottomrightback(1) toebottomrightfront(1)],'YData',[toebottomrightback(2) toebottomrightfront(2)],'ZData',[toebottomrightback(3) toebottomrightfront(3)]);
                
                delete(obj.text);
                obj.text = text(pelvis(1),pelvis(2),pelvis(3)+0.5,['t = ',sprintf('%.2f',obj.step.t(i))]);
                obj.text.FontSize = 14;
                obj.text.FontWeight = 'Bold';
                obj.text.Color = [0,0,0];
                %  set(obj.text);
                
                drawnow;
                
                obj.starting_index = (i + 1);
                obj.next_frame_time = obj.next_frame_time + obj.DeltaTime*obj.FactorTime;
                return;
            end
            
            if obj.starting_index == 1 % Prevent an infinite recurrsion
                return;
            end
            
            % Could not find a frame...
            obj.starting_index = 1;
            % Offset absolute coordinates
            if obj.updateWorldPosition
                obj.WorldPosition = obj.q(1:6);
                obj.next_frame_time = obj.step.t(end);
                obj.step.t = obj.step.t + repmat(obj.step.t(end)-obj.step.t(1),size(obj.step.t,1),size(obj.step.t,2));
            else
                obj.next_frame_time = 0;
            end
            obj.Animate(); % Try again (looping mechanism)
        end
        
        function delete(obj)
            if ishandle(obj.figure)
                close(obj.figure);
            end
            
            stop(obj.timer);
            delete(obj.timer);
        end

        % Events
        function closefigurefcn(obj)
            obj.play = false;
            obj.Pause();
            pause(1);
        end
    end
end
