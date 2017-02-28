function [AbsAngle, IncAngle, Rollover, IncCalTick] = calibrateEncoders(CalibrationParams,AbsEncoders,IncEncoders,IncEncodersPrev,Reset,RolloverIn,IncCalTickIn)
    %#codegen
    %This function calibrates the encoder values and converts to radians.

    % CalibrationParams = [AbsMaxTick; AbsCalConst; AbsCalAngle; AbsCalTick; IncMaxTick; IncCalConst; BoomMaxTick; BoomCalConst; BoomCalAngle; BoomCalTick];
    
    AbsMaxTick   = CalibrationParams(1:10);
    AbsCalConst  = CalibrationParams(11:20);
    AbsCalAngle  = CalibrationParams(21:30);
    AbsCalTick   = CalibrationParams(31:40);
    
    IncMaxTick   = CalibrationParams(41:46);
    IncCalConst  = CalibrationParams(47:52);
    
    BoomMaxTick  = CalibrationParams(53:55);
    BoomCalConst = CalibrationParams(56:58);
    BoomCalAngle = CalibrationParams(59:61);
    BoomCalTick  = CalibrationParams(62:64);
    
    MaxTick      = [IncMaxTick; BoomMaxTick];
    
    % Absolute hip encoders might rollover. This is not possible for the
    % linear optical encoders. We solve the rollover problem for the
    % absolute hip encoders by noting that they can only move about 30
    % degrees, so if the TICK count is very far from the CAL TICK count, we
    % know a rollover has occurred. We can then add or subtract the max
    % tick count to correct the problem.
    AbsEncoders(9:10) = unrollAbsEncoders(AbsMaxTick(9:10), AbsCalTick(9:10), AbsEncoders(9:10));
    
    % Calibrate absolute encoders
    AbsTick  = AbsEncoders;
    AbsAngle = AbsCalAngle + AbsCalConst.*(AbsTick - AbsCalTick);
    
    % Calibration and rollover count for incremental encoders
    if Reset
        Rollover = 0*RolloverIn;
        RefAngle = [AbsAngle(5:8)*50; AbsAngle(9:10)];
        [IncCalTick, Rollover(1:6)] = getIncCalTick(IncCalConst, IncMaxTick, RefAngle, IncEncoders(1:6));
    else
        Rollover   = RolloverIn + getRollover(MaxTick, IncEncoders, IncEncodersPrev);
        IncCalTick = IncCalTickIn;
    end
    
    % Calibrate incremental encoders
    IncCalTickB = [IncCalTick; BoomCalTick];
    IncCalAngle = [zeros(6,1); BoomCalAngle];
    IncTick     = IncEncoders + MaxTick.*Rollover;
    IncAngle    = IncCalAngle + [IncCalConst; BoomCalConst].*(IncTick - IncCalTickB);
end

function [IncCalTick, Rollover] = getIncCalTick(IncCalConst, IncMaxTick, AbsAngle, IncTick)
    % Compute the calibration tick count corresponding to 0 degrees
    IncCalTick = mod(IncTick - AbsAngle./IncCalConst, IncMaxTick);
    %Rollover = floor((IncCalTick-IncTick)./IncMaxTick);
    Rollover = floor((AbsAngle./IncCalConst-IncTick+IncCalTick)./IncMaxTick);
end

function Rollover = getRollover(MaxTick, IncEncoders, IncEncodersPrev)
    % Determine if a rollover has occurred on any incremental encoder
    % The determination is made by assuming the encoder shaft has rotated
    % less than half of a revolution since the previous time step. If a
    % rollover is detected on a particular encoder, the corresponding
    % element of Rollover is either +1 or -1, depending on the direction of
    % the rollover
    %
    % To compute the rollover, ticks are normalized by the maximum tick
    % number. This maps all (NormalizedCountPrev, NormalizedCount) pairs
    % into the region [0,1]X[0,1] in the plane. The upper left hand corner
    % corresponds to negative rollover, and the lower right hand corner
    % corresponds to positive rollover.
    
    NormalizedCountPrev = IncEncodersPrev./MaxTick;
    NormalizedCount     = IncEncoders./MaxTick;
    
    Rollover = zeros(9,1);
    Rollover(NormalizedCountPrev<0.5 & NormalizedCount > (NormalizedCountPrev+0.5)) = -1;
    Rollover(NormalizedCountPrev>0.5 & NormalizedCount < (NormalizedCountPrev-0.5)) = 1;
end

function AbsUnrolled = unrollAbsEncoders(AbsMaxTick, AbsCalTick, AbsEncoder)
    % We solve the rollover problem for the absolute hip encoders by noting
    % that they can only move about 30 degrees, so if the TICK count is
    % very far from the CAL TICK count, we know a rollover has occurred. We
    % can then add or subtract the max tick count to correct the problem.
    AbsUnrolled = AbsEncoder;
    
    % Find offset of Cal from center of tick range
    HalfMaxTicks = AbsMaxTick/2;
    CalOffset = AbsCalTick - HalfMaxTicks;
    
    % Find index of elements where the current encoder reading is GREATER
    % than CalOffset ticks above the CalTick. Correct by subtracting
    % MaxTicks (results in a negative number, which is okay).
    iHigh = (CalOffset<0) & (AbsEncoder > AbsCalTick + HalfMaxTicks);
    AbsUnrolled(iHigh) = AbsUnrolled(iHigh) - AbsMaxTick(iHigh);
    
    % Find index of elements where the current encoder reading is LESS than
    % CalOffset ticks below the CalTick. Correct by adding MaxTicks
    % (results in a count greater than MaxTicks, which is okay).
    iLow = (CalOffset>0) & (AbsEncoder < AbsCalTick - HalfMaxTicks);
    AbsUnrolled(iLow) = AbsUnrolled(iLow) + AbsMaxTick(iLow);
end

