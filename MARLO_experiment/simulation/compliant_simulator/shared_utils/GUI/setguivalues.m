function setguivalues(h, data)
    gd = guidata(h);
    names = fieldnames(data);
    
    for k=1:length(names)
        if isfield(gd, names{k}) && ishandle(gd.(names{k}))
            setguival(gd.(names{k}), data.(names{k}));
        end
    end
end
