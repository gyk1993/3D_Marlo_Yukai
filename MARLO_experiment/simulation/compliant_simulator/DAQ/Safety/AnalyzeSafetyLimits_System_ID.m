%%
%{
Fields = {'t', 'q', 'dq'};
parseOutput  = @(L) struct('log', struct('t', L.time, 'q', L.output(:,1:13), 'dq', L.output(:,14:26)));
getLogFields = @(L, tlim) rmfield(trimLog(L.log, tlim), setdiff(fieldnames(L.log), Fields));
packStruct = @(S) cell2struct(cellfun(@(f){vertcat(S.(f))}, fieldnames(S)), fieldnames(S), 1);

LOG(1) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2013-11-19\Experiment19\Experiment19.mat'), [77 89]);
LOG(2) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-06-06\Experiment07\Experiment07.mat'), [69.5 72]);
LOG(3) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-05-03\Experiment03\Experiment03.mat'), [171 175]);
LOG(4) = getLogFields(parseOutput(load('D:\bgbuss\biped\data\experiments\Walking\2013-07-10\Experiment09.mat')), [760 774.5]);
LOG(5) = getLogFields(parseOutput(load('D:\bgbuss\biped\data\experiments\Walking\2013-07-11\Experiment02.mat')), [107 114.5]);
LOG(6) = getLogFields(parseOutput(load('D:\bgbuss\biped\data\experiments\Walking\2013-10-05\Experiment02.mat')), [105 109]);
LOG(7) = getLogFields(load('D:\bgbuss\biped\data\experiments\Walking\2013-10-24\Experiment01.mat'), [306 308.5]);
LOG(8) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-05-06\Experiment04\Experiment04.mat'), [290 305]);
LOG(9) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-05-06\Experiment08\Experiment08.mat'), [95 108]);
LOG(10) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-05-06\Experiment09\Experiment09.mat'), [182.5 187.5]);
%LOG(11) = getLogFields(load('D:\bgbuss\biped\Dropbox\TeamWide\Logs\Walking\2014-05-06'));



%clear DATA
% Good walking
DATA(1) = packStruct([...
    trimLog(LOG(1), [77 89]); ...
    trimLog(LOG(2), [69.5 70.5]); ...
    trimLog(LOG(3), [171 173.5]); ...
    trimLog(LOG(4), [760 772]); ...
    trimLog(LOG(5), [107 111.5]); ...
    trimLog(LOG(6), [105 106.5]); ...
    trimLog(LOG(7), [306 307]); ...
    ]);
% Just before things get really bad
DATA(2) = packStruct([...
    trimLog(LOG(2), [70.5 71.3]);...
    trimLog(LOG(3), [173.5 174.1]);...
    trimLog(LOG(4), [772 773.5]); ...
    trimLog(LOG(5), [111.5 112.2]); ...
    trimLog(LOG(6), [106.5 106.75]); ...
    trimLog(LOG(7), [307 307.4]); ...
    ]);
% Really bad
DATA(3) = packStruct([...
    trimLog(LOG(2), [71.3 72]); ...
    trimLog(LOG(3), [174.1 175]);...
    trimLog(LOG(4), [773.5 774.5]); ...
    trimLog(LOG(5), [112.2 114.5]); ...
    trimLog(LOG(6), [106.75 109]); ...
    trimLog(LOG(7), [307.4 308.5]); ...
    ]);
save('SampleLogsSafetyAnalysis', 'LOG', 'DATA')
%}

load('SampleLogsSafetyAnalysis', 'LOG', 'DATA')

%%
% Define a bunch of coordinates
Tq  = eye(13);

Tq1 = Tq([4 6],:);
Tq2 = Tq([5 7],:);
Tqgr1 = Tq([8 11],:);
Tqgr2 = Tq([9 12],:);

TqLA = (Tq1 + Tq2)/2;
TqKA = Tq2 - Tq1;
TqgrLA = (Tqgr1 + Tqgr2)/2;
TqgrKA = Tqgr2 - Tqgr1;

Tqsp1 = Tqgr1 - Tq1;
Tqsp2 = Tqgr2 - Tq2;
TqspLA = TqgrLA - TqLA; % = (Tqsq1 + Tqsp2)/2
TqspKA = TqgrKA - TqKA; % = Tqsp2 - Tqsp1

Tq3  = Tq([10 13],:);
Tq3RL = [1 1]*Tq3;
TqDLA = [1 -1]*TqLA;

TqxT = Tq(3,:);
TqyT = Tq(2,:);
Ttheta = [1;1]*TqxT + TqLA;
Tthetagr = [1;1]*TqxT + TqgrLA;


% Collect all coordinates that we want to plot
Coords.q1 = struct('T', Tq1, 'Lims', [100	200	-400	600	160	180]);
Coords.q2 = struct('T', Tq2, 'Lims', [160	260	-400	500	200	220]);
Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-400	500	180	180]);
Coords.qKA = struct('T', TqKA, 'Lims', [15	90	-500	500	30	60]);
Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	200	-400	600	160	180]);
Coords.qgr2 = struct('T', Tqgr2, 'Lims', [160	260	-400	500	200	220]);
Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-400	500	180	180]);
Coords.qgrKA = struct('T', TqgrKA, 'Lims', [15	90	-500	500	30	60]);
Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-2	4	-200	300	-1	3]);
Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-6	2	-400	200	-2	1]);
Coords.qspLA = struct('T', TqspLA, 'Lims', [-3	3	-300	300	-1	1]);
Coords.qspKA = struct('T', TqspKA, 'Lims', [-8	3	-600	500	-2	1]);
Coords.q3 = struct('T', Tq3, 'Lims', [-20 15 -250 250 -20 15]);
Coords.qDLA = struct('T', TqDLA, 'Lims', [-45 45 -400 400 -25 25]);
Coords.q3RL = struct('T', Tq3RL, 'Lims', [-25 30 -300 300 -25 30]);
Coords.qxT = struct('T', TqxT, 'Lims', [-30 15 -150 150 -20 0]);
Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -150 150 -10 10]);
Coords.theta = struct('T', Ttheta, 'Lims', [140 220 -300 300 160 200]);
Coords.thetagr = struct('T', Tthetagr, 'Lims', [140 220 -300 300 160 200]);

%
F0 = 0;
CoordList = fieldnames(Coords);
CoordName = @(k) CoordList{k}(1:end);
plotLims = @(Lims) plot(Lims([1 1 6 2 2 5 1]), [0 Lims([4 4]) 0 Lims([3 3]) 0], 'k', 'LineWidth', 2);

for k=1:length(CoordList)
    if mod(k-1,4)==0, figure(F0+floor(k/4)+1); clf; set(gcf, 'Name', CoordName(k)); end
    subplot(2,2,mod(k-1,4)+1);
    plot(DATA(1).q*Coords.(CoordList{k}).T.'*180/pi, DATA(1).dq*Coords.(CoordList{k}).T.'*180/pi, '.b'); hold on;
    plot(DATA(2).q*Coords.(CoordList{k}).T.'*180/pi, DATA(2).dq*Coords.(CoordList{k}).T.'*180/pi, '.m');
    plot(DATA(3).q*Coords.(CoordList{k}).T.'*180/pi, DATA(3).dq*Coords.(CoordList{k}).T.'*180/pi, '.r'); 
    if length(Coords.(CoordList{k}).Lims)==6
        plotLims(Coords.(CoordList{k}).Lims); 
    end
    hold off;
    xlabel([CoordName(k) ' (deg)']);
    ylabel(['d' CoordName(k) ' (deg)']);
end


%% Complex limits

% Define a function to create the plots
plotData = @(fx, fy) [plot(fx(DATA(1)), fy(DATA(1)), '.b'); plot(fx(DATA(2)), fy(DATA(2)), '.m'); plot(fx(DATA(3)), fy(DATA(3)), '.r')];

% Difference in LA versus sum of Hip angles
fHipSum = @(L) L.q*Tq3RL.'*180/pi;
fDiffLA = @(L) L.q*TqDLA.'*180/pi;
figure(F0+10); clf; hold on;
plotData(fDiffLA, fHipSum);
xlabel('qLAR - qLAL (deg)');
ylabel('q3R + q3L (deg)');


%% Update the spreadsheet
xlsFile = 'D:\bgbuss\biped\data\MARLOSafetyLimits.xlsx';

xlsFields1 = {'q1', 'q2', 'qLA', 'qKA', 'qgr1', 'qgr2', 'qgrLA', 'qgrKA', 'qsp1', 'qsp2', 'qspLA', 'qspKA', 'q3'}.';
Data1 = num2cell(cell2mat(cellfun(@(f) Coords.(f).Lims, xlsFields1, 'Unif', 0)));
xlsFields2 = {'q3RL', 'qxT', 'qyT', 'theta', 'thetagr'}.';
Data2 = num2cell(cell2mat(cellfun(@(f) Coords.(f).Lims, xlsFields2, 'Unif', 0)));

%{
xlswrite(xlsFile, Data1, 'Sheet1', 'D6:I18')
xlswrite(xlsFile, Data2, 'Sheet1', 'D21:I25')
winopen(xlsFile);
%}

%% Write safety check function
safetyFun = 'MARLOBasicSafetyLimits';
filename = fullfile(fileparts(which('MARLOSafety')), [safetyFun '.m']);
fid = fopen(filename, 'w');
if (fid ~= -1)
    %fprintf(fid, 'function [violation, message] = %s(q, dq) %%#codegen\n', safetyFun);
    fprintf(fid, 'function [violation, qmin, qmax, dqmin, dqmax, qminv, qmaxv, T] = %s(q, dq) %%#codegen\n', safetyFun);
    fprintf(fid, '\t%% %s Checks to see if the configuration and velocity satisfy basic safety limits.\n', upper(safetyFun));
    %fprintf(fid, '\tviolation = true(%d,1);\n', length(CoordList));
    %fprintf(fid, '\tmessage   = cell(%d,1);\n', length(CoordList));
    fprintf(fid, '\n');
    
    fprintf(fid, '\tT = [...\n');
    for k=1:length(CoordList)
        fprintf(fid, '\t\t... %% %s\n', CoordList{k});
        fprintf(fid, '\t\t%s; \n', regexprep(mat2str(Coords.(CoordList{k}).T), {'[[]]', ';'}, {'', ';\n\t\t'}));
    end
    fprintf(fid, '\t];\n');
    fprintf(fid, '\n');
    LimNames = {'qmin', 'qmax', 'dqmin', 'dqmax', 'qminv', 'qmaxv'};
    LimComments = {'minimum q', 'maximum q','minimum dq','maximum dq','minimum q at full negative velocity (dqmin)','maximum q at full positive velocity (dqmax)'};
    for l=1:length(LimNames)
        fprintf(fid, '\t%s = [... %% %s\n', LimNames{l}, LimComments{l});
        for k=1:length(CoordList)
            fprintf(fid, '\t\t... %% %s\n', CoordList{k});
            fprintf(fid, '\t\t%f; \n', repmat(Coords.(CoordList{k}).Lims(l), size(Coords.(CoordList{k}).T, 1), 1));
        end
        fprintf(fid, '\t];\n');
    end
    fprintf(fid, '\n');
    fprintf(fid, '\t%% Check limits\n');
    fprintf(fid, '\tqbar = T * q * 180/pi;\n');
    fprintf(fid, '\tdqbar = T * dq * 180/pi;\n');
    fprintf(fid, '\tviolation = (qbar < qmin) | (qbar > qmax) ...\n');
    fprintf(fid, '\t\t | (dqbar < dqmin) | (dqbar > dqmax) ...\n');
    fprintf(fid, '\t\t | dqbar .* (qminv - qmin) < dqmin .* (qbar - qmin) ...\n');
    fprintf(fid, '\t\t | dqbar .* (qmax - qmaxv) > dqmax .* (qmax - qbar);\n');
    
    %{
    for k=1:length(CoordList)
        Coord = Coords.(CoordList{k});
        CoordName = CoordList{k};
        fprintf(fid, '\t%% %s\n', CoordName);
        fprintf(fid, '\t%% Limits: %s\n', mat2str(Coord.Lims));
        fprintf(fid, '\tT%s = %s;\n',CoordName, mat2str(Coord.T));
        fprintf(fid, '\t%s = T%s * q * 180/pi;\n', CoordName, CoordName);
        fprintf(fid, '\td%s = T%s * dq * 180/pi;\n', CoordName, CoordName);
        fprintf(fid, '\tviolation(%d) = any(%s < %f) || any(%s > %f) ...\n', k, CoordName, Coord.Lims(1), CoordName, Coord.Lims(2)); 
        fprintf(fid, '\t\t || any(d%s < %f) || any(d%s > %f) ...\n', CoordName, Coord.Lims(3), CoordName, Coord.Lims(4));
        if (Coord.Lims(5) > Coord.Lims(1))
            fprintf(fid, '\t\t || any(d%s < %f * (%s - %f)) ...\n', CoordName, Coord.Lims(3)/(Coord.Lims(5) - Coord.Lims(1)), CoordName, Coord.Lims(1));
        end
        if (Coord.Lims(2) > Coord.Lims(6))
            fprintf(fid, '\t\t || any(d%s > %f * (%f - %s)) ...\n', CoordName, Coord.Lims(4)/(Coord.Lims(2) - Coord.Lims(6)), Coord.Lims(2), CoordName);
        end
        fprintf(fid, '\t;\n');
        %fprintf(fid, '\tmessage{%d} = ''%s'';\n', k, ['Safety limit violation: ' CoordName]);
        fprintf(fid, '\n');
    end
    %}
    fprintf(fid, 'end\n');
    fclose(fid);
    edit(safetyFun)
end


%%

for l=1:length(LOG)
    LOG(l).violation = false(length(LOG(l).t),1);
    LOG(l).violationOld = false(length(LOG(l).t),1);
    for k=1:length(LOG(l).violation)
        LOG(l).violation(k) = any(MARLOSafetyLimits(LOG(l).q(k,:).', LOG(l).dq(k,:).'));
        LOG(l).violationOld(k) = any(MARLOSafetyLimitsOld(LOG(l).q(k,:).'));
    end
    
    figure(20+l); clf;
    h=subplot(3,1,1:2);
    plot(LOG(l).t, LOG(l).q(:,4:7)*180/pi); hold on;
    plot(LOG(l).t, LOG(l).q(:,[8:9 11:12])*180/pi, '--');
    plot(LOG(l).t, LOG(l).violation*60+140, 'r', 'LineWidth', 2);
    plot(LOG(l).t, LOG(l).violationOld*60+140, '-.c', 'LineWidth', 2); hold off;
    
    h(2)=subplot(3,1,3);
    plot(LOG(l).t, LOG(l).q(:,[10 13])*180/pi); hold on;
    plot(LOG(l).t, LOG(l).violation*10, 'r', 'LineWidth', 2);
    plot(LOG(l).t, LOG(l).violationOld*10, '-.c', 'LineWidth', 2); hold off;
    
    linkaxes(h,'x');
end
