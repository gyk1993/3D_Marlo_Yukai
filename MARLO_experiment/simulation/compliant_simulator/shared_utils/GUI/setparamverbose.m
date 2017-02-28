function newval = setparamverbose(tg, id, val)
    
    [a,b] = getparamname(tg, id);
    if isempty(a)
        fprintf('Setting %s to %s.\n', b, mat2str(val));
    elseif isempty(b)
        fprintf('Setting %s to %s.\n', a, mat2str(val));
    else
        fprintf('Setting %s/%s to %s.\n', a, b, mat2str(val));
    end
    newval = setparamsafe(tg, id, val);
end
