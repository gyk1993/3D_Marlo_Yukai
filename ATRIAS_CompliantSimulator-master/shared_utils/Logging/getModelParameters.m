function Params = getModelParameters(tg)
    Params = struct();
    for k = 0:tg.NumParameters-1
        [BlockName,ParamName]=tg.getparamname(k);
        if isempty(BlockName)
            Params.(ParamName) = getparam(tg, k);
        elseif strcmpi(ParamName, 'Value')
            Params.(regexprep(BlockName, '/', '_')) = getparam(tg, k);
        else
            Params.([regexprep(BlockName, '/', '_') '_' ParamName]) = getparam(tg, k);
        end
    end
end
