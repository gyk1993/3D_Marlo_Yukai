function [MotorCurrentCommandSafe, MedullaCommandSafe, SafetyState, SafetyCountOut] = MARLOSafety_ATRIAS(MotorCurrentCommand, MedullaCommand, RequestSoftStop, q, dq, SafetyCountIn, SelectBasicLimits)
    %#codegen

    % Checks DAQ inputs and outputs to ensure that the commands sent to the
    % robot and the state reported by the robot are okay. Any invalid
    % commands to the robot are discarded, and default (zero) commands are
    % send instead. The cause of the failure can be traced by logging the
    % SafetyStateOut output.
    %
    % SafetyState is a double with integer value in the range 0 to
    % 2^52-1. The 52 bits of the significand represent different safety
    % checks. Corresponding bits are set when a safety violation is
    % detected. If SafetyState is nonzero for more than SSMAX time steps,
    % the requested commands (MotorCurrentCommand, MedullaCommand,
    % IMUCommand) are replaced with the safe commands specified below. This
    % should cause the torque to be zero and the Medullas to enter the HALT
    % or ERROR state.
    
    
%     if (nargin < 6)
%         SelectBasicLimits = 1;
%     end
    
    % SAFE OUTPUTS
    % THESE OUTPUTS ARE USED IN A HARD SHUTDOWN, AND CAUSE ALL COMMANDED
    % CURRENTS TO BE ZEROED AND THE MEDULLAS TO ENTER THE HALT STATE.
    MotorCurrentCommandSafe   = [0; 0; 0; 0; 0; 0];
    MedullaCommandSafe        = 4; % 4=HALT
    
    % HARD SAFETY PARAMETERS
    % THE FOLLOWING PARAMETERS SPECIFY LIMITS WHICH, WHEN EXCEEDED, CAUSE
    % THE SAFETY TO LOCK DOWN THE ROBOT BY SENDING THE DEFAULT SAFE OUTPUTS
    % ABOVE.
    %MAX_MOTOR_TEMP         = 80; % C
    MAX_MOTOR_CURRENT      = 120;  % Amps 
    VALID_MEDULLA_COMMANDS = [0 1 2 3 4 5 6 7];
    %VALID_IMU_COMMANDS     = [0 1 2]; % Meaningless for now
    
    % END (HARD SAFETY PARAMETERS)
    
    % SOFT SAFETY PARAMETERS
    % THE FOLLOWING PARAMETERS SPECIFY LIMITS WHICH DO NOT CAUSE THE SAFETY
    % TO LOCK DOWN THE WHOLE ROBOT. INSTEAD, APPROPRIATE CURRENTS ARE
    % LIMITED TO PREVENT DRIVING THE MOTORS IN A MANNER THAT MIGHT CAUSE
    % DAMAGE
    %MAX_HIP_ANGLE_SOFT           = 7; % degrees; mechanical limit is reported to be 20 degrees
    %MIN_HIP_ANGLE_SOFT           = -15; % degrees; mechanical limit is reported to be -10 degrees 
    
    %SOFT_LIMIT_WIDTH_HIP         = 4;  % degrees
    %SOFT_LIMIT_UMAX_HIP          = 15; % Amps
    % END (SOFT SAFETY PARAMETERS)
    
    
    % SAFETY STATE DEFINITION
    %SS_DYNAMIC_STATE_LIMIT     = 2.^(0:39).'; % bits 1:40
    SS_DYNAMIC_STATE_LIMIT     = 2.^(0:33).'; % bits 1:40
    SS_INVALID_MOTOR_COMMAND   = 2^40; % bit 41
    SS_INVALID_MEDULLA_COMMAND = 2^41; % bit 42
    %SSMASK_INVALID_IMU_COMMAND     = 2^42; % bit 43
    %SSMASK_OVERTEMP                = 2^43; % bit 44
    
    
    % CHECK ROBOT CONFIGURATION AND VELOCITY (HARD SAFETY)
    switch SelectBasicLimits
        case 5
            violation = MARLOBasicSafetyLimits5(q, dq);
        case 4
            violation = MARLOBasicSafetyLimits4(q, dq);
        case 3
            violation = MARLOBasicSafetyLimits3(q, dq);
        case 2
            violation = MARLOBasicSafetyLimits2(q, dq);
        otherwise
            violation = MARLOBasicSafetyLimits(q, dq);
    end
    SafetyState = sum(SS_DYNAMIC_STATE_LIMIT .* violation);
    
    % VALIDATE MOTOR COMMAND
    if any(~isfinite(MotorCurrentCommand)) ...                    % Check for NaN and +Inf and -Inf
            || any(abs(MotorCurrentCommand) > MAX_MOTOR_CURRENT)  % Check for extremely large commands
        SafetyState = SafetyState + SS_INVALID_MOTOR_COMMAND;
    end
    
    % VALIDATE MEDULLA COMMAND
    if any(~ismember(MedullaCommand, VALID_MEDULLA_COMMANDS))
        SafetyState = SafetyState + SS_INVALID_MEDULLA_COMMAND;
    end
    
    % VALIDATE IMU COMMAND
    %if any(~ismember(IMUCommand, VALID_IMU_COMMANDS))
    %    SafetyState = SafetyState + SS_INVALID_IMU_COMMAND;
    %end    
        
    % CHECK THERMISTORS    
    % TODO

    
    % CHECK ROBOT CONFIGURATION (SOFT SAFETY)
    
    % THE FOLLOWING LIMITS, WHEN EXCEEDED, DO *NOT* CAUSE THE SAFETY TO
    % LOCK DOWN THE WHOLE ROBOT. INSTEAD, APPROPRIATE CURENTS ARE LIMITED
    % TO PREVENT DRIVING THE MOTORS IN A MANNER THAT MIGHT CAUSE DAMAGE
    
    %{
    % BGB 2014-05-21
    q3R = q(10);
    q3L = q(13);
    
    MotorCurrentCommand(3) = continuouslySaturate(MotorCurrentCommand(3), q3R, [MIN_HIP_ANGLE_SOFT MAX_HIP_ANGLE_SOFT]*pi/180, SOFT_LIMIT_WIDTH_HIP*pi/180, SOFT_LIMIT_UMAX_HIP);
    MotorCurrentCommand(6) = continuouslySaturate(MotorCurrentCommand(6), q3L, [MIN_HIP_ANGLE_SOFT MAX_HIP_ANGLE_SOFT]*pi/180, SOFT_LIMIT_WIDTH_HIP*pi/180, SOFT_LIMIT_UMAX_HIP);
    % END BGB 2014-05-21
    %}
    
    
    % IF EVERYTHING LOOKS OKAY (SAFETYSTATE==0), THEN PASS THE COMMANDS TO THE DAQ
    if (SafetyState==0)
        SafetyCountOut = max(0, SafetyCountIn-1);
    else
        SafetyCountOut = min(SafetyCountIn+1, 10);
    end
    
    if (SafetyCountOut < 4) && (RequestSoftStop == 0)
        MotorCurrentCommandSafe = MotorCurrentCommand;
        MedullaCommandSafe = MedullaCommand;
    end

    
end

