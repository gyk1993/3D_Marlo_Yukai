function [Valid, SerialBuffer, SerialBufferEnd] = bufferModbusData(LastModbusFunction, ResponseLength, SerialIn, SerialBuffer, SerialBufferEnd) %#codegen
    % Insert the new data into the SerialBuffer
    numNewBytes = min(SerialIn(1), 256);
    assert(numNewBytes < 257);
    SerialBuffer(SerialBufferEnd + (1:numNewBytes)) = SerialIn(1 + (1:numNewBytes));
    SerialBufferEnd = SerialBufferEnd + numNewBytes;
    
    Valid = false; % Invalid packet
    if (SerialBuffer(2) == LastModbusFunction) && (SerialBufferEnd == 3 + ResponseLength)
        Valid = true; % Okay
    elseif (SerialBuffer(2) == LastModbusFunction+128) && (SerialBufferEnd == 5)
        Valid = true; % Exception
    end
end
