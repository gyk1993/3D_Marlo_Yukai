function data = getguivalues(h, data, includeText)
    
    if nargin<2 || isempty(data)
        data = struct();
    end
    if nargin<3
        includeText = false;
    end
    data.GUI_NAME = get(ancestor(h,'figure'), 'Name');
    data.GUI_FILE = get(ancestor(h,'figure'), 'Name');
    
    gd = guidata(h);
    if isempty(gd)
        return
    end
    
    saveTypes = {'edit', 'radiobutton', 'pushbutton', 'togglebutton', 'checkbox', 'slider', 'listbox', 'popupmenu', 'uitable'};
    if includeText
        saveTypes = [saveTypes 'text'];
    end
    
    names = fieldnames(gd);
    for k=1:length(names)
        [val, type] = getguival(gd.(names{k}));
        if ismember(type, saveTypes)
            data.(names{k}) = val;
        end
    end
end
