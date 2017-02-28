function [RHAT,t] = kvhshow(ser)
    
    %% Setup and open COM port
    %ser = serial('COM6','BaudRate',921600,'InputBufferSize', 2^30);
    %fopen(ser)
    HDR = hex2dec(['FE'; '81'; 'FF'; '55']);
    D0 = [];
    NT = 1000*3600*0.25;
    RHAT = zeros(3,3,NT);
    t = zeros(NT,1);
    
    %%
    
    Rx = @(t) [1 0 0 ; 0 cos(t) -sin(t); 0 sin(t) cos(t)];
    Ry = @(t) [cos(t) 0 sin(t); 0 1 0 ; -sin(t) 0 cos(t)];
    Rz = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
    Rot = @(q) Rz(q(1))*Ry(q(2))*Rx(q(3)); % Robot to world
    S = @(w) [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
    
    %% Compute initial rotation
    N = 100;
    [A0,sequence] = averageAcceleration(ser, N);
    A0  = A0/norm(A0);
    qy0 = asin(-A0(1));
    qx0 = atan2(A0(2), A0(3));
    Rhat = Rot([0 qy0 qx0]);
    RHAT(:,:,1) = Rhat; t(1) = 0; n = 2;
    tic;
    
    %% Draw dylinder
    [X,Y,Z]=cylinder(0.5);
    Points = [X(:) Y(:) 0.8*(Z(:)-0.5)];
    PointsTri = convhull(X(:), Y(:), Z(:));

    figure(1000); set(gcf, 'Units', 'normalized', 'Position', [0.15 0.05 0.7 0.8]); clf;
    h = trisurf(PointsTri, X(:), Y(:), Z(:), Y(:)); hold on;
    hq = quiver3(-ones(3,1), -ones(3,1), zeros(3,1), [1 0 0]', [0 1 0]', [0 0 1]', 'LineWidth', 3);
    hx = line(NaN, NaN, NaN, 'LineWidth', 2, 'Color', 'k');
    hy = line([0 0], [-1 1], [0 0], 'LineWidth', 2, 'Color', 'k');
    hz = line([0 0], [0 0], [-1 1], 'LineWidth', 2, 'Color', 'k');
    
    axis equal
    set(gca, 'XLim', [-1 1], 'YLim', [-1 1], 'ZLim', [-1 1]);

    missedPackets = 0;
    updateRotation();
    missedPackets = 0;
    ha = annotation('textbox',[0.05 0.07 0.1 0.1], 'String', sprintf('MISSED PACKETS:\n %d', missedPackets));
    
    %% Loop: Read data and update drawing
    try
        while (n<=NT)
            
            updateRotation();
            updateLine(hx, Rhat*[-1 1; 0 0; 0 0]);
            updateLine(hy, Rhat*[0 0; -1 1; 0 0]);
            updateLine(hz, Rhat*[0 0; 0 0; -1 1]);
            set(h, 'Vertices', Points*Rhat');
            set(ha, 'String', sprintf('MISSED PACKETS:\n %d', missedPackets));
            drawnow;
        end
    catch
    end
    
    function updateRotation()
        while (ser.BytesAvailable<36)
            pause(0.001);
        end
        D   = [D0; fread(ser, ser.BytesAvailable)];
        idx = strfind(D', HDR');
        idx = idx(idx+35<=length(D)); % only find full packets
        D0 = D(idx(end)+36:end); % save the rest to parse next time
        
        for j=1:length(idx)
            lastsequence = sequence;
            [DeltaAngle,~,~,sequence] = KVHParsePacket(D(idx(j)+(0:35)));
            dseq = (sequence - lastsequence - 1);
            if (sequence<64 && lastsequence>64)
                dseq = dseq + 128;
            end
            missedPackets = missedPackets + dseq;
            
            K = DeltaAngle/norm(DeltaAngle);
            theta = norm(DeltaAngle);
            Rk = eye(3)*cos(theta) + S(K)*sin(theta) + (1-cos(theta))*(K*K');
            %Rhat = Rk*Rhat;
            Rhat = Rhat*Rk;
            RHAT(:,:,n) = Rhat; t(n)=toc;  n = n+1;
        end
    end
    
end

function [Abar,sequence] = averageAcceleration(ser, N)
    D0  = [];
    HDR = hex2dec(['FE'; '81'; 'FF'; '55'])';
    
    BUF = zeros(1, 36*(N+10), 'uint8');
    head = 0;
    tail = 0;
    
    A = zeros(3,N);
    n = 0;
    
    flushinput(ser);
    while n<N
        if (ser.BytesAvailable)
            D1 = fread(ser, ser.BytesAvailable);
            BUF(head+(1:length(D1))) = D1;
            head = head + length(D1);
        end
        
        if (tail+36 <= head)
            idx = strfind(BUF(tail+1:head), HDR);

            for j=1:min(length(idx), N-n)
                [~,Atmp,~,sequence,~,valid] = KVHParsePacket(double(BUF(tail+idx(j)+(0:35))));
                if ~valid
                    continue
                end
                n = n+1;
                A(:,n) = Atmp;
            end
            tail = tail + idx(j) + 36;
        end
    end
    Abar = mean(A,2);
end

function updateLine(h, D)
    set(h, 'XData', D(1,:)', 'YData', D(2,:)', 'ZData', D(3,:)');
end

