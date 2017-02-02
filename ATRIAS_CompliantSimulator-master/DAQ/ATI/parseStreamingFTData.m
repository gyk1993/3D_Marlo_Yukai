function [GaugeCount, Gauge, SerialBuffer, SerialBufferEnd, GaugeStatus] = parseStreamingFTData(SerialIn, SerialBuffer, SerialBufferEnd) %#codegen
    % Insert the new data into the SerialBuffer
    numNewBytes = min(SerialIn(1), 255);
    numNewBytes = min(numNewBytes, 512-SerialBufferEnd);
    SerialBuffer(SerialBufferEnd + (1:numNewBytes)) = SerialIn(1 + (1:numNewBytes));
    SerialBufferEnd = SerialBufferEnd + numNewBytes;
    Gauge = zeros(6,8);
    GaugeStatus = zeros(8,1);
    
    SerialBufferBegin = 1;
    GaugeCount = 0;
    k = 0;
    while k < SerialBufferEnd-12
        % Verify checksum (first seven bits of last byte in packet)
        valid = CheckSample(SerialBuffer(k+(1:13)));
        
        if valid 
            % Get gauge status bit (msb of last byte in packet) if the packet is valid
            GaugeCount = GaugeCount + 1;
            Gauge(:,GaugeCount)     = ComputeGauge(SerialBuffer(k+(1:12)));
            GaugeStatus(GaugeCount) = bitget(SerialBuffer(k+13), 8);
            k = k + 13;
            SerialBufferBegin = k + 1;
        else
            k = k + 1;
        end 
    end
    
    n = (SerialBufferEnd+1) - SerialBufferBegin;
    SerialBuffer(1:n) = SerialBuffer(SerialBufferBegin:SerialBufferEnd);
    SerialBufferEnd = n;
    %GaugeStatus(8) = double(n);
end

function valid = CheckSample( sampleBytes )
    checkSum = int16(0);
    for k = 1:12
        checkSum = checkSum + int16(sampleBytes(k));
    end
    valid = bitand(checkSum, 127) == bitand(sampleBytes(13), 127);
end

function Gauge = ComputeGauge(D)
    % Convert uint8 to int16 and reorder
    % The Digital F/T board returns Gauge data in the order
    %   [G0 G2 G4 G1 G3 G5]'.
    % and we want it in the order
    %   [G0 G1 G2 G3 G4 G5].'
    
    Gauge = double( bitshift(int16(D([1 3 5 7 9 11])), 8) + int16(D([2 4 6 8 10 12])) );
    Gauge = Gauge([1 4 2 5 3 6]);
end
