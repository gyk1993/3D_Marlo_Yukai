function [AbsAngle, IncAngle, Rollover, IncCalTick] = calibrateEncoders2(Calibration,AbsEncoders,IncEncoders,IncEncodersPrev,Reset,RolloverIn,IncCalTickIn)
    %#codegen
    %This function calibrates the encoder values and converts to radians.
    
    % Absolute hip encoders might rollover. This is not possible for the
    % linear optical encoders. We solve the rollover problem for the
    % absolute hip encoders by noting that they can only move about 30
    % degrees, so if the TICK count is very far from the CAL TICK count, we
    % know a rollover has occurred. We can then add or subtract the max
    % tick count to correct the problem.
    AbsEncoders(9:10) = unrollAbsEncoders(Calibration.AbsMaxTick(9:10), Calibration.AbsCalTick(9:10), AbsEncoders(9:10));
    
    % Calibrate absolute encoders
    AbsAngle = Calibration.AbsCalAngle + Calibration.AbsCalConst.*(AbsEncoders - Calibration.AbsCalTick);
    
    % Calibration and rollover count for incremental encoders
    if Reset
        Rollover = 0*RolloverIn;
        RefAngle = [AbsAngle(5:8)*50; AbsAngle(9:10)];
        [IncCalTick, Rollover(1:6)] = getIncCalTick(Calibration.IncCalConst, Calibration.IncMaxTick, RefAngle, IncEncoders(1:6));
    else
        
        Rollover   = RolloverIn + getRollover(Calibration.MaxTick, IncEncoders, IncEncodersPrev);
        IncCalTick = IncCalTickIn;
    end
    
    % Calibrate incremental encoders
    IncCalTickB = [IncCalTick; Calibration.BoomCalTick];
    IncCalAngle = [zeros(6,1); Calibration.BoomCalAngle];
    IncTick     = IncEncoders + Calibration.MaxTick.*Rollover;
    IncAngle    = IncCalAngle + [Calibration.IncCalConst; Calibration.BoomCalConst].*(IncTick - IncCalTickB);
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

