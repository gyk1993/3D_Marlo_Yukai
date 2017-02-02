function [Status, SerialBuffer, SerialBufferEnd] = readFromBuffer(ModbusFunction, ResponseLength, SerialIn, SerialBuffer, SerialBufferEnd) %#codegen
    % Insert the new data into the SerialBuffer
    numNewBytes = min(length(SerialIn), SerialIn(1));
    SerialBuffer(SerialBufferEnd + (1:numNewBytes)) = SerialIn(1 + (1:numNewBytes));
    SerialBufferEnd = SerialBufferEnd + numNewBytes;
    
    Status = 0;
    if (SerialBuffer(1) == ModbusFunction) && (SerialBufferEnd == 4 + ResponseLength)
        Status = 1;
    elseif (SerialBuffer(1) == ModbusFunction+128) && (SerialBufferEnd == 2)
        Status = -1;
    end
end
