%This function generates one .mat file with the calibration parameters 
%and one file with the motor paramters for MARLO
%It is primarily based on http://code.google.com/p/atrias/source/browse/robot_definitions/
% Notes:
% -UMich right leg is a type 4 leg, and UMich left leg is a type 3 leg
% -In OSU terminology, A=shin and B=thigh
% -In UMich terminology, 1=shin and 2=thigh
% -In OSU terminology, Leg=shin/thigh encoder and Trans=motor encoder (i.e.
%         our q_gr1R, etc.)

%From robot_invariant_defs.h
LEG_A_CALIB_LOC = 1.3089969389957472; %Calibration angle in OSU convention radians, based on Solidworks; Same for Leg and Motor/Trans 
LEG_B_CALIB_LOC = 1.8325957145940461;  %Calibration angle in OSU convention radians, based on Solidworks; Same for Leg and Motor/Trans
PITCH_ENCODER_RAD_PER_TICK = 0.00002396844; %Ticks to rad constant
HIP_INC_ENCODER_RAD_PER_TICK = 0.000009889017906384604997;  %Ticks to rad constant
HIP_ABS_ENCODER_RAD_PER_TICK = 0.000766990393942820614859; %Ticks to rad constant
% LEFT_MOTOR_HIP_DIRECTION = 1.0; %The direction for the left hip motor.
% RIGHT_MOTOR_HIP_DIRECTION = -1.0; %The direction for the right hip motor.
MTR_MAX_COUNT = 19900; %The maximum commanded amplifier value. This is the maximum value sent to the Medullas for the amplifier command.
%From biped2_variant_defs.h
LEFT_HIP_CALIB_VAL = 3249;   %Calibration encoder value in ticks (OSU convention)
RIGHT_HIP_CALIB_VAL = 1387;  %Calibration encoder value in ticks (OSU convention)
LEFT_HIP_CALIB_POS = 4.537856055185257;  %Calibration angle in radians (OSU convention)
RIGHT_HIP_CALIB_POS = 4.902629868852071; %Calibration angle in radians (OSU convention)
BOOM_X_METERS_PER_TICK = -0.00000937522094511213193198; %The meters of boom motion per encoder tick. This is calculated from the boom's length, the number of encoder ticks per encoder revolution, and the gear ratio between the boom and the encoder.
MTR_MAX_TORQUE = 60.0; %Maximum motor torque for scaling
MTR_HIP_MAX_TORQUE = 60.0; %Maximum hip motor torque for scaling
%From leg3_definitions.h (corresponds to UMich left leg)
%(Note that A=shin and B=thigh for OSU convention)
LEG3_LEG_A_CALIB_VAL = 265073230; %Calibration encoder value in ticks
LEG3_LEG_B_CALIB_VAL = 261240919; %Calibration encoder value in ticks
LEG3_LEG_A_RAD_PER_CNT = 9.8039216e-09; %Ticks to rad constant
LEG3_LEG_B_RAD_PER_CNT = -9.8039216e-09; %Ticks to rad constant
LEG3_TRAN_A_CALIB_VAL = 141488171; %Calibration encoder value in ticks
LEG3_TRAN_B_CALIB_VAL = 197960639; %Calibration encoder value in ticks
LEG3_TRAN_A_RAD_PER_CNT = 9.8039216e-09; %Ticks to rad constant
LEG3_TRAN_B_RAD_PER_CNT = -9.8039216e-09; %Ticks to rad constant
LEG3_MOTOR_A_DIRECTION = -1.0;
LEG3_MOTOR_B_DIRECTION = 1.0;
%From leg4_definitions.h (corresponds to UMich right leg)
%(Note that A=shin and B=thigh for OSU convention)
LEG4_LEG_A_CALIB_VAL = 265239580; %Calibration encoder value in ticks
LEG4_LEG_B_CALIB_VAL = 174863762; %Calibration encoder value in ticks
LEG4_LEG_A_RAD_PER_CNT = -9.8039216e-09; %Ticks to rad constant
LEG4_LEG_B_RAD_PER_CNT = -9.8039216e-09; %Ticks to rad constant
LEG4_TRAN_A_CALIB_VAL = 145825180; %141352160; %Calibration encoder value in ticks
LEG4_TRAN_B_CALIB_VAL = 142427224; %Calibration encoder value in ticks
LEG4_TRAN_A_RAD_PER_CNT = 9.8039216e-09; %Ticks to rad constant
LEG4_TRAN_B_RAD_PER_CNT = -9.8039216e-09; %Ticks to rad constant
LEG4_MOTOR_A_DIRECTION = -1.0;
LEG4_MOTOR_B_DIRECTION = 1.0;


%%

%From our tests at UMich
BOOM_PITCH_VERTICAL_VALUE = 80529; %The pitch encoder's reading (in ticks) when the boom-robot connection is locked in place
BOOM_ROLL_CAL_VALUE_DEG = .6; %Roll angle (in degrees) when the robot is lowered until it is hanging from the safety rope
BOOM_ROLL_CAL_VALUE_TICKS = 1643; %Roll encoder value when the robot is lowered until it is hanging from the safety rope
UMich_LEFT_MOTOR_HIP_DIRECTION = -1.0; %The direction for the left hip motor.
UMich_RIGHT_MOTOR_HIP_DIRECTION = -1.0; %The direction for the right hip motor.
HIP_INC_CALIB_VAL = 12*pi/180; %This is UMich calibration value in radians; assumes that the robot starts out with legs at the "folded in" position, which should be approx. 12 degrees
LEFT_HIP_INC_CALIB_CNT = 65459; %This is UMich calibration value in ticks (for UMich left hip incremental encoder); determined experimentally 
RIGHT_HIP_INC_CALIB_CNT = 65534; %This is UMich calibration value in ticks (for UMich right hip incremental encoder); determined experimentally 

HIP_INC_MAX_ENCODER_TICKS = 65535; %Max value of the incremental hip encoder (16-bit)
HIP_INC_3L_TICK_BIAS = 3769;
HIP_INC_3R_TICK_BIAS = 3234;

%IMU Alignment Params - These are the Euler angles (ZYX convention) which
%describe the matrix that takes us from the Robot frame to the IMU frame,
%given in degrees
Z_AXIS_ALIGNMENT_ANGLE = 0; %In degrees
Y_AXIS_ALIGNMENT_ANGLE = 90; %In degrees
X_AXIS_ALIGNMENT_ANGLE = 180; %In degrees

%% NEW CALIBRATION VALUES
%{
warning('Using new calibration values determined with Allen keys, not calibration pins! (CalibrationData-2013-06-29.mat)')
LEG4_LEG_A_CALIB_VAL =  264077192; % Old value:  265239580 
LEG4_LEG_B_CALIB_VAL =  175967399; % Old value:  174863762 
LEG3_LEG_A_CALIB_VAL =  265503819; % Old value:  265073230 
LEG3_LEG_B_CALIB_VAL =  261965398; % Old value:  261240919 
LEG4_TRAN_A_CALIB_VAL =  145944822; % Old value:  145825180 
LEG4_TRAN_B_CALIB_VAL =  142256884; % Old value:  142427224 
LEG3_TRAN_A_CALIB_VAL =  142090713; % Old value:  141488171 
LEG3_TRAN_B_CALIB_VAL =  198285796; % Old value:  197960639
%}

%{
% CALIBRATION WITH SHOULDER BOLTS
warning('Using new calibration values determined with shoulder bolts! (2013-07-18)')
LEG4_LEG_A_CALIB_VAL =  264772607; % 264077192;
LEG4_LEG_B_CALIB_VAL =  175995424; % 175967399;
LEG3_LEG_A_CALIB_VAL =  264911363; % 265503819;
LEG3_LEG_B_CALIB_VAL =  261612736; % 261965398;
LEG4_TRAN_A_CALIB_VAL =  145785534; % 145944822;
LEG4_TRAN_B_CALIB_VAL =  142225631; % 142256884;
LEG3_TRAN_A_CALIB_VAL =  142044899; % 142090713;
LEG3_TRAN_B_CALIB_VAL =  198272079; % 198285796;

BOOM_ROLL_CAL_VALUE_TICKS = 20883;
BOOM_PITCH_VERTICAL_VALUE = 68425;
%}

%
warning('Using new calibration values determined with shoulder bolts! (2013-12-09)')
LEG4_LEG_A_CALIB_VAL =  172473210; % 172473210;
LEG4_LEG_B_CALIB_VAL =  262858212; % 262858212;
LEG3_LEG_A_CALIB_VAL =  265758172;
LEG3_LEG_B_CALIB_VAL =  265686812;
LEG4_TRAN_A_CALIB_VAL =  197435714; % 197435714;
LEG4_TRAN_B_CALIB_VAL =  198013298; % 198013298;
LEG3_TRAN_A_CALIB_VAL =  199134830;
LEG3_TRAN_B_CALIB_VAL =  199703981;

BOOM_ROLL_CAL_VALUE_TICKS = 20883;
BOOM_PITCH_VERTICAL_VALUE = 68107; % BGB 2014-02-21 68425;
% 
%                    0
%                    0
%                    0
%            172473210
%            262858212
%            218025297
%            267532137
%            197435714
%            198013298
%                   18
%            151291602
%            201533416
%                    7
%                    0
%                    0

%                    0
%                    0
%                    0
%            251511428
%            179318438
%            265758172
%            265686812
%            118066741
%            114445835
%                   43
%            199134830
%            199703981
%                    9
%                    0
%                    0

%%
CalParams = [LEG_A_CALIB_LOC,LEG_B_CALIB_LOC,PITCH_ENCODER_RAD_PER_TICK,HIP_INC_ENCODER_RAD_PER_TICK,HIP_ABS_ENCODER_RAD_PER_TICK,...
    LEFT_HIP_CALIB_VAL,RIGHT_HIP_CALIB_VAL,LEFT_HIP_CALIB_POS,RIGHT_HIP_CALIB_POS,BOOM_PITCH_VERTICAL_VALUE,BOOM_X_METERS_PER_TICK,...
    LEG3_LEG_A_CALIB_VAL,LEG3_LEG_B_CALIB_VAL,LEG3_LEG_A_RAD_PER_CNT,LEG3_LEG_B_RAD_PER_CNT,...
    LEG3_TRAN_A_CALIB_VAL,LEG3_TRAN_B_CALIB_VAL,LEG3_TRAN_A_RAD_PER_CNT,LEG3_TRAN_B_RAD_PER_CNT,...
    LEG4_LEG_A_CALIB_VAL,LEG4_LEG_B_CALIB_VAL,LEG4_LEG_A_RAD_PER_CNT,LEG4_LEG_B_RAD_PER_CNT,...
    LEG4_TRAN_A_CALIB_VAL,LEG4_TRAN_B_CALIB_VAL,LEG4_TRAN_A_RAD_PER_CNT,LEG4_TRAN_B_RAD_PER_CNT,...
    HIP_INC_CALIB_VAL,LEFT_HIP_INC_CALIB_CNT,RIGHT_HIP_INC_CALIB_CNT,HIP_INC_MAX_ENCODER_TICKS,BOOM_ROLL_CAL_VALUE_DEG,BOOM_ROLL_CAL_VALUE_TICKS,...
    HIP_INC_3L_TICK_BIAS,HIP_INC_3R_TICK_BIAS];

MotorParams = [UMich_LEFT_MOTOR_HIP_DIRECTION,UMich_RIGHT_MOTOR_HIP_DIRECTION,MTR_MAX_COUNT,MTR_MAX_TORQUE,MTR_HIP_MAX_TORQUE,...
    LEG3_MOTOR_A_DIRECTION,LEG3_MOTOR_B_DIRECTION,LEG4_MOTOR_A_DIRECTION,LEG4_MOTOR_B_DIRECTION];

IMU_Alignment_Params = [Z_AXIS_ALIGNMENT_ANGLE Y_AXIS_ALIGNMENT_ANGLE X_AXIS_ALIGNMENT_ANGLE];


%% setup filters for encoder differentiation
M_deriv_encoder  = 5; % size of window (filter of order M-1)
m0_deriv_encoder = 5; % tap at which derivative is computed
N_deriv_encoder  = 2; % degree of polynomial to fit
Dt_deriv_encoder = 0.001;

[A,B,C,D] = num_der(N_deriv_encoder,M_deriv_encoder,m0_deriv_encoder,Dt_deriv_encoder);

A_deriv_encoder=A;
B_deriv_encoder=B;
C_deriv_encoder=C(2,:);
D_deriv_encoder=D(2,:);

[A_deriv_encoder,B_deriv_encoder,C_deriv_encoder,temp,PP] = dbalreal(A_deriv_encoder,B_deriv_encoder,C_deriv_encoder);
x0_deriv_encoder = PP*0*B_deriv_encoder(:,1);

% setup filters for IMU differentiation
M_deriv_IMU  = 10; % size of window (filter of order M-1)
m0_deriv_IMU = 10; % tap at which derivative is computed
N_deriv_IMU  = 2; % degree of polynomial to fit
Dt_deriv_IMU = 0.002;
%Dt_deriv_IMU = 0.004; % BGB 2013-06-22
clear A B C D
[A,B,C,D] = num_der(N_deriv_IMU,M_deriv_IMU,m0_deriv_IMU,Dt_deriv_IMU);

A_deriv_IMU=A;
B_deriv_IMU=B;
C_deriv_IMU=C(2,:);
D_deriv_IMU=D(2,:);

[A_deriv_IMU,B_deriv_IMU,C_deriv_IMU,temp,PP_IMU] = dbalreal(A_deriv_IMU,B_deriv_IMU,C_deriv_IMU);
x0_deriv_IMU = PP_IMU*0*B_deriv_IMU(:,1);
    

%%

A_dirty_deriv=A_deriv_encoder;
B_dirty_deriv=B_deriv_encoder;
C_dirty_deriv=C_deriv_encoder;
D_dirty_deriv=D_deriv_encoder;
Dt_dirty_deriv = Dt_deriv_encoder;
x0_dirty_deriv = x0_deriv_encoder;

A_dirty_deriv_IMU=A_deriv_IMU;
B_dirty_deriv_IMU=B_deriv_IMU;
C_dirty_deriv_IMU=C_deriv_IMU;
D_dirty_deriv_IMU=D_deriv_IMU;
Dt_dirty_deriv_IMU = Dt_deriv_IMU;
x0_dirty_deriv_IMU = x0_deriv_IMU;


%% Anomaly detection and mitigation
MAX_ANOMALY = 10;
ANOMALY_INIT = 10;

