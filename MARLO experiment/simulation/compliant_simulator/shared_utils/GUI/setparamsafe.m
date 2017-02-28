function newval = setparamsafe(tg, id, val)
    
    if ~isnumeric(val(:)) || isempty(val(:)) || any(~isfinite(val(:))) ...
            || ~isnumeric(id) || isempty(id) || any(~isfinite(id))
        warning('Empty parameter id?');
        return
    end
    
    p = setparam(tg, id, val);
    newval = p.NewValues;
end
