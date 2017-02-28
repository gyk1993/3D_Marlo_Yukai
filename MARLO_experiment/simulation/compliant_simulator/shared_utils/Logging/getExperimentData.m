function [time, output, status, log, datalogfilename] = getExperimentData(tg, gui, time, output, status)
    
    % Get data from target object
    if nargin<4
        time   = tg.TimeLog;
        output = tg.OutputLog;
    end
    
    if nargin<5
        status.Application = tg.Application;
        status.ExecTime    = tg.ExecTime;
        status.MaxTET      = tg.MaxTET;
        status.AvgTET      = tg.AvgTET;
        status.MinTET      = tg.MinTET;
        status.NumLogWraps = tg.NumLogWraps;
        status.SampleTime  = tg.SampleTime;
        status.SessionTime = tg.SessionTime;
        status.AppSummary  = getmdlsummary(status.Application);
        status.TET         = tg.TETLog;
        if tg.NumParameters <= 500
            status.Parameters  = getModelParameters(tg);
        else
            status.Parameters = [];
            warning('Not logging model parameters because the number of parameters is greater than 500.')
        end
        
        status.FootType = '';
        status.PowerSource = '';
        status.Goal = '';
        status.Results = '';
        status.HardwareIssues = '';
    end
    
    % Create log directory and copy files to it
    logname = 'Experiment';
    [logdir, lognum, parentlogdir] = getlogdir(logname,1);

    try
        matlabVersion = ver('MATLAB');
        if str2double(matlabVersion.Version) < 8.3 %R2014a
            zip(fullfile(logdir,[status.Application '_xpc_rtw']), [status.Application '_xpc_rtw']);
        else
            zip(fullfile(logdir,[status.Application '_slrt_rtw']), [status.Application '_slrt_rtw']);
        end
        copyfile(which([status.Application '.dlm']), logdir);
        if ~isempty(which([status.Application '.slx']))
            copyfile(which([status.Application '.slx']), logdir);
        end
        if ~isempty(which([status.Application '.mdl']))
            copyfile(which([status.Application '.mdl']), logdir);
        end
        if ~isempty(which('StartCallbackWalking'))
            copyfile(which('StartCallbackWalking'), logdir);
        end
        copyfile('C:\Users\xingye\Documents\SVN\MARLO_Controllers\TransitionExp\OSUcontroller\Controller3DHZD_obj.m',logdir);    % save DDA control objective
    catch
        warning('GETEXPERIMENTDATA was unable to copy some model files to the log folder.')
    end
    
    datalogfilename  = fullfile(logdir, sprintf('%s%02d.mat',logname,lognum));
    paramfilename    = fullfile(logdir, sprintf('%s%02d_guiparams.mat',logname,lognum));
    dailylogfilename = fullfile(parentlogdir, 'dailylog.html');
    
    % Save log data
    try 
        if isstruct(time) && isempty(output)
            log = time;
        else
            log = parseModelData(time,output,status.Application);
        end
        log.Parameters = status.Parameters;
        save(datalogfilename, 'log','status');
    catch
        warning('Failed to parse data into a LOG structure. Saving raw TIME and OUTPUT instead.');
        log = [];
        save(datalogfilename, 'time','output','status');
    end
    
    
    
    % Save gui parameters
    if ~isempty(gui) && ishandle(gui)
        guivalues = getguivalues(gui);
        save(paramfilename, 'guivalues');
        try
            guiscreen = getframe(gui);
            screenfilename = regexprep(paramfilename, 'guiparams\.mat', 'guiparams.png');
            imwrite(guiscreen.cdata, screenfilename);
        catch
            warning('Failed to capture image of GUI.');
        end
    end
    
    
    % Generate log entry
    logentry = loggui(lognum, logname);
    status.FootType       = strtrim(logentry.FootType);
    status.PowerSource    = strtrim(logentry.PowerSource);
    status.Goal           = strtrim(logentry.Goal);
    status.Results        = strtrim(logentry.Results);
    status.HardwareIssues = strtrim(logentry.HardwareIssues);
    save(datalogfilename, '-append', 'status');
    
    newlognum = logentry.LogNum;
    newlogname = logentry.LogName;
    
    % Move and rename the log files if necessary
    if (newlognum~=lognum) || ~strcmp(newlogname, logname)
        [logdir, logname, lognum] = movelog(parentlogdir, logdir, logname, lognum, newlogname, newlognum);
    end
    
    % Create HTML log entry
    entry = generateLogEntry(logname, lognum, status.Application, logdir, status.PowerSource, status.FootType, status.Goal, status.Results, status.HardwareIssues);
    
    % Append to log file
    fid = fopen(dailylogfilename, 'a');
    if fid==-1
        warning('Could not open file',dailylogfilename);
        fprintf('%s', entry);
        return
    end
    
    fprintf(fid,'%s\n',entry);
    fclose(fid);
    fprintf('<a href="matlab:winopen(''%s'');">%s</a>\n',dailylogfilename,dailylogfilename);
    fprintf('<a href="matlab:edit(''%s'');">%s</a> (edit)\n',dailylogfilename,dailylogfilename);
    fprintf('<a href="matlab:winopen(''%s'');">%s</a> (open folder)\n',logdir,logdir);
end

function [logdir, logname, lognum] = movelog(parentlogdir, logdir, logname, lognum, newlogname, newlognum)
    fid = -1;
    try
        metalog = fullfile(parentlogdir,'metalog.txt');
        fid = fopen(metalog,'a');
        if (fid==-1)
            error('Could not open %s for writing.', metalog);
        end
        
        fprintf(fid, '[%s]\n', datestr(now, 'yyyy-mm-dd HH:MM:SS'));
        fprintf(fid, 'Begin renaming log %s%02d to %s%02d.\n', logname, lognum, newlogname, newlognum);
        
        newlogdir = fullfile(parentlogdir, sprintf('%s%02d',newlogname,newlognum));
        if ~exist(newlogdir,'dir')
            if movefile(logdir,newlogdir)
                fprintf(fid, 'Moved %s to %s.\n', logdir, newlogdir);
                logdir = newlogdir;
            else
                fprintf(fid, 'Failure to move %s to %s.\n', logdir, newlogdir);
                error('Failure to move directory %s to %s.', logdir, newlogdir);
            end
        else
            fprintf(fid, 'Directory %s already exists.\n', newlogdir);
            error('Directory %s already exists.', newlogdir);
        end
        
        d = dir(logdir);
        for k=1:length(d)
            filename = d(k).name;
            newfilename = regexprep(filename, sprintf('%s%02d',logname,lognum), sprintf('%s%02d',newlogname,newlognum));
            if ~isequal(filename, newfilename)
                fprintf(fid, 'Moving %s to %s...\n', filename, newfilename);
                movefile(fullfile(logdir,filename), fullfile(logdir,newfilename));
                fprintf(fid, 'Successfully moved %s to %s\n', fullfile(logdir,filename), fullfile(logdir,newfilename));
            end
        end
        fprintf(fid, '\n');
        logname = newlogname;
        lognum  = newlognum;
    catch
        fprintf(fid, 'GETEXPERIMENTDATA was unable to rename some log data and/or folders.\n\n');
        warning('GETEXPERIMENTDATA was unable to rename some log data and/or folders.');
    end
    
    if (fid~=-1)
        fclose(fid);
    end
end
