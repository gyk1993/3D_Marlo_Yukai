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
EncoderFiltSys = getDerivFilter(2, 5, 5, Ts);
MicrostrainFiltSys = getDerivFilter(2, 5, 5, TsMicrostrain);
UseMicrostrainRate = 0;

% -- OSU derivative filter --
% Sensors
sample_time = Ts;
lpf_damping = sqrt(2)/2; % Butterworth filter damping
fcut_velocity = 200*(2*pi); % Cutoff frequency for velocities
B1_lpf_velocity = -2*exp(-lpf_damping*fcut_velocity*sample_time)*cos(fcut_velocity*sample_time*sqrt(1-lpf_damping^2));
B2_lpf_velocity = exp(-2*lpf_damping*fcut_velocity*sample_time);
A_lpf_velocity = 1 + B1_lpf_velocity + B2_lpf_velocity;


% -- DDA Kalman Filter --
% std_w = 1/Ts^2;
% R = std_w^2/10;    % state noise (default)
% Q = Ts/100;        % output noise (default)
% % Q = 1.5e3;    % filter out more frequency
% EncoderFiltSys = getDerivFilter_DDA(R, Q, Ts);


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
GearOffsets = [1.24217943173965;-0.407713335566099;0.687918096516674;0.0151070496603364];
TorsoCOMOffsets = [0; 0];

%% DAQ Controls
ResetDAQ = 0;
ResetYaw = 0;
EnableFT = 0;
TareFT   = 0;
MedullaCommand = 0;
IMUCommand = 70;


