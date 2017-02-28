function paramid = getAllParamIds(tg)
    
    for k = 0:tg.NumParameters-1
        [BlockName,ParamName]=tg.getparamname(k);
        if isempty(BlockName)
            paramid.(ParamName) = k;
        elseif strcmpi(ParamName, 'Value')
            ParamName = regexprep(BlockName, '/', '_');
            if isvarname(ParamName)
                paramid.(ParamName) = getparam(tg, k);
            end
        end
    end
end