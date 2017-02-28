function entry = generateLogEntry(expname, expnum, model, logfilename, powersource, foottype, goal, results, hardwareissues)

    if nargin<4
        logfilename = '';
    end
    if nargin<5
        powersource = '';
    end
    if nargin<6
        foottype = '';
    end
    if nargin<7
        goal = '';
    end
    if nargin<8
        results = '';
    end
    if nargin<9
        hardwareissues =  '';
    end
    
    base_url = 'https://sites.google.com/a/umich.edu/atrias/experiment-planning-and-logging';
    month_url = [base_url '/' datestr(now,'yyyy-mm') '-' lower(datestr(now,'mmmm'))];
    day_url   = [month_url '/' lower(datestr(now,'yyyy-mm-dd'))];
    
    entry = [...
        sprintf('<u><b>%s #%d</b></u>\n',expname,expnum) ...
        sprintf('<div><b>Time:</b> %s<br></div>\n',datestr(now,'HH:MM')) ...
        sprintf('<div><b>Power source:</b> %s<br></div>\n',powersource) ...
        sprintf('<div><b>Foot type:</b> %s<br></div>\n',foottype) ...
        sprintf('<div><b>Controller:</b> %s<br></div>\n',model) ...
        sprintf('<div><b>Goal:</b> %s<br></div>\n',goal) ...
        sprintf('<div><b>Results:</b> %s<br></div>\n',results) ...
        sprintf('<div><b>Hardware Issues:</b> %s<br></div>\n',hardwareissues) ...
        sprintf('<div><b>Log file location:</b> %s<br></div>\n',logfilename) ...
        sprintf('<br>\n') ...
        ];
    
    fprintf('\n');
    %fprintf('%s\n',entry);
    
    %clipboard('copy', entry);
    %fprintf('<a href="matlab:">LOG ENTRY COPIED TO CLIPBOARD</a>\n');
    %fprintf('<a href="matlab:system(''start %s'');">%s</a>\n',month_url,month_url);
    %fprintf('<a href="matlab:system(''start %s'');">%s</a>\n',day_url,day_url);
    %system(sprintf('start %s',day_url));
end
