function [Valid, T, Rhat, qThat] = microstrainBatchProcess(D,F0)
    
    if nargin<2, F0=0; end
    
    HDR = [223]; % hex2dec('DF');
    D = D(:)'; % make sure D is a row vector
    idx = strfind(D, HDR);
    idx = idx(idx<length(D)-35); % only find full packets
    
    %%
    N             = length(idx);
    Q             = zeros(N,4);
    DeltaAngle    = zeros(N,3);
    DeltaVelocity = zeros(N,3);
    T             = zeros(N,1);
    Valid         = zeros(N,1);
    Rhat          = zeros(3,3,N);
    qThat         = zeros(N,3);
     
    if (N==0)
        return
    end
    
    % CMD = hex2dec('DF'); % Quaternion  
    CMD = hex2dec('C3'); % DeltaAngle and DeltaVelocity 
    
    
    switch (CMD)
        case 223 % hex2dec('DF'); (Quaternion)
            for k=1:N
                [Valid(k), T(k), Q(k,:)] = microstrainParsePacket(D(idx(k)+(0:22)), CMD);
                Rhat(:,:,k) = convertQtoRotation(Q(k,:));
            end
            Q = Q(Valid==1,:);
            
        case 195 % hex2dec('C3'); (DeltaAngle and DeltaVelocity)
            for k=1:N
                [Valid(k), T(k), DeltaAngle(k,:), DeltaVelocity(k,:)] = microstrainParsePacket(D(idx(k)+(0:30)), CMD);
                [Rhat(:,:,k), wk, Ahat(k,:), Seqk] = estimateOrientation(DeltaAngle(k,:)', Acceleration(k,:)', Rkm1, wkm1, Akm1, Status(k)*(Valid(k)==1), Sequence(k), Seqkm1, Reset);
                Rkm1 = Rhat(:,:,k);
                Akm1 = Ahat(k,:)';
                wkm1 = wk;
                Seqkm1 = Seqk;
            end
            
    end

    
    T = T(Valid==1);
    
    Rhat = Rhat(:,:,Valid==1);
    
    % Convert from IMU frame to robot frame and compute Euler angles. The
    % yaw angle is set to zero at the time the Reset is released.
    Rz  = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
    RIR = eye(3); %[0 0 1; [-1 -1; 1 -1]/sqrt(2) [0; 0]]';
    qT0 = M_to_ZYX(Rhat(:,:,find(Valid,1,'first'))*RIR);
    R0  = Rz(-qT0(1));
    for k=1:size(Rhat,3)
        Rhat(:,:,k) = R0*Rhat(:,:,k)*RIR;
    end
    qThat = M_to_ZYX(Rhat)';
    
    %% Plot
    
    h = [];
    figure(F0+3); clf;
    h(1)=gca; plot(T,qThat*180/pi); title('Euler angles'); ylabel('(deg)'); legend('qzT', 'qyT', 'qxT');
    
    linkaxes(h,'x');
end
