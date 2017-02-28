function tg = connectToTarget(verbose)
    
    if nargin<1
        verbose = 1;
    end
    
    IPAddress = getxpcenv('TcpIpTargetAddress');
    
    tg = [];
    SystemResponse = '';
    GoodResponse = regexprep(sprintf('Reply from %s', IPAddress), '\.', '\\.');
    
    MaxTries = 50;
    NumTries = 0;
    while isempty(regexp(SystemResponse, GoodResponse, 'once')) && NumTries < MaxTries
        if verbose
            fprintf('\nPing %s...', IPAddress);
        end
        [~,SystemResponse] = system(sprintf('ping %s -n 1', IPAddress));
        NumTries = NumTries + 1;
    end
    
    if isempty(regexp(SystemResponse, GoodResponse, 'once'))
        if verbose
            fprintf(' failed.\n');
            fprintf('%s\n', SystemResponse);
        end
        return
    else
        if verbose
            fprintf(' success.\n');
        end
    end
    
    SLRTPingResponse = '';
    MaxTries = 1;
    NumTries = 0;
    while ~strcmpi(SLRTPingResponse, 'success') && NumTries < MaxTries
        if verbose
            fprintf('SLRT ping %s...', IPAddress);
        end
        SLRTPingResponse = slrtpingtarget();
        NumTries = NumTries + 1;
    end
    
    if ~strcmpi(SLRTPingResponse, 'success')
        if verbose
            fprintf(' failed.\n');
        end
        return
    else
        if verbose
            fprintf(' success.\n');
        end
    end
    
    tg = slrt();
end
