function [varargout] = getlogdir(logname,create,date)
    
    if nargin<1
        logname = 'Experiment';
    end
    if nargin<2 || isempty(create)
        create = false;
    end
    if nargin<3
        date = datestr(now,'yyyy-mm-dd');
    end
    
    % Get path to root of individual log directory
    % MYLOGDIR should be a function that returns a string containing the
    % root directory where you want log files to be placed.
    logdir = mylogdir();
    
    % Check to see if the date is already included in the log dir; if not,
    % add it
    [~,logdirlast] = fileparts(logdir);
    try
        datenum(logdirlast,'yyyy-mm-dd');
    catch
        logdir = fullfile(logdir,date);
    end
    parentlogdir = logdir;
    
    % Now get the name of a subdirectory for the new experiment
    if exist(logdir,'dir')
        d1 = dir(fullfile(logdir,[logname '*']));
        d2 = d1(~cellfun(@isempty,regexp({d1.name},[logname '\d+'],'once')));
        n  = regexp({d2.name},[logname '(\d+)'],'tokens','once');
        n  = str2double([n{:}]);
        lognum = floor(max([0 n])) + 1;
    else
        lognum = 1;
        d2 = [];
    end
   
    logdir = fullfile(logdir, sprintf('%s%02d',logname,lognum));
   
    % Create the directory if necessary
    if create && ~exist(logdir,'dir')
        mkdir(logdir);
    end
    
    if nargout==0
        fprintf('<a href="matlab:winopen(''%s'');">%s</a>\n',parentlogdir,parentlogdir);
        
        for k=1:length(d2)
            fprintf('\n');
            logdir = fullfile(parentlogdir, d2(k).name);
            fprintf('<a href="matlab:winopen(''%s'');">%s</a> (open)\n',logdir, logdir);
            
            d3 = dir(fullfile(logdir,'*.mat'));
            for l=1:length(d3)
                logfile = fullfile(logdir, d3(l).name);
                fprintf('<a href="matlab:load(''%s'');">%s</a> (load)\n',logfile, logfile);
            end
        end
    else
        varargout = {logdir, lognum, parentlogdir};
    end
end
