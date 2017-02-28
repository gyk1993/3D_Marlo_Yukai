function [bandwidth, synchro, encoder, ratio, hires, rps] = sg_IO422_sd_read_m(id, showPositionOutput, showVelocityOutput, showStatusOutput, dynamic, hires, ratio, rps, bandwidth, synchro, encoder, chan)

        
        chUsed = zeros(1, 4);

        %%% check Channel vector parameter
        if size(chan,1)~=1
            error('Channel vector must be a row vector');
        end
        if ~isa(chan, 'double')
            error('Channel vector parameter must be of class double');
        end
        for i=1:length(chan)
            channel=round(chan(i));
            if channel < 1 || channel > 4
                error('Channel Vector elements have to be in the range: 1..4');
            end
            if chUsed(channel)
                error(['Channel ',num2str(channel),' already in use ']);
            else
                chUsed(channel)=1;
            end
        end
        
        if ~isa(bandwidth, 'double')
            error('Bandwidth parameter must be of class double');
        end
        if size(bandwidth) == [1 1]
            bandwidth = bandwidth * ones(size(chan));
        elseif ~all(size(bandwidth) == size(chan))
            error('Bandwidth must be a scalar or have the same number of elements as the Channel vector');
        end
        
        bandwidth = round(bandwidth);
        for i=1:length(chan)
            if bandwidth(i) ~= 0
                if (bandwidth(i) < 6 || bandwidth(i) > 1280)
                    error('Bandwidth values must be in the range 0, 6..1280');
                end
            end
        end
        
        if ~isa(synchro, 'double')
            error('Synchro/resolver parameter must be of class double');
        end
        if size(synchro) == [1 1]
            synchro = synchro * ones(size(chan));
        elseif ~all(size(synchro) == size(chan))
            error('Synchro/resolver must be a scalar or have the same number of elements as the Channel vector');
        end
        
        synchro = round(synchro);
        if ~all(ismember(synchro, [0 1]))
            error('Synchro/resolver vector elements must be 0 or 1');
        end
        
        if ~isa(encoder, 'double')
            error('Encoder vector parameter must be of class double');
        end
        if size(encoder) == [1 1]
            encoder = encoder * ones(size(chan));
        elseif ~all(size(encoder) == size(chan))
            error('Encoder vector must be a scalar or have the same number of elements as the Channel vector');
        end
        encoder = round(encoder);
        if ~all(ismember(encoder, [4 6 8 12 13 14 15 16]))
            error('Encoder vector elements must be in the range 4, 6, 8, 12..16');
        end
        
        if ~isa(rps, 'double')
            error('Max RPS vector parameter must be of class double');
        end
        if size(rps) == [1 1]
            rps = rps * ones(size(chan));
        elseif ~all(size(rps) == size(chan))
            error('Max RPS vector must be a scalar or have the same number of elements as the Channel vector');
        end
        
        for i=1:length(chan)
            if rps(i) ~= 0
                if (rps(i) < 11.9209 || rps(i) > 190.7348)
                    error('Max RPS values must be in the range 11.9209..190.7348');
                end
            end
        end

        
        if ~isa(ratio, 'double')
            error('Ratio parameter must be of class double');
        end
        ratio = round(ratio);        

        if size(ratio) == [1 1] 
            if length(chan) > 1           
                ratio = ratio * ones(1, fix(length(chan)/2));
            end
        elseif fix(length(chan)/2) ~= fix(length(ratio))
            error('Ratio vector must be a scalar or have the same number of elements as the count of pair channel'); 
        end

        for i=1:length(ratio)  
            if (ratio(i) < 1 || ratio(i) > 256)
                error('Ratio value must be in the range 1..256');
            end
        end
     
        
        if ~isa(hires, 'double')
            error('High resolution parameter must be of class double');
        end
        hires = round(hires);        

        if size(hires) == [1 1] 
            if length(chan) > 1   
                hires = hires * ones(1, fix(length(chan)/2));
            end
        elseif fix(length(chan)/2) ~= fix(length(hires))
            error('High resolution vector must be a scalar or have the same number of elements as the count of pair channel'); 
        end

        for i=1:length(hires)  
            if ~all(ismember(hires, [0 1]))
                error('High resolution vector elements must be 0 or 1');
            end
        end    
        
        % check parameters:

        if length(chan) > 1 
            if hires(1) > 0 && ratio(1) == 1
                error('High resolution is only valid with multiple speed configuration.');
            end
        end
        
        if length(chan) > 3
            if hires(2) > 0 && ratio(2) == 1
                error('High resolution is only valid with multiple speed configuration.');
            end
        end        
      
        maskDisplay = sg_mask('IO422', 'sd_read', id);
        port = 0;
        
        if showPositionOutput
           port = port + 1;
           maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(port),',''','Position',''');'];
        end
        
        if showVelocityOutput
           port = port + 1;
           maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(port),',''','Velocity',''');'];
        end
        
        if showStatusOutput
           port = port + 1;
           maskDisplay = [maskDisplay, 'port_label(''output'',',num2str(port),',''','Status',''');'];
        end   
        
        if dynamic
           maskDisplay = [maskDisplay, 'port_label(''input'',',num2str(1),',''','Max RPS',''');'];
        end   
        
        set_param(gcb, 'MaskDisplay', maskDisplay);

    

