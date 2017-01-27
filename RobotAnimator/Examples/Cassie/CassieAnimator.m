classdef CassieAnimator < Animator.AbstractAnimator
    properties
        leg1Color = 'r';
        leg2Color = 'b';
        torsoColor = 'k';
        groundColor = 'g';
		
        positions_function;
    end
    
    properties (Access = private)
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
        
        starting_index;
        next_frame_time;
        
        H;
        
        q_all;
        t_all;
    end
    
    properties
        updateWorldPosition logical
    end
    
    methods
        function obj = CassieAnimator(t, q, positions_function, varargin)
            obj = obj@Animator.AbstractAnimator(); % Calling super constructor
    
            obj.q_all = q;
            obj.t_all = t;
            
            obj.startTime = t(1);
            obj.currentTime = obj.startTime;
            obj.endTime = t(end);
            
            obj.positions_function = positions_function;
            obj.updateWorldPosition = false;
            
            if isempty(varargin)
                [terrain.Tx, terrain.Ty] = meshgrid(-10:1:10, -10:1:10);
                terrain.Tz = 0.*terrain.Tx;
            else
                terrain = varargin{1};
            end
            
            Rz = @(th) [cos(th), -sin(th), 0; sin(th), cos(th), 0; 0,0,1];
            Ry = @(th) [cos(th), 0, sin(th); 0, 1, 0; -sin(th), 0, cos(th)];
            Rx = @(th) [1,0,0; 0, cos(th), -sin(th); 0, sin(th), cos(th)];
            
            r = obj.q_all(1:3, end) - obj.q_all(1:3, 1);
            th = obj.q_all(4:6, end) - obj.q_all(4:6, 1);
            obj.H = [Rx(th(1))*Ry(th(2))*Rz(th(3)), r; 0,0,0,1];
            
            % Initialization
            [pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
            kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
            fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
            fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = obj.positions_function(obj.q_all(1,:));
            
            % Define Terrain
            obj.ground = surf(terrain.Tx,terrain.Ty,terrain.Tz); hold on;

            scale = 10;
            [x,y,z] = sphere(10); x = x./scale; y = y./scale; z = z./scale;
            obj.torso = surf(x+pelvis(1),y+pelvis(2),z+pelvis(3), zeros([size(x,1),size(x,2),3]));
            
            axis(obj.axs,[pelvis(1)-1, pelvis(1)+1, pelvis(2)-1, pelvis(2)+1,pelvis(3)-1.5, pelvis(3)+0.5]);
            
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
        end
        
        function Draw(obj, t, x)
            q = x;                     

            % Update Positions
            [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
              kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
              fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
              fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = obj.positions_function(q);

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
            obj.text = text(pelvis(1),pelvis(2),pelvis(3)+0.5,['t = ',sprintf('%.2f',t)]);
            obj.text.FontSize = 14;
            obj.text.FontWeight = 'Bold';
            obj.text.Color = [0,0,0];
            %  set(obj.text);

            drawnow;
        end
        
        function x = GetData(obj, t)
            t_start = obj.t_all(1);
            t_end = obj.t_all(end);
            delta_t = t_end - t_start;
            
            val = 0;
            
            if t < t_start || t > t_end
                val = floor((t - t_start) / delta_t);
                t = t - val * delta_t;
            end
            
            if t < t_start
                t = t_start;
            elseif t > t_end
                t = t_end;
            end
            
            n = length(obj.t_all);
            x = obj.q_all(:, 1); % Default
            
            a = 1;
            b = n;
            
            while (a <= b)
                c = floor((a + b) / 2);
                
                if t < obj.t_all(c)
                    x = obj.q_all(:, c);
                    b = c - 1;
                elseif t > obj.t_all(c)
                    a = c + 1;
                else
                    x = obj.q_all(:, c);
                    break;
                end
            end
            
            delta_q = obj.q_all(1:6, end) - obj.q_all(1:6, 1);
            
            %T = obj.H(1:3,4);
            %roll = atan2(-obj.H(2,3),obj.H(3,3));
            %pitch = asin(obj.H(1,3));
            %yaw = atan2(-obj.H(1,2),obj.H(1,1));
            
            if obj.updateWorldPosition
                Rz = @(th) [cos(th), -sin(th), 0; sin(th), cos(th), 0; 0,0,1];
                Ry = @(th) [cos(th), 0, sin(th); 0, 1, 0; -sin(th), 0, cos(th)];
                Rx = @(th) [1,0,0; 0, cos(th), -sin(th); 0, sin(th), cos(th)];
                
                x_orig_init = obj.q_all(1:6, 1);
                x_current_init = obj.q_all(1:6, 1);
                if val > 0
                    for i = 1:val
                        x_end = obj.q_all(1:6, end);
                        
                        r1 = x_current_init(1:3) - x_orig_init(1:3);
                        th1 = x_current_init(4:6) - x_orig_init(4:6);
                        H1 = [Rx(th1(1))*Ry(th1(2))*Rz(th1(3)), r1; 0,0,0,1];
                        
                        r2 = x_end(1:3) - x_orig_init(1:3);
                        th2 = x_end(4:6) - x_orig_init(4:6);
                        H2 = [Rx(th2(1))*Ry(th2(2))*Rz(th2(3)), r2; 0,0,0,1];
                        
                        H = H1*H2;
                        T = H(1:3,4);
                        roll = atan2(-H(2,3),H(3,3));
                        pitch = asin(H(1,3));
                        yaw = atan2(-H(1,2),H(1,1));
                        
                        x_current_init = x_orig_init(1:6) + [T;roll;pitch;yaw];   
                    end
                    
                    x_current = x(1:6);
                        
                    r1 = x_current_init(1:3) - x_orig_init(1:3);
                    th1 = x_current_init(4:6) - x_orig_init(4:6);
                    H1 = [Rx(th1(1))*Ry(th1(2))*Rz(th1(3)), r1; 0,0,0,1];

                    r2 = x_current(1:3) - x_orig_init(1:3);
                    th2 = x_current(4:6) - x_orig_init(4:6);
                    H2 = [Rx(th2(1))*Ry(th2(2))*Rz(th2(3)), r2; 0,0,0,1];

                    H = H1*H2;
                    T = H(1:3,4);
                    roll = atan2(-H(2,3),H(3,3));
                    pitch = asin(H(1,3));
                    yaw = atan2(-H(1,2),H(1,1));

                    x(1:6) = x_orig_init(1:6) + [T;roll;pitch;yaw];   
                end
            end
        end
        
        function [center, radius, yaw] = GetCenter(obj, t, x)
            q = x;
            
            % Update Positions
            [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
              kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
              fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
              fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = obj.positions_function(q);
            
            center = pelvis;
            radius = 1.5;
            yaw = rad2deg(q(6));
        end
    end
end
