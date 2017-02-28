function violation = MARLOSafetyLimitsOld(q)
    
    SafetyState               = uint32(0);
    
    MAX_TORSO_PITCH         = 35; % degrees
    MAX_TORSO_ROLL          = 20; % degrees
    MAX_LEG_ANGLE_DEVIATION = 40; % degrees from 180
    MAX_KNEE_ANGLE          = 80; % degrees; mechanical limit is 160 degrees
    MIN_KNEE_ANGLE          = 14.5; %22.5; % degrees; mechanical limit is reported to be 34.5 degrees
    MAX_LEG_LINK_FLEXION    = 80; % degrees from 180; mechanical limit is 107.5 degrees
    MAX_LEG_LINK_EXTENSION  = 20; % degrees from 180; mechanical limit is 45 degrees 
    % END (HARD SAFETY PARAMETERS)
    
    % SAFETY STATE DEFINITION
    SSMASK_BAD_CONFIGURATION       = uint32(8);
    
    % CHECK ROBOT CONFIGURATION (HARD SAFETY)   

    % THE FOLLOWING LIMITS, WHEN EXCEEDED, CAUSE THE SAFETY TO LOCK DOWN
    % THE ROBOT BY SENDING THE DEFAULT SAFE OUTPUTS ABOVE.
    qyT = q(2);
    qxT = q(3);
    qLA = [0 0 0 0.5 0.5   0   0 0 0 0 0 0 0; ...
           0 0 0   0   0 0.5 0.5 0 0 0 0 0 0]*q;
	qKA = [0 0 0  -1   1   0   0 0 0 0 0 0 0; ...
           0 0 0   0   0  -1   1 0 0 0 0 0 0]*q;
    qLegLinkFlexion = [0 0 0  -1   0   0   0 0 0 0 0 0 0; ...
                       0 0 0   0   1   0   0 0 0 0 0 0 0; ...
                       0 0 0   0   0  -1   0 0 0 0 0 0 0
                       0 0 0   0   0   0   1 0 0 0 0 0 0]*q + [1; -1; 1; -1]*pi;
                   
    if abs(qxT) > MAX_TORSO_PITCH*pi/180 ...
            || abs(qyT) > MAX_TORSO_ROLL*pi/180 ...
            || any(abs(qLA-pi) > MAX_LEG_ANGLE_DEVIATION*pi/180) ...
            || any(qKA > MAX_KNEE_ANGLE*pi/180) ...
            || any(qKA < MIN_KNEE_ANGLE*pi/180) ...
            || any(qLegLinkFlexion > MAX_LEG_LINK_FLEXION*pi/180) ...
            || any(qLegLinkFlexion < -MAX_LEG_LINK_EXTENSION*pi/180)
        
        SafetyState = bitor(SafetyState, SSMASK_BAD_CONFIGURATION);
    end
        
    
    % The SafetyState output must be a double for efficient storage in an array with other DAQ outputs
    violation = double(SafetyState); 
end

