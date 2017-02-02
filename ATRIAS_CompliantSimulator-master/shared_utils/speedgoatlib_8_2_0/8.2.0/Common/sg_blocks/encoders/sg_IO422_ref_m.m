function sg_IO422_ref_m(id, slot, frequency, voltage)


    if ~isa(frequency, 'double')
        error('Frequency parameter must be of class double');
    end
    if size(frequency) == [1 1]
        if frequency < 47 || frequency > 10000
            error('Frequency value must be in the range 47..10000');
        end            
    else
        error('Frequency must be a scalar');
    end   

    if ~isa(voltage, 'double')
        error('Voltage parameter must be of class double');
    end
    if size(voltage) == [1 1] 
        if voltage < 2 || voltage > 115
            error('Voltage value must be in the range 2..115');
        end            
    else
        error('Voltage must be a scalar');
    end   
    
    maskDisplay = sg_mask('IO422', 'ref', id);
    set_param(gcb, 'MaskDisplay', maskDisplay);
       
