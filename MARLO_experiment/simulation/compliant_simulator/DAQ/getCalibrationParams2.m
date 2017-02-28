function Calibration = getCalibrationParams2()
    
    %% Calibration Tick Values
    [Calibration.AbsCalTick, Calibration.BoomCalTick] = Calibration01();
    
    %% Absolute encoder calibration
    % AbsEncoders = [q1R; q2R; q1L; q2L; qgr1R; qgr2R; qgr1L; qgr2L; q3R; q3L]
    
    RENISHAW_LINEAR_RAD_PER_TICK = 9.8039216e-09; %Ticks to rad constant
    RENISHAW_ROTARY_RAD_PER_TICK = 0.000766990393942820614859; %Ticks to rad constant
    
    Calibration.AbsCalConst = [...
        [-1; -1; 1; -1; 1; -1; 1; -1]*RENISHAW_LINEAR_RAD_PER_TICK; ...
        [1; 1]*RENISHAW_ROTARY_RAD_PER_TICK ...
        ];
    
    Calibration. AbsCalAngle = [165; 195; 165; 195; 165; 195; 165; 195; 12; 12]*pi/180;
    Calibration.AbsMaxTick = [ones(8,1)*2^32; 8192; 8192];
    
    %% Incremental encoder calibration
    % IncEncoders = [qmot1R; qmot2R; qmot1L; qmot2L; qmot3R; qmot3L]
    
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
    % agree. If you measure the DIAMETER of the hip motor output, it is
    % about 1.8 cm, and the RADIUS of the hip pulley is about 55 cm, so we
    % get a gear ratio of 55cm/0.9cm = 61.1.
    % HIP_INC_RAD_PER_TICK   =  2*pi/56.8/10000;  %Ticks to rad constant (2*pi hip rad/hip rev)*(1 hip rev/56.8 mot rev)*(1 mot rev/10000 ticks)
    
    Calibration.IncCalConst = [[1; -1; 1; -1]*MOTOR_INC_RAD_PER_TICK; [-1; -1]*HIP_INC_RAD_PER_TICK];
    Calibration.IncMaxTick  = [[1; 1; 1; 1]*MOTOR_INC_MAX_TICK; [1; 1]*HIP_INC_MAX_TICK];
    
    %% Boom calibration
    % Boom = [qzT; qyT; qxT]
    BOOM_ENCODER_RAD_PER_TICK = 0.00002396844; %Ticks to rad constant
    BOOM_ENCODER_MAX_TICK     = 2^17;
    
    Calibration.BoomCalConst = [-1/4.77; 1/3.77; 1]*BOOM_ENCODER_RAD_PER_TICK;
    Calibration.BoomCalAngle = [0; 0; 0]*pi/180;
    
    Calibration.BoomMaxTick  = [1; 1; 1]*BOOM_ENCODER_MAX_TICK;
    
    % NOTE (BGB): The factor 1/4.77 was estimated by moving the boom in
    % roughly a half circle and computing the max and min angles.
    %
    % NOTE (BGB): The factor 1/3.77 was estimated regressing the
    % encoder-measured roll angle against the KVH-IMU computed roll angle
    % after an experiment where the boom was raised and lowered.
    %   RollKVH = [ONES RollEncoder]*[a; b]
    % The value of b was about 1/3.77.
    
    % Combine Incremental and Boom Max Ticks for convenience
    Calibration.MaxTick  = [Calibration.IncMaxTick; Calibration.BoomMaxTick];
    
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
    
    Calibration.Motors = [UMich_LEFT_MOTOR_HIP_DIRECTION; UMich_RIGHT_MOTOR_HIP_DIRECTION; ...
        MTR_MAX_COUNT; MTR_MAX_TORQUE; MTR_HIP_MAX_TORQUE;...
        LEG3_MOTOR_A_DIRECTION; LEG3_MOTOR_B_DIRECTION; ...
        LEG4_MOTOR_A_DIRECTION; LEG4_MOTOR_B_DIRECTION];
    
    % KVHOrientationCal and MicrostrainOrientationCal should be the
    % rotation matrix R_R^I mapping points in the robot frame to points in
    % the IMU frame. From the IMU data, the DAQ computes the rotation
    % matrix R_I^W representing the IMU orientation in the world frame.
    % This estimate is right multiplied by KVHOrientationCal = R_R^I to get
    % the orientation of the robot in the world frame:
    %   R_R^W = R_I^W * R_R^I
    Calibration.KVHOrientation = [0 0 -1; 1/sqrt(2) -1/sqrt(2) 0; -1/sqrt(2) -1/sqrt(2) 0].'; % transpose(Ry(-pi/2)*Rz(3*pi/4))
    Calibration.MicrostrainOrientation = [0 0 -1; 0 -1 0; -1 0 0];
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
