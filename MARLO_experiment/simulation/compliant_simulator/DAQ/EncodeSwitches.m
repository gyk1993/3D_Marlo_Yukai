function [LimitSwitchesEncoded] = EncodeSwitches(LimitSwitchesVec)
    % From OSU code:
    % (See atrias/software/atrias_medulla_drivers/src/LegMedulla.cpp and
    % http://code.google.com/p/atrias/wiki/LimitSwitches; note error in Leg
    % A bits 4 and 5.)
    %
    % Hip
    % 0 	Inside limit (relaxed position)
    % 1 	Outside limit (fully extended)
    %
    % Leg A
    % 0 	Negative motor limit
    % 1 	Positive motor limit
    % 2 	Negative spring deflection limit
    % 3 	Positive spring deflection limit
    % 4 	Leg extension limit
    % 5 	Leg retraction limit
    %
    % Leg B
    % 0 	Negative motor limit
    % 1 	Positive motor limit
    % 2 	Negative spring deflection limit
    % 3 	Positive spring deflection limit
    % 4 	Motor retraction limit
    
    % LimitSwitches is an integer which encodes the state of all of the limit switches
    % The bit encoding is as follows:
    %   Right Shin (A)
    %     LSB 0:	Negative motor limit
    %         1: 	Positive motor limit
    %         2: 	Negative spring deflection limit
    %         3: 	Positive spring deflection limit
    %         4: 	Leg retraction limit
    %         5: 	Leg extension limit
    %   Right Thigh (B)
    %   	  6: 	Negative motor limit
    %   	  7:	Positive motor limit
    %   	  8:	Negative spring deflection limit
    %   	  9:	Positive spring deflection limit
    %   	 10:	Motor retraction limit
    %   Right Hip
    %   	 11:	Inside limit (relaxed position)
    %   	 12:    Outside limit (fully extended)
    %   Left Shin (A)
    %        16:	Negative motor limit
    %        17: 	Positive motor limit
    %        18: 	Negative spring deflection limit
    %        19: 	Positive spring deflection limit
    %        20: 	Leg retraction limit
    %        21: 	Leg extension limit
    %   Left Thigh (B)
    %   	 22: 	Negative motor limit
    %   	 23:	Positive motor limit
    %   	 24:	Negative spring deflection limit
    %   	 25:	Positive spring deflection limit
    %   	 26:	Motor retraction limit
    %   Left Hip
    %   	 27:	Inside limit (relaxed position)
    %   	 28:	Outside limit (fully extended)
    
    LimitSwitchesEncoded  = uint32(0);
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(1), 0));  % Right Shin (A)
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(2), 6));  % Right Thigh (B)
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(3), 11)); % Right Hip
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(4), 16)); % Left Shin (A)
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(5), 22)); % Left Thigh (B)
    LimitSwitchesEncoded  = bitor(LimitSwitchesEncoded, bitshift(LimitSwitchesVec(6), 27)); % Left Hip
    
end
