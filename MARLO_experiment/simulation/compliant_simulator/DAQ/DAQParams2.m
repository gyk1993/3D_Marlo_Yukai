%% Sample times
TsFundamental = 0.0005;

%% Calibration
[CalibrationParams, MotorParams, IMUParams] = getCalibrationParams();

% KVHOrientationCal should be the rotation matrix R_R^I mapping points in
% the robot frame to points in the IMU frame. From the IMU data, the DAQ
% computes the rotation matrix R_I^W representing the IMU orientation in
% the world frame. This estimate is right multiplied by KVHOrientationCal =
% R_R^I to get the orientation of the robot in the world frame:
%   R_R^W = R_I^W * R_R^I
KVHOrientationCal = [0 0 -1; 1/sqrt(2) -1/sqrt(2) 0; -1/sqrt(2) -1/sqrt(2) 0].'; % transpose(Ry(-pi/2)*Rz(3*pi/4))
MicrostrainOrientationCal = [-1 0 0; 0 0 1; 0 1 0]; % Rx(-pi/2)*Rz(pi)
IMU_Alignment_Params = [0 90 180]; % in degrees

%% EncoderFilters
M_deriv_encoder  = 5; % size of window (filter of order M-1)
m0_deriv_encoder = 5; % tap at which derivative is computed
N_deriv_encoder  = 2; % degree of polynomial to fit
Dt_deriv_encoder = 0.001;

[A,B,C,D] = num_der(N_deriv_encoder,M_deriv_encoder,m0_deriv_encoder,Dt_deriv_encoder);

A_deriv_encoder=A;
B_deriv_encoder=B;
C_deriv_encoder=C(2,:);
D_deriv_encoder=D(2,:);

[A_deriv_encoder,B_deriv_encoder,C_deriv_encoder] = dbalreal(A_deriv_encoder,B_deriv_encoder,C_deriv_encoder);
x0_deriv_encoder = 0*B_deriv_encoder(:,1);

%% IMUFilters
M_deriv_IMU  = 5; % size of window (filter of order M-1)
m0_deriv_IMU = 5; % tap at which derivative is computed
N_deriv_IMU  = 2; % degree of polynomial to fit
Dt_deriv_IMU = 0.001;
[A,B,C,D] = num_der(N_deriv_IMU,M_deriv_IMU,m0_deriv_IMU,Dt_deriv_IMU);

A_deriv_IMU=A;
B_deriv_IMU=B;
C_deriv_IMU=C(2,:);
D_deriv_IMU=D(2,:);

[A_deriv_IMU,B_deriv_IMU,C_deriv_IMU] = dbalreal(A_deriv_IMU,B_deriv_IMU,C_deriv_IMU);
x0_deriv_IMU = 0*B_deriv_IMU(:,1);

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

% Offsets
IMUTorsoOffsets = [0; 0];
GearOffsets = [1.24217943173965;-0.407713335566099;0.687918096516674;0.0151070496603364];
TorsoCOMOffsets = [0; 0];

