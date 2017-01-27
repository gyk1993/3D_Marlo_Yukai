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
        pHR;
        pHL;
        pHT;
        text;
        sys;
        video;
        play;
        
        step;
        starting_index;
        next_frame_time;
        
        timer;
        DeltaTime;
    end
    
    methods
        function obj = RobotAnimator(t, q, positions_function, FactorTime, varargin)
            obj.figure = figure('DeleteFcn', @(~, ~) obj.closefigurefcn());
            obj.axis1 = axes('Parent', obj.figure);
    
            obj.step.q = q;
            obj.step.t = t;
            obj.positions_function = positions_function;
            
            if isempty(varargin)
                [terrain.Tx, terrain.Ty] = meshgrid(-10:1:10, -10:1:10);
                terrain.Tz = 0.*terrain.Tx;
            else
                terrain = varargin{1};
            end
            
            figure(obj.figure);
            obj.axisCells = {obj.axis1};
            
            % Initialization
            [pH, pT, pR, pL] = obj.positions_function(obj.step.q(1,:));
            axis(obj.axisCells{1},[pH(1)-1, pH(1)+1, pH(2)-1, pH(2)+1]);
            
            % Define Terrain
%             obj.ground = surf(terrain.Tx,terrain.Ty,terrain.Tz);
            obj.ground = line([-100 100],[0 0]);
            set(obj.ground,'LineWidth',3,'Color',obj.groundColor);

            obj.pHR = line([pR(1) pH(1)],[pR(2) pH(2)]);
            obj.pHL = line([pL(1) pH(1)],[pL(2) pH(2)]);
            obj.pHT = line([pT(1) pH(1)],[pT(2) pH(2)]);
            
            set(obj.pHR,'LineWidth',3,'Color',obj.leg1Color);
            set(obj.pHL,'LineWidth',3,'Color',obj.leg2Color);
            set(obj.pHT,'LineWidth',3,'Color',obj.torsoColor);
            
            
            obj.starting_index = 1;
            obj.next_frame_time = 0;
            obj.FactorTime = FactorTime;
            obj.DeltaTime = 0.04; % 40 ms
            
            obj.timer = timer; %#ok<CPROP>
            obj.timer.Period = obj.DeltaTime;
            obj.timer.ExecutionMode = 'fixedDelay';
            obj.timer.TimerFcn = @(~, ~) obj.Animate();
        end
        
        function Play(obj)
            
%             votype = 'VideoWriter';
%             vo = VideoWriter('Video', 'MPEG-4');
%             set(vo, 'FrameRate', 30);
%             open(vo);
%             
%             while true
%                 if ~obj.Animate()
%                     break;
%                 end
%                 F = getframe(gcf);
%                 writeVideo(vo, F);
%             end
%             
%             close(vo);
            
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
        
        function flag = Animate(obj)
            flag = true;
            n = length(obj.step.t);
            for i = obj.starting_index:n
                if obj.next_frame_time > obj.step.t(i)
                    continue;
				end

                for j=1:length(obj.axisCells)
                    % Update Positions
                    [pH, pT, pR, pL] = obj.positions_function(obj.step.q(i,:));
                    axis(obj.axisCells{j},[pH(1)-1, pH(1)+1, pH(2)-1, pH(2)+1]);
                    % 					view(obj.views{j})
                    
                                  
                    set(obj.pHR,'XData',[pR(1) pH(1)],'YData',[pR(2) pH(2)]);
                    set(obj.pHL,'XData',[pL(1) pH(1)],'YData',[pL(2) pH(2)]);
                    set(obj.pHT,'XData',[pT(1) pH(1)],'YData',[pT(2) pH(2)]);
                    
%                     delete(obj.text);
%                     obj.text = text(p0(1)+.2,p0(2)+0.75,1.75,{['t = ',sprintf('%.2f',obj.step.t(i))],'Average vcm' ,['x: ', sprintf('%.2f',obj.step.vcm_average(i,1)), ' m/s'],['y: ', sprintf('%.2f',obj.step.vcm_average(i,2)), ' m/s']});
                    obj.text.FontSize = 14;
                    obj.text.FontWeight = 'Bold';
                    obj.text.Color = [0,0,0];
                    %  set(obj.text);
                    
                    drawnow;
                end
				
                obj.starting_index = (i + 1);
                obj.next_frame_time = obj.next_frame_time + obj.DeltaTime*obj.FactorTime;
                return;
            end
            
            if obj.starting_index == 1 % Prevent an infinite recurrsion
                return;
            end
            
            % Could not find a frame...
            obj.starting_index = 1;
            obj.next_frame_time = 0;
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

function step = CombineSteps(steps)
    count = 0;
    
    for i = 1:numel(steps)
        s = steps{i};
        count = count + length(s.t);
    end
    
    step.t = zeros(count, 1);
    step.q = zeros(count, size(steps{1}.q, 2));
    
    index = 1;
    for i = 1:numel(steps)
        s = steps{i};
        
        for j = 1:length(s.t)
            step.t(index,:) = s.t(j);
            step.q(index,:) = s.q(j,:);
            index = index + 1;
        end
    end
end
