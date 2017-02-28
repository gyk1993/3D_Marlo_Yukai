%% Sample Time
Ts = 0.0005;
TsKVH = 0.001;
TsMicrostrain = 0.002;
TsCAN = 0.001;

%% Calibration
defineRobotCalibrationBus();
Calibration = getCalibrationParams2();

%% Derivative Estimation Filters
% FiltSys = getDerivFilter(N, M, m0, dt)
% N = degree of polynomial to fit
% M = size of window (filter of order M-1)
% m0 = tap at which derivative is computed
% dt = sample time

std_w = 1/Ts^2;
R = std_w^2/10;    % state noise (default)
Q = Ts/100;        % output noise (default)
% Q = 1.5e3;    % filter out more frequency
% EncoderFiltSys = getDerivFilter_DDA(R, Q, Ts);

EncoderFiltSys = getDerivFilter(2, 5, 5, Ts);
MicrostrainFiltSys = getDerivFilter(2, 5, 5, TsMicrostrain);
UseMicrostrainRate = 0;

%% Anomaly detection and mitigation
MAX_ANOMALY = 30;
ANOMALY_INIT = 10;

EncoderAngleLimits = [60 240; 120 300; 60 240; 120 300; 60 240; 120 300; 60 240; 120 300; -30 30; -30 30; -inf inf; -inf inf; -inf inf; -inf inf; -30 30; -30 30; -inf inf; -90 90; -90 90]*pi/180;
EncoderThreshold = [5; 5; 5; 5; 5; 5; 5; 5; 5; 5; 250; 250; 250; 250; 5; 5; 5; 5; 5]*pi/180;

IMUAngleLimits = [-180 180; -90 90; -90 90]*pi/180;
IMUThreshold = 5*pi/180;

%% ATI F/T Interface
MODBUS_TIMEOUT = 0.02;   % (sec)  
STREAMING_TIMEOUT = 0.1; % (sec)

defineFTCalibrationBus();
writeBusSerializationFunctions('FTCalibrationBus', fullfile(fileparts(which('defineFTCalibrationBus')),'autogen'));

%% Offsets
IMUTorsoOffsets = [0; 0];
% GearOffsets = [1.24217943173965;-0.407713335566099;0.687918096516674;0.0151070496603364];
GearOffsets = [0.1290   -0.7550   -0.4480   -0.0800]';   % 8mm 2016-02-15
TorsoCOMOffsets = [0; 0];

%% DAQ Controls
ResetDAQ = 0;
ResetYaw = 0;
EnableFT = 0;
TareFT   = 0;
MedullaCommand = 0;
IMUCommand = 70;


