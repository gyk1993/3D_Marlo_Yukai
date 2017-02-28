function [excitationVoltage, vll, phase] = sg_IO422_lvdt_write_m(id, chan, showPosition, showFrequency, showVoltage, showStatus, excitationVoltage, vll, phase, optVoltage, optFrequency)

    % verify input parameters:
    
    if optVoltage ~= 0 && optVoltage ~= 115 && (optVoltage < 2 || optVoltage > 28)
      error('Optional voltage must be set to 0, 115 or between 2 and 28VRMS');
    end
    
    if optFrequency ~= 0  && (optVoltage < 47 || optVoltage > 10000)
      error('Optional frequency must be set to 0 or between 47 and 10 000Hz');
    end
    
    47 to 10,000 Hz
      
    if size(excitationVoltage) == [1, 1]
        excitationVoltage = excitationVoltage * ones(1, length(chan));
    elseif ~all(size(excitationVoltage) == [1, length(chan)])
        error(['Excitation voltage vector must be a scalar or have ' num2str(length(chan)), ' elements']);
    end


    for i = 1:length(excitationVoltage)
        if excitationVoltage(i) < 2 || excitationVoltage(i) > 28
            error('Excitation voltage vector elements must be set between 2 and 28Vrms.');
        end
    end
    
    if size(vll) == [1, 1]
        vll = vll * ones(1, length(chan));
    elseif ~all(size(vll) == [1, length(chan)])
        error(['VLL output vector must be a scalar or have ' num2str(length(chan)), ' elements']);
    end


    for i = 1:length(vll)
        if vll(i) < 2 || excitationVoltage(i) > 11.5
            error('VLL output voltage vector elements must be set between 2 and 11.5Vrms.');
        end
    end    

    if size(phase) == [1, 1]
        phase = phase * ones(1, length(chan));
    elseif ~all(size(phase) == [1, length(chan)])
        error(['Phase vector must be a scalar or have ' num2str(length(chan)), ' elements']);
    end
    
    maskDisplay = sg_mask('IO422', 'lvdt_write', id);
    
    for i = 1:length(chan)
        maskDisplay = [maskDisplay,'port_label(''input'',',num2str(i),',''','Position ', num2str(chan(i)),''');'];
    end

    
    port = 1;
    if showPosition
        maskDisplay = [maskDisplay,'port_label(''output'',',num2str(port),',''','Wrapped position',''');'];
        port = port + 1;
    end
    
    if showFrequency
        maskDisplay = [maskDisplay,'port_label(''output'',',num2str(port),',''','Wrapped frequency',''');'];
        port = port + 1;
    end
    
    if showVoltage
        maskDisplay = [maskDisplay,'port_label(''output'',',num2str(port),',''','Wrapped voltage',''');'];
        port = port + 1;
    end
    
    if showStatus
        maskDisplay = [maskDisplay,'port_label(''output'',',num2str(port),',''','Status',''');'];
        port = port + 1;
    end
        
    set_param(gcb, 'MaskDisplay', maskDisplay);

end
