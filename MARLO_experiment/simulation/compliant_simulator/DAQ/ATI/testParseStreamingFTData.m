

load('FTTest08-log01','log');
AllSerialIn = uint16(log.SerialIn);
idx = 228;
N = size(log.SerialIn,1);

Cal=deserializeFTCalibrationBus(log.Calibration(end,:));

%%
SerialBuffer = zeros(512,1,'uint16');
SerialBufferEnd = uint16(0);

GaugeCount  = zeros(N,1);
Gauge       = zeros(6,8,N,'int16');
GaugeStatus = zeros(N,8);

for k = idx:size(log.SerialIn,1)
    SerialIn = AllSerialIn(k,:).';
    [GaugeCount(k), Gauge(:,:,k), SerialBuffer, SerialBufferEnd, GaugeStatus(k,:)] = parseStreamingFTData(SerialIn, SerialBuffer, SerialBufferEnd);
end
%%
CalMatrix = diag([Cal.CountsPerForce, Cal.CountsPerForce Cal.CountsPerForce Cal.CountsPerTorque Cal.CountsPerTorque Cal.CountsPerTorque]) \ Cal.BasicMatrix;
Offset = double(Gauge(:,:,1000));
FT = zeros(6,8,N);

for k=1:N
    FT(:,:,k) = CalMatrix * (double(Gauge(:,:,k)) - Offset);
end

%%
figure(1); clf; plot([GaugeCount*13 AllSerialIn(:,1)])
figure(2); clf; plot(GaugeStatus)

figure(3); clf; plot(squeeze(FT(:,1,:)).');% hold on; plot(log.FT(:,1:6), ':k')
