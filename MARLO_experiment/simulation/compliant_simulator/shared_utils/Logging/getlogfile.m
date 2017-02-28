function varargout = getlogfile(parentlogdir)
    if nargin<1
        [~, ~, parentlogdir] = getlogdir();
    end
    
    dailylogfilename = fullfile(parentlogdir, 'dailylog.html');
    
    if nargout==0
        base_url = 'https://sites.google.com/a/umich.edu/atrias/experiment-planning-and-logging';
        month_url = [base_url '/' datestr(now,'yyyy-mm') '-' lower(datestr(now,'mmmm'))];
        day_url   = [month_url '/' lower(datestr(now,'yyyy-mm-dd'))];
        
        fprintf('<a href="matlab:system(''start %s'');">%s</a>\n',month_url,month_url);
        fprintf('<a href="matlab:system(''start %s'');">%s</a>\n',day_url,day_url);
        fprintf('<a href="matlab:system(''start %s'');">%s</a>\n',dailylogfilename,dailylogfilename);
        fprintf('<a href="matlab:edit(''%s'');">%s</a> (edit)\n',dailylogfilename,dailylogfilename);
    else
        varargout{1} = dailylogfilename;
    end
end