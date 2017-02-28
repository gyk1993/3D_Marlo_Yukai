%% UpdateSafetyLimits

SelectBasicLimits = 5;

%% Define coordinates
%
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

switch SelectBasicLimits
    % Collect all coordinates and limits in a structure
    % Lims: [qmin qmax dqmin dqmax qminv qmaxv]    
    case 5
        Coords.q1 = struct('T', Tq1, 'Lims', [100	200	-600	600	130	180]);
        Coords.q2 = struct('T', Tq2, 'Lims', [160	260	-600	500	200	220]);
        Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qKA = struct('T', TqKA, 'Lims', [40	110	-500	500	60	90]);
        Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	200	-600	600	130	180]);
        Coords.qgr2 = struct('T', Tqgr2, 'Lims', [160	260	-600	500	200	220]);
        Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qgrKA = struct('T', TqgrKA, 'Lims', [40	110	-500	500	60	90]);
        Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-6	10	-200	300	-1	3]);
        Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-10	3	-400	200	-6	1]);
        Coords.qspLA = struct('T', TqspLA, 'Lims', [-3	3	-300	300	-1	1]);
        Coords.qspKA = struct('T', TqspKA, 'Lims', [-20	10	-600	500	-2	1]);
        Coords.q3 = struct('T', Tq3, 'Lims', [-20 15 -250 250 -20 15]);
        Coords.qDLA = struct('T', TqDLA, 'Lims', [-45 45 -400 400 -25 25]);
        Coords.q3RL = struct('T', Tq3RL, 'Lims', [-25 30 -300 300 -25 30]);
        Coords.qxT = struct('T', TqxT, 'Lims', [-30 30 -150 150 -20 20]);
        Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -150 150 -10 10]);
        Coords.theta = struct('T', Ttheta, 'Lims', [140 220 -300 300 160 200]);
        Coords.thetagr = struct('T', Tthetagr, 'Lims', [140 220 -300 300 160 200]);
        
        suffix = '5';
    
    case 4
        Coords.q1 = struct('T', Tq1, 'Lims', [100	240	-600	600	140	200]);
        Coords.q2 = struct('T', Tq2, 'Lims', [140	250	-600	600	180	240]);
        Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-600	600	150	200]);
        Coords.qKA = struct('T', TqKA, 'Lims', [25	180	-800	800	25	140]);
        Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	240	-600	600	140	200]);
        Coords.qgr2 = struct('T', Tqgr2, 'Lims', [140	250	-600	600	180	240]);
        Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-600	600	150	200]);
        Coords.qgrKA = struct('T', TqgrKA, 'Lims', [25	180	-800	800	25	140]);
        Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-4	10	-600	600	-1	5]);
        Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-10	5	-600	600	-5	1]);
        Coords.qspLA = struct('T', TqspLA, 'Lims', [-8	5	-1000	1000	-4	1]);
        Coords.qspKA = struct('T', TqspKA, 'Lims', [-20	8	-1000	1000	-10	3]);
        Coords.q3 = struct('T', Tq3, 'Lims', [-20 15 -400 400 -20 10]);
        Coords.qDLA = struct('T', TqDLA, 'Lims', [-70 70 -600 600 -50 50]);
        Coords.q3RL = struct('T', Tq3RL, 'Lims', [-40 25 -600 600 -40 20]);
        Coords.qxT = struct('T', TqxT, 'Lims', [-25 25 -250 250 -20 20]);
        Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -250 250 -10 10]);
        Coords.theta = struct('T', Ttheta, 'Lims', [120 240 -600 600 140 220]);
        Coords.thetagr = struct('T', Tthetagr, 'Lims', [120 240 -600 600 140 220]);
        
        suffix = '4';
        
        case 3
        Coords.q1 = struct('T', Tq1, 'Lims', [100	240	-600	600	140	200]);
        Coords.q2 = struct('T', Tq2, 'Lims', [140	250	-600	600	180	240]);
        Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-600	600	150	200]);
        Coords.qKA = struct('T', TqKA, 'Lims', [25	180	-800	800	25	140]);
        Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	240	-600	600	140	200]);
        Coords.qgr2 = struct('T', Tqgr2, 'Lims', [140	250	-600	600	180	240]);
        Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-600	600	150	200]);
        Coords.qgrKA = struct('T', TqgrKA, 'Lims', [25	180	-800	800	25	140]);
        Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-4	10	-600	600	-1	5]);
        Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-10	5	-600	600	-5	1]);
        Coords.qspLA = struct('T', TqspLA, 'Lims', [-8	5	-1000	1000	-4	1]);
        Coords.qspKA = struct('T', TqspKA, 'Lims', [-20	8	-1000	1000	-10	3]);
        Coords.q3 = struct('T', Tq3, 'Lims', [-20 12 -400 400 -20 8]);
        Coords.qDLA = struct('T', TqDLA, 'Lims', [-70 70 -600 600 -50 50]);
        Coords.q3RL = struct('T', Tq3RL, 'Lims', [-40 25 -600 600 -40 20]);
        Coords.qxT = struct('T', TqxT, 'Lims', [-25 25 -250 250 -20 20]);
        Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -250 250 -10 10]);
        Coords.theta = struct('T', Ttheta, 'Lims', [120 240 -600 600 140 220]);
        Coords.thetagr = struct('T', Tthetagr, 'Lims', [120 240 -600 600 140 220]);
        
        suffix = '3';
    
    case 2
        Coords.q1 = struct('T', Tq1, 'Lims', [100	200	-400	600	160	180]);
        Coords.q2 = struct('T', Tq2, 'Lims', [160	260	-400	500	200	220]);
        Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qKA = struct('T', TqKA, 'Lims', [15	90	-500	500	30	60]);
        Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	200	-400	600	160	180]);
        Coords.qgr2 = struct('T', Tqgr2, 'Lims', [160	260	-400	500	200	220]);
        Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qgrKA = struct('T', TqgrKA, 'Lims', [15	90	-500	500	30	60]);
        Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-2	6	-200	300	-1	3]);
        Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-6	3	-400	200	-2	1]);
        Coords.qspLA = struct('T', TqspLA, 'Lims', [-3	3	-300	300	-1	1]);
        Coords.qspKA = struct('T', TqspKA, 'Lims', [-8	3	-600	500	-2	1]);
        Coords.q3 = struct('T', Tq3, 'Lims', [-20 15 -250 250 -20 15]);
        Coords.qDLA = struct('T', TqDLA, 'Lims', [-45 45 -400 400 -25 25]);
        Coords.q3RL = struct('T', Tq3RL, 'Lims', [-25 30 -300 300 -25 30]);
        Coords.qxT = struct('T', TqxT, 'Lims', [-30 30 -150 150 -20 20]);
        Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -150 150 -10 10]);
        Coords.theta = struct('T', Ttheta, 'Lims', [140 220 -300 300 160 200]);
        Coords.thetagr = struct('T', Tthetagr, 'Lims', [140 220 -300 300 160 200]);
        
        suffix = '2';
        
    otherwise
        % Collect all coordinates and limits in a structure
        % Lims: [qmin qmax dqmin dqmax qminv qmaxv]
        Coords.q1 = struct('T', Tq1, 'Lims', [100	200	-400	600	160	180]);
        Coords.q2 = struct('T', Tq2, 'Lims', [160	260	-400	500	200	220]);
        Coords.qLA = struct('T', TqLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qKA = struct('T', TqKA, 'Lims', [15	100	-500	500	30	80]);
        Coords.qgr1 = struct('T', Tqgr1, 'Lims', [100	200	-400	600	140	180]);
        Coords.qgr2 = struct('T', Tqgr2, 'Lims', [160	260	-400	500	200	220]);
        Coords.qgrLA = struct('T', TqgrLA, 'Lims', [130	230	-400	500	180	180]);
        Coords.qgrKA = struct('T', TqgrKA, 'Lims', [15	90	-500	500	30	60]);
        Coords.qsp1 = struct('T', Tqsp1, 'Lims', [-2	6	-200	300	-1	3]);
        Coords.qsp2 = struct('T', Tqsp2, 'Lims', [-6	3	-400	200	-2	1]);
        Coords.qspLA = struct('T', TqspLA, 'Lims', [-3	3	-300	300	-1	1]);
        Coords.qspKA = struct('T', TqspKA, 'Lims', [-8	3	-600	500	-2	1]);
        Coords.q3 = struct('T', Tq3, 'Lims', [-20 15 -250 250 -20 15]);
        Coords.qDLA = struct('T', TqDLA, 'Lims', [-45 45 -400 400 -25 25]);
        Coords.q3RL = struct('T', Tq3RL, 'Lims', [-25 30 -300 300 -25 30]);
        Coords.qxT = struct('T', TqxT, 'Lims', [-30 15 -150 150 -20 0]);
        Coords.qyT = struct('T', TqyT, 'Lims', [-20 20 -150 150 -10 10]);
        Coords.theta = struct('T', Ttheta, 'Lims', [140 220 -300 300 160 200]);
        Coords.thetagr = struct('T', Tthetagr, 'Lims', [140 220 -300 300 160 200]);
        
        suffix = '';
end

CoordList = fieldnames(Coords);

%% Write safety check function
safetyFun = ['MARLOBasicSafetyLimits' suffix];
filename = fullfile(fileparts(which('MARLOSafety')), [safetyFun '.m']);
fid = fopen(filename, 'w');
if (fid ~= -1)
    fprintf(fid, 'function [violation, qmin, qmax, dqmin, dqmax, qminv, qmaxv, T] = %s(q, dq) %%#codegen\n', safetyFun);
    fprintf(fid, '\t%% %s Checks to see if the configuration and velocity satisfy basic safety limits.\n', upper(safetyFun));
    
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
    
    fprintf(fid, 'end\n');
    fclose(fid);
    edit(safetyFun)
end

%% Write a function with the coordinate names
safetyCoordFun = 'MARLOBasicSafetyCoords';
filename = fullfile(fileparts(which('MARLOSafety')), [safetyCoordFun '.m']);
fid = fopen(filename, 'w');
if (fid ~= -1)
    fprintf(fid, 'function [CoordNames] = %s()\n', safetyCoordFun);
    fprintf(fid, '\t%% %s Returns a cell array with the names of the basic safety coordinates.\n', upper(safetyCoordFun));
    
    fprintf(fid, '\n');
    
    fprintf(fid, '\tCoordNames = {...\n');
    for k=1:length(CoordList)
        if size(Coords.(CoordList{k}).T, 1)==2
            fprintf(fid, '\t\t''%sR''; ...\n', CoordList{k});
            fprintf(fid, '\t\t''%sL''; ...\n', CoordList{k});
        else
            fprintf(fid, '\t\t''%s''; ...\n', CoordList{k});
        end
    end
    fprintf(fid, '\t};\n');
    fprintf(fid, '\n');
    fprintf(fid, 'end\n');
    fclose(fid);
    edit(safetyCoordFun)
end
