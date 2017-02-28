function [DeltaAngle, Acceleration, Status, Sequence, Temperature, Valid, Rhat, Ahat, qThat] = kvhBatchProcess(D,F0)
    
    if nargin<2, F0=0; end
    
    HDR = [254 129 255 85]; % hex2dec(['FE';'81';'FF';'55']);
    D = D(:)'; % make sure D is a row vector
    idx = strfind(D, HDR);
    idx = idx(idx<length(D)-35); % only find full packets
    
    %%
    N            = length(idx);
    DeltaAngle   = zeros(N,3);
    Acceleration = zeros(N,3);
    Status       = zeros(N,1);
    Sequence     = zeros(N,1);
    Temperature  = zeros(N,1);
    Valid        = zeros(N,1);
    Rhat         = zeros(3,3,N);
    Ahat         = zeros(N,3);
    qThat        = zeros(N,3);
    
    if (N==0)
        return
    end
    
    Rkm1 = zeros(3,3);
    wkm1 = zeros(3,1);
    Akm1 = zeros(3,1);
    Seqkm1 = 0;
    ResetIdx = 200;
    for k=1:N
        Reset = (k <= ResetIdx);
        [DeltaAngle(k,:), Acceleration(k,:), Status(k), Sequence(k), Temperature(k), Valid(k)] = KVHParsePacket(D(idx(k)+(0:35)));
        [Rhat(:,:,k), wk, Ahat(k,:), Seqk] = estimateOrientation(DeltaAngle(k,:)', Acceleration(k,:)', Rkm1, wkm1, Akm1, Status(k)*(Valid(k)==1), Sequence(k), Seqkm1, Reset);
        Rkm1 = Rhat(:,:,k);
        Akm1 = Ahat(k,:)';
        wkm1 = wk;
        Seqkm1 = Seqk;
    end
    
    % Convert from IMU frame to robot frame and compute Euler angles. The
    % yaw angle is set to zero at the time the Reset is released.
    Rz  = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
    RIR = [0 0 1; [-1 -1; 1 -1]/sqrt(2) [0; 0]]';
    qT0 = M_to_ZYX(Rhat(:,:,ResetIdx-1)*RIR);
    R0  = Rz(-qT0(1));
    for k=1:size(Rhat,3)
        Rhat(:,:,k) = R0*Rhat(:,:,k)*RIR;
    end
    qThat = M_to_ZYX(Rhat)';
    
    %% Plot
    N = length(DeltaAngle);
    t = 0.001*(0:N-1)';
    dseq = diff(Sequence);
    dseq(dseq==-127 & Sequence(1:end-1)==127) = 1;
    statusbits = bitget(repmat(Status,1,6), repmat([1 2 3 5 6 7], length(Status), 1));
    
    
    figure(F0+1); clf;
    h(1)=subplot(2,3,1); plot(t,Sequence); title('Sequence');
    h(2)=subplot(2,3,2); plot(t(2:end),dseq); title('diff(Sequence)');
    h(3)=subplot(2,3,3); plot(t,Temperature); title('Temperature (C)');
    h(4)=subplot(2,3,[4 5]); plot(t,statusbits); title('Status'); legend('Gyro X', 'Gyro Y', 'Gyro Z', 'Accel X', 'Accel Y', 'Accel Z');
    h(5)=subplot(2,3,6); plot(t,Valid); title('Valid CRC');
    
    figure(F0+2); clf;
    h(6)=gca; plot(t,Ahat); title('Initial Acceleration'); ylabel('g');
    
    figure(F0+3); clf;
    h(7)=gca; plot(t,qThat*180/pi); title('Euler angles'); ylabel('(deg)'); legend('qzT', 'qyT', 'qxT');
    
    linkaxes(h,'x');
end
