function valid = checkModbusCRC32(D)
    % Based on MODBUS Over Serial Line
    % http://www.modbus.org/docs/PI_MBUS_300.pdf
    
    D0 = uint32(D);
    receivedCRC = D0(end-1:end);
    computedCRC = uint32(computeModbusCRC32(D0(1:end-2)));
    
    % COMPARE
    valid = all(receivedCRC == computedCRC);
end    
