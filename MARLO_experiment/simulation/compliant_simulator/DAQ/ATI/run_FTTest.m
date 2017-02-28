%
mdl = 'FTTest08';
tg.load(mdl);
tg.start();

sid.FTCount = tg.getsignalid('FTSerialStateMachine/p1');
sid.FT = tg.getsignalid('FTSerialStateMachine/p2/s1')+int32(0:6);

pid.StreamingMode = getparamid(tg, 'StreamingMode', 'Value');
pid.ModbusSend = getparamid(tg, 'ModbusSend', 'Value');
pid.ModbusFunction = getparamid(tg, 'ModbusFunction', 'Value');
pid.ModbusData = getparamid(tg, 'ModbusData', 'Value');

pause(0.5);
scs(1) = addscope(tg, 'Target',1);
set(scs(1), 'Decimation', 10, 'DisplayMode', 'Rolling', 'NumSamples', 250);
scs(1).addsignal(sid.FT)
scs.start();

%% Read Holding Registers
Address = uint16(hex2dec('00e3'));
NumRegs = 169;
while NumRegs>0
    NumRegsA = min(NumRegs, 125);
    setparam(tg, pid.ModbusFunction, 3);
    setparam(tg, pid.ModbusData, [4 bitshift(Address,-8) bitand(Address,255) 0 NumRegsA]);
    setparam(tg, pid.ModbusSend, 1);
    pause(0.05);
    setparam(tg, pid.ModbusSend, 0);    
    pause(0.05);
    NumRegs = NumRegs - NumRegsA;
    Address = Address+NumRegsA;
end

%%
mdl = 'FTTest09a';
!ping 192.168.1.23 -w 10 -n 1
xpctargetping
tg=xpc;
tg.load(mdl);
% xpctargetspy

%%
tg.start();
pause(5);

%%
tg.stop();
time=tg.TimeLog;
output=tg.OutputLog;
log=parseModelData(time, output, tg.Application);


longtips = @(fig) set(datacursormode(fig),'UpdateFcn', @(~,evt)sprintf('%8d\n%8d',get(evt,'Position')));
% close all
h = [];

%t = (1:length(log.t)).';
t = log.t;
dt = t(2)-t(1);
t7R  = cell2mat(arrayfun(@(t,n) t+(0:n-1).'*dt/n, t, log.FTCount(:,1), 'Unif', 0));
t7L  = cell2mat(arrayfun(@(t,n) t+(0:n-1).'*dt/n, t, log.FTCount(:,2), 'Unif', 0));
FT7R = cell2mat(arrayfun(@(k) reshape(log.FT(k, 1:6*log.FTCount(k,1)), 6, log.FTCount(k,1)).', (1:length(log.t)).', 'Unif', 0));
FT7L = cell2mat(arrayfun(@(k) reshape(log.FT(k, 48+(1:6*log.FTCount(k,2))), 6, log.FTCount(k,2)).', (1:length(log.t)).', 'Unif', 0));

figure(1); clf;
h(end+1) = subplot(3,1,1:2); set(gca, 'FontSize', 18); plot(t7R, FT7R(:,1:3), 'LineWidth', 1); hold on; plot(t7L, FT7L(:,1:3), '--', 'LineWidth', 1); ylabel('Force (N)'); grid on
h(end+1) = subplot(3,1,3); set(gca, 'FontSize', 18);  plot(t7R, FT7R(:,4:6), 'LineWidth', 1); hold on; plot(t7L, FT7L(:,4:6), '--', 'LineWidth', 1); ylabel('Torque (Nm)'); grid on
longtips(gcf);


%%

longtips = @(fig) set(datacursormode(fig),'UpdateFcn', @(~,evt)sprintf('%8d\n%8d',get(evt,'Position')));
% close all
h = [];

t = (1:length(log.t)).';
t = log.t;
dt = t(2)-t(1);
t7  = cell2mat(arrayfun(@(t,n) t+(0:n-1).'*dt/n, t, log.FTCount, 'Unif', 0));
FT7 = cell2mat(arrayfun(@(k) reshape(log.FT(k, 1:6*log.FTCount(k)), 6, log.FTCount(k)).', (1:length(log.t)).', 'Unif', 0));

% figure(1); clf;
% plot(t, [log.ModbusCommand(:,1) log.SerialOut(:,1) log.SerialIn(:,1) log.ModbusResponse(:,1) log.FTInterfaceStatus log.FTSetupStatus]);
% legend('ModbusCommand', 'SerialOut', 'SerialIn', 'ModbusResponse', 'FTInterfaceStatus', 'FTSetupStatus');
% h(1)=gca;
% longtips(1);

% figure(2); clf;
% plot(t, log.Gauge(:,1:6)); hold on
% plot(t, 1e4*log.FTStatus(:,1), 'k', 'LineWidth', 2); hold off
% ylabel('Gauge');
% h(2)=gca;
% longtips(2);
%%
figure(1); clf;
h(end+1) = subplot(3,1,1:2); set(gca, 'FontSize', 18); plot(t7, FT7(:,1:3), 'LineWidth', 1); ylabel('Force (N)'); grid on
h(end+1) = subplot(3,1,3); set(gca, 'FontSize', 18);  plot(t7, FT7(:,4:6), 'LineWidth', 1); ylabel('Torque (Nm)'); grid on
longtips(gcf);
% 
% figure(4); clf; 
% plot(t, log.FTStatus)
% h(4) = gca;

linkaxes(h, 'x');


%%
figure(1); clf;
h(1) = subplot(311); plot(log.t, log.SerialIn(:,1), log.t, log.SerialOut(:,1));
h(2) = subplot(312); plot(log.t, log.SerialIn); hold on; plot(log.t, log.RequestStreamingMode*500, 'g', 'LineWidth', 2);
h(3) = subplot(313); plot(log.t, log.SerialOut);

figure(2); clf;
h(4) = subplot(311); plot(log.t, log.MessageCount);
h(5) = subplot(3,1,[2 3]); plot(log.t, log.ModbusResponse);

linkaxes(h,'x');
