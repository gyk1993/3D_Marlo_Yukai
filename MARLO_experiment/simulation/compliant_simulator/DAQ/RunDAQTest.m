


n = length(log.t);
AbsAngle   = zeros(n,10);
IncAngle   = zeros(n,9);
Rollover   = zeros(n,9);
IncCalTick = zeros(n,6);

IncEncodersPrev = zeros(9,1);
RolloverIn = zeros(9,1);
HipCalTickIn = [0; 0];

for k=1:n
    Reset = (log.t(k)<2);
    AbsEncoders = log.Ticks(k,1:10)';
    IncEncoders = log.Ticks(k,11:19)';
    [AbsAngle(k,:), IncAngle(k,:), Rollover(k,:), IncCalTick(k,:)] = calibrateEncoders(CalibrationParams,AbsEncoders,IncEncoders,IncEncodersPrev,Reset,RolloverIn,HipCalTickIn);
    %[AbsAngle(k,:), IncAngle(k,:)] = calibrateEncoders(CalibrationParams,AbsEncoders,IncEncoders,IncEncodersPrev,Reset,RolloverIn,HipCalTickIn);
    IncEncodersPrev = IncEncoders;
    RolloverIn = Rollover(k,:)';
    HipCalTickIn = IncCalTick(k,:)';
end

figure(1); plot(log.t, Rollover); title('Rollover Count');
figure(2); plot(log.t, AbsAngle); title('Absolute Angles (Calibrated)');
figure(3); plot(log.t, IncAngle); title('Incremental Angles (Calibrated)');
figure(4); plot(log.t, IncCalTick);

%%
figure(10);
plot(log.t, IncAngle(:,5:6)*180/pi); hold on; plot(log.t, AbsAngle(:,9:10)*180/pi, '--'); hold off;
title('Hip Angles'); legend('q3R (inc)', 'q3L (inc)', 'q3R (abs)', 'q3L (abs)');

figure(11); clf;
plot(log.t, Rollover(:,5:6)); title('Rollover count'); legend('q3R (inc)', 'q3L (inc)');

%%
t = log.t;

figure(20); clf;
plot(t, log.EncodersClean-log.EncodersDirty);

figure(21); clf;
plot(t, log.EncodersClean*180/pi);
title('Encoders clean');

figure(22); clf;
plot(t, log.EncodersClean(:,1:4)*180/pi); hold on; plot(t, log.EncodersClean(:,5:8)*180/pi, '--');
title('Link and gear encoders');

figure(23); clf;
plot(t, log.EncodersClean(:,9:10)*180/pi); hold on; plot(t, log.EncodersClean(:,15:16)*180/pi, '--');
title('Hip encoders');

figure(24); clf;
plot(t, log.EncodersClean(:,11:14));
title('Motor encoders');
