
mdl = bdroot;
tg=xpc;
tg.load(mdl);
%{
paramid.EnableFT = getparamid(tg, 'SerialInterfaces/EnableFT', 'Value');
paramid.TareFT = getparamid(tg, 'SerialInterfaces/TareFT', 'Value');
%}
paramid.EnableFT = getparamid(tg, '', 'EnableFT');
paramid.TareFT = getparamid(tg, '', 'TareFT');


sid.EtherCATStatus = [...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s1') ...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s2') ...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s3') ...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s4') ...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s5') ...
    getsignalid(tg, 'EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97/s6') ...
    ];
sid.KVHEulerAngles = [...
    getsignalid(tg, 'SerialInterfaces/KVH/ComputeEulerAngles/p1/s1') ...
    getsignalid(tg, 'SerialInterfaces/KVH/ComputeEulerAngles/p1/s2') ...
    getsignalid(tg, 'SerialInterfaces/KVH/ComputeEulerAngles/p1/s3') ...
    ];

tg.remscope();
sc(1) = tg.addscope('Target');
sc(1).addsignal(sid.EtherCATStatus(4));
sc(1).YLimit = [-3e5 3e5];
sc(2) = tg.addscope('Target');
sc(2).addsignal(sid.KVHEulerAngles)
sc(2).YLimit = [-3.5 3.5];
sc(3) = tg.addscope('Target');
sc(3).addsignal(sid.EtherCATStatus(2));
sc(3).DisplayMode = 'Numerical';

%tg.SampleTime = 0.0005 * (1.004825);
%tg.SampleTime = 0.0005 * (1.004);
tg.SampleTime = 0.0005 + 2.1e-6; % Gordon Weast

tg.StopTime = 30;

setparam(tg, paramid.EnableFT, 1);
tg.start();


%%
%tg.SampleTime = 0.0005 * (1.004825);
%paramid.EnableFT = getparamid(tg, '', 'EnableFT');
%setparam(tg, paramid.EnableFT, 0);
%setparam(tg, paramid.TareFT, 1);

sc.start();
while strcmp(tg.Status, 'running')
    pause(1);
end

%setparam(tg, paramid.TareFT, 0);
%%

%setparam(tg, paramid.EnableFT, 0);
%pause(0.5);
%sc.stop();
pause(1);
tg.stop();
pause(1);
log = parseModelData(tg);
plotStandaloneDAQ

SimulinkRealTime.copyFileToHost('c:\xPCTrace.csv');
%log.xpcTrace = csvread('xPCTrace.csv');
log.SampleTime = tg.SampleTime;
Data = rmfield(log, setdiff(fieldnames(log), {'Model','TET','t','EtherCATStatus','profData','SampleTime'}));

profileInfo.modelname = bdroot;
log.profData = profile_xpc(profileInfo);


