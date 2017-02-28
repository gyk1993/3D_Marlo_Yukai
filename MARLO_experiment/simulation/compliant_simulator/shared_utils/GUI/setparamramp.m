function [canceled,curval,ok] = setparamramp(tg, id, val, rate, option)
    
    canceled = true;
    curval   = [];
    ok       = false;
    
    if nargin<5
        option = 'silent';
    end
    if nargin<4 || isempty(rate)
        rate = 1e3;
    end
    
    if ~isnumeric(val(:)) || isempty(val(:)) || any(~isfinite(val(:))) ...
            || ~isnumeric(id) || isempty(id) || any(~isfinite(id))
        return
    end
    
    canceled = false;
    
    % step frequency
    Ts = 0.05;
    
    % design ramp starting at current value and ending at VAL
    curval = getparam(tg, id);
    ramp = cell(length(curval), 1);
    for l=1:length(curval)
        ramp{l}   = [curval(l):(sign(val(l)-curval(l))*rate*Ts):val(l) val(l)];
    end
    L = cellfun(@length, ramp);
    Lmax = max(L);
    ramp = cell2mat(cellfun(@(r) [r r(end)*ones(1,Lmax-length(r))], ramp, 'UniformOutput', 0));
    
    % Double-check that these calculations have not resulted in invalid
    % values
    if ~isnumeric(ramp) || isempty(ramp) || any(~isfinite(ramp(:)))
        return
    end
    
    % Create waitbar
    if option(1)=='v' % verbose
        h=waitbar(0,'Ramping parameter values...','CreateCancelBtn',@(h,e)setappdata(get(h,'Parent'),'canceling',1));
        setappdata(h,'canceling',0);
    end
    
    ok = true;
    
    try
        % Apply the ramp
        for k=1:Lmax
            p=setparam(tg, id, ramp(:,k));
            pause(Ts);
            
            if option(1)=='v'
                if getappdata(h,'canceling')
                    p=setparam(tg, id, curval);
                    canceled = true;
                    break
                else
                    waitbar(k/Lmax,h);
                end
            end
        end
        
    catch
        ok = false;
    end
    
    % Delete waitbar
    if option(1)=='v'
        delete(h);
    end
    
    curval = p.NewValues;
end

