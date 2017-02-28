function sigid = getAllSignalIds(tg, pattern, replace)
    sigid = struct();
    signals = cell(tg.NumSignals, 2);
    
    for k = 0:tg.NumSignals-1
        signals{k,1} = tg.getsignalname(k);
        signals{k,2} = k;
    end
    
    FieldName = regexprep(SignalName, pattern, replace);
    if isvarname(FieldName)
        sigid.(FieldName) = k;
    end
end
