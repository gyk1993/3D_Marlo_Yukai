function [val,type] = getguival(hObject, num)
    
    val = [];
    type = '';
    
    if (nargin<2)
        num = false;
    end
    
    if isscalar(hObject) && ishandle(hObject)
        type = get(hObject, 'Type');
        
        if strcmp(type, 'uicontrol');
            type = get(hObject, 'Style');
            switch(type)
                case 'edit'
                    val = get(hObject, 'String');
                    
                case {'radiobutton', 'pushbutton', 'togglebutton', 'checkbox', 'slider', 'listbox'}
                    val = get(hObject, 'Value');
                    
                case 'text'
                    val = get(hObject, 'String');
                    
                case 'popupmenu'
                    val.String = get(hObject,'String');
                    val.Value  = get(hObject,'Value');
                    if iscell(val.String) && numel(val.String)>=val.Value
                       val.SelectedString = val.String{val.Value};
                    else
                       val.SelectedString = '';
                    end
            end
            
        elseif strcmp(type, 'uitable')
            val = get(hObject, 'Data');
        end
    end
    
    % Convert to numeric value if requested
    if (num)
        if ischar(val)
            val = str2double(val);
        elseif isstruct(val)
            val = val.Value;
        end
    end
end
