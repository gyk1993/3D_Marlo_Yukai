function [CalibrationParams MotorParams IMUParams] = getCalibrationParams()
    
    %% Calibration Tick Values
    [AbsCalTick, BoomCalTick] = Calibration01();
    
    %% Absolute encoder calibration
    % AbsEncoders = [q1R; q2R; q1L; q2L; qgr1R; qgr2R; qgr1L; qgr2L; q3R; q3L]
    
    RENISHAW_LINEAR_RAD_PER_TICK = 9.8039216e-09; %Ticks to rad constant
    RENISHAW_ROTARY_RAD_PER_TICK = 0.000766990393942820614859; %Ticks to rad constant
    
    AbsCalConst = [...
        [-1; -1; 1; -1; 1; -1; 1; -1]*RENISHAW_LINEAR_RAD_PER_TICK; ...
        [1; 1]*RENISHAW_ROTARY_RAD_PER_TICK ...
        ];
    
    AbsCalAngle = [165; 195; 165; 195; 165; 195; 165; 195; 12; 12]*pi/180;
    AbsMaxTick = [ones(8,1)*2^32; 8192; 8192];
    
    %% Incremental encoder calibration
    % IncEncoders = [qmot1R; qmot2R; qmot1L; qmot2L; qmot3R; qmot3L;
    
    MOTOR_INC_RAD_PER_TICK = 2*pi/3500/4;
    MOTOR_INC_MAX_TICK     = 2^16;
    HIP_INC_MAX_TICK       = 65536; % Max value of the incremental hip encoder (16-bit)
    
    HIP_INC_RAD_PER_TICK   = 0.000009889017906384604997;  %Ticks to rad constant
    
    % NOTE (BGB): The value of HIP_INC_RAD_PER_TICK privided by OSU is
    % about 10% lower than the value below. I am just guessing on the
    % number of ticks per revolution. US DIGITAL makes standard
    % transmissive disks with up to 2500 lines per revolution
    % (http://www.usdigital.com/products/em1), and we get 4 ticks per line
    % using quadrature decoding (see "Resolution" at
    % http://www.usdigital.com/support/glossary). I am also estimating the
    % gear ratio in order to make the incremental and absolute encoders
    % agree. If you measure the diameter of the hip motor output, it is
    % about 18 mm, and the radius of the hip pulley is about 55 cm, so we
    % get a gear ratio of 550mm/9mm = 61.1.
    % HIP_INC_RAD_PER_TICK   =  2*pi/56.8/10000;  %Ticks to rad constant (2*pi hip rad/hip rev)*(1 hip rev/56.8 mot rev)*(1 mot rev/10000 ticks)
    
    IncCalConst = [[1; -1; 1; -1]*MOTOR_INC_RAD_PER_TICK; [-1; -1]*HIP_INC_RAD_PER_TICK];
    IncMaxTick  = [[1; 1; 1; 1]*MOTOR_INC_MAX_TICK; [1; 1]*HIP_INC_MAX_TICK];
    
    %% Boom calibration
    % Boom = [qzT; qyT; qxT]
    BOOM_ENCODER_RAD_PER_TICK = 0.00002396844; %Ticks to rad constant
    BOOM_ENCODER_MAX_TICK     = 2^17;
    
    BoomCalConst = [-1/4.77; 1/3.77; 1]*BOOM_ENCODER_RAD_PER_TICK;
    BoomCalAngle = [0; 0; 0]*pi/180;
    
    BoomMaxTick  = [1; 1; 1]*BOOM_ENCODER_MAX_TICK;
    
    % NOTE (BGB): The factor 1/4.77 was estimated by moving the boom in
    % roughly a half circle and computing the max and min angles.
    %
    % NOTE (BGB): The factor 1/3.77 was estimated regressing the
    % encoder-measured roll angle against the KVH-IMU computed roll angle
    % after an experiment where the boom was raised and lowered. 
    %   RollKVH = [ONES RollEncoder]*[a; b]
    % The value of b was about 1/3.77.
    
    %% Concatenate
    CalibrationParams = [AbsMaxTick; AbsCalConst; AbsCalAngle; AbsCalTick; IncMaxTick; IncCalConst; BoomMaxTick; BoomCalConst; BoomCalAngle; BoomCalTick];
    
    
    %% Motors
    UMich_LEFT_MOTOR_HIP_DIRECTION = -1.0; %The direction for the left hip motor.
    UMich_RIGHT_MOTOR_HIP_DIRECTION = -1.0; %The direction for the right hip motor.
    MTR_MAX_COUNT = 19900; %The maximum commanded amplifier value. This is the maximum value sent to the Medullas for the amplifier command.
    MTR_MAX_TORQUE = 60.0; %Maximum motor torque for scaling
    MTR_HIP_MAX_TORQUE = 60.0; %Maximum hip motor torque for scaling
    LEG3_MOTOR_A_DIRECTION = -1.0;
    LEG3_MOTOR_B_DIRECTION = 1.0;
    LEG4_MOTOR_A_DIRECTION = -1.0;
    LEG4_MOTOR_B_DIRECTION = 1.0;
    
    MotorParams = [UMich_LEFT_MOTOR_HIP_DIRECTION,UMich_RIGHT_MOTOR_HIP_DIRECTION,MTR_MAX_COUNT,MTR_MAX_TORQUE,MTR_HIP_MAX_TORQUE,...
        LEG3_MOTOR_A_DIRECTION,LEG3_MOTOR_B_DIRECTION,LEG4_MOTOR_A_DIRECTION,LEG4_MOTOR_B_DIRECTION];
    
    %% Microstrain IMU
    %IMU Alignment Params - These are the Euler angles (ZYX convention) which
    %describe the matrix that takes us from the Robot frame to the IMU frame,
    %given in degrees
    Z_AXIS_ALIGNMENT_ANGLE = 0; %In degrees
    Y_AXIS_ALIGNMENT_ANGLE = 90; %In degrees
    X_AXIS_ALIGNMENT_ANGLE = 180; %In degrees
    
    IMUParams = [Z_AXIS_ALIGNMENT_ANGLE Y_AXIS_ALIGNMENT_ANGLE X_AXIS_ALIGNMENT_ANGLE];
end


function [AbsCalTick, BoomCalTick] = Calibration01()
        AbsCalTick = [...
        172473210; ...
        262858212; ...
        265758172; ...
        265686812; ...
        197435714; ...
        198013298; ...
        199134830; ...
        199703981; ...
        5769; ...
        506; ...
        ];
    
    BoomCalTick  = [38047; 20883; 68107]; % BGB 2014-02-21 [0; 20883; 68425];
end
