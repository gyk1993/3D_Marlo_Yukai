function FootPoints = FootModel(SelectFootModel)
    
    if nargin<1
        SelectFootModel = 'Kevin';
    end
    
    Rx = @(t) [1 0 0 ; 0 cos(t) -sin(t); 0 sin(t) cos(t)];
    Ry = @(t) [cos(t) 0 sin(t); 0 1 0 ; -sin(t) 0 cos(t)];
    Rz = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
    
    switch SelectFootModel
        case 'Kevin'
            % Specify foot adjustment parameters and foot geometry
            % Foot adjustment angles for the right foot. We assume that any
            % adjustment about Z-axis or Y-axis is symmetric (i.e. mirror) for the left.
            % These parameters are given as angles (in radians) of rotation of the foot
            % with respect to the frame attached to the right shin axis (after it has been
            % rotated by pi around the x-axis so that z is positive pointing up the shin)
            footX_param = 14.0*pi/180; %19*pi/180; %19 seems to match the experimental data
            footY_param = 0;
            footZ_param = -14*pi/180;
            
            %Foot geometry, i.e. physical dimensions of the foot (in meters)
            %full prosthetic foot with toe
            foot_length = 0.15; %0.26; %length of the foot from heel to ground contact at front
            length_behind_heel = 0.03; %.07; %distance from the back of the heel to the ankle
            heel_width = .02; % width of the foot at the heel
            toe_width = .04; % width of the foot at the to ground contact point in front
            y_dist_ankle_to_toe = 0.135; %0.21; %the y distance from the ankle point to the toe, along the foot midline
            z_dist_ankle_to_toe = 0.05; %0.008; %the height of the toe above the ground, when the foot is flat on the ground
            
            [~, FootPoints] = getFootPoints(0, foot_length, length_behind_heel, heel_width, toe_width, y_dist_ankle_to_toe, z_dist_ankle_to_toe, footX_param, footY_param, footZ_param);
            zd = 0;
            
        case 'Ellipsoidal'
            n = 3;
            psi   = 17.5*pi/180; % rotation around z-axis (points *down* the shin)
            phi   = 0*pi/180;    % rotation around y-axis (points to the right)
            theta = 16*pi/180;   % rotation around z-xais
            wid = 0.05;
            len = 0.20;
            zr = 0.005;
            zd = 0.07; % "height"
            [X,Y,Z] = ellipsoid(0, -0.25*len, 0, wid/2, len/2, zr, 2*n);
            X = X(n+1:end,:);
            Y = Y(n+1:end,:);
            Z = Z(n+1:end,:);
            FootPoints = Rz(psi)*Ry(phi)*Rx(theta)*unique([X(:) Y(:) Z(:)], 'rows')';
            FootPoints(3,:) = FootPoints(3,:) + zd;
            
        case 'TinyRound'
            n = 3;
            r = 0.01;
            e = 0.2;
            zd = 0;%0.07;
            [X,Y,Z] = sphere(2*n);
            X = r*X(n+1:end,:);
            Y = r*Y(n+1:end,:);
            Z = e*r*Z(n+1:end,:);
            FootPoints = unique([X(:) Y(:) Z(:)], 'rows')';
            FootPoints(3,:) = FootPoints(3,:) + zd;
            
        case 'SmallFlatCircle'
            n = 8;
            r = 0.02;
            zd = 0.07;
            t = linspace(0, 2*pi, n+1); t(end) = [];
            FootPoints = [r*cos(t); r*sin(t); 0*t-zd];
            
        case 'Point'
            zd = 0;
            FootPoints = [0; 0; 0];
            
        case 'Toroidal' % For now, just a ring of points
            n = 20;
            r = 0.04;
            zd = 0.0;
            t = linspace(0, 2*pi, n+1); t(end) = [];
            FootPoints = Rx(8*pi/180) * [r*cos(t); r*sin(t); 0*t-zd];
            
    end
    
    if 0
        try
            % Visualize
            % For convenience, rotate 180 degrees around the x-axis so that
            % z is up. This is done by negating the y and z components.
            h=figure;
            % Check for coplanarity and collinearity
            FP1 = bsxfun(@minus, FootPoints, FootPoints(:,1));
            if rank(FP1)==3
                trisurf(convhull(FootPoints'), FootPoints(1,:)', -FootPoints(2,:)', -FootPoints(3,:)', 'FaceColor', 'interp'); axis equal
            elseif rank(FP1)==2
                [U,S,V] = svd(FootPoints', 'econ');
                idx = convhull(U*S(:,1:2));
                patch(FootPoints(1,idx)', -FootPoints(2,idx)', -FootPoints(3,idx)', 'FaceColor', 'interp'); axis equal
            else
                line(FootPoints(1,:)', -FootPoints(2,:)', -FootPoints(3,:)', 'Marker', 'o', 'MarkerFaceColor', 'b');
            end
            % Draw the bottom 5cm of the leg bar
            [X,Y,Z]=cylinder(0.01);
            hold on; surf(X,Y,0.05*Z-zd)
        catch err
            %err.getReport()
            close(h);
        end
    end
end
