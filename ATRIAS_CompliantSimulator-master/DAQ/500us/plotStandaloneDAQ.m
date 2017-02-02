
figure(21); clf;
subplot(211); plot(log.t, log.TET); title('Task Execution Time');
subplot(212); plot(log.t, log.EtherCATStatus(:,4)); title('EtherCAT Master To Network Clk Diff');

figure(22); clf;
plot(log.t, log.q(:,1:3)*180/pi); hold on;
plot(log.t, log.KVHEulerAngles*180/pi, '-.');
plot(log.t, log.MicrostrainEulerAnglesClean*180/pi, ':');
title('Euler Angles');

figure(23); clf;
plot(log.t, log.dq(:,1:3)*180/pi); hold on;
plot(log.t, log.KVHEulerAngleDeriv*180/pi, '-.');
plot(log.t, log.MicrostrainEulerAngleDerivsClean*180/pi, ':');
title('Euler Angle Derivatives');

figure(24); clf;
subplot(211); plot(log.t, log.FT(:,1:3)); title('Force')
subplot(212); plot(log.t, log.FT(:,4:6)); title('Torque');

%%
% E1 = zeros(length(log.t), 3);
% E2 = zeros(length(log.t), 3);
% E3 = zeros(length(log.t), 3);
% E4 = zeros(length(log.t), 3);
% for k=1:length(log.t)
%     E1(k,:) = computeEulerAnglesKevin([0 90 180], reshape(log.MicrostrainRotation(k,:), 3, 3));
%     E2(k,:) = computeEulerAnglesKevin([0 90 180], reshape(log.MicrostrainRotation(k,:), 3, 3).');
%     E3(k,:) = computeEulerAnglesKevin([180 90 0], reshape(log.MicrostrainRotation(k,:), 3, 3));
%     E4(k,:) = computeEulerAnglesKevin([180 90 0], reshape(log.MicrostrainRotation(k,:), 3, 3).');
% end
% 
% figure(5); clf;
% subplot(411); plot(E1*180/pi);
% subplot(412); plot(E2*180/pi);
% subplot(413); plot(E3*180/pi);
% subplot(414); plot(E4*180/pi);
% 
