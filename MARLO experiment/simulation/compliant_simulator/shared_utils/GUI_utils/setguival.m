function setguival(hObject, data)
    
    if ishandle(hObject)
        if strcmp(get(hObject, 'Type'), 'uicontrol')
            
            switch(get(hObject, 'Style'))
                case {'edit', 'text'}
                    if isnumeric(data)
                        set(hObject, 'String', num2str(data));
                    elseif ischar(data)
                        set(hObject, 'String', data);
                    end
                    
                case {'radiobutton', 'pushbutton', 'togglebutton', 'checkbox', 'slider', 'listbox'}
                    set(hObject, 'Value', data);
                    
                case {'popupmenu'}
                    menuString = get(hObject,'String');
                    
                    if ~isempty(menuString) && iscell(menuString)
                        if ischar(data) && ismember(data, menuString)
                            [~,idx] = ismember(data, menuString);
                            set(hObject, 'Value', idx);
                        elseif isstruct(data) && ismember(data.SelectedString, menuString)
                            [~,idx] = ismember(data.SelectedString, menuString);
                            set(hObject, 'Value', idx);
                        end
                    elseif isstruct(data)
                        set(hObject, 'String', data.String, 'Value', data.Value);
                    end
            end
            
        elseif strcmp(get(hObject, 'Type'), 'uitable')
            set(hObject, 'Data', data);
            
        end

    end
end
