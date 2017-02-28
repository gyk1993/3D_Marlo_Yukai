function valid = checkModbusCRC(D)
    % Based on MODBUS Over Serial Line
    % http://www.modbus.org/docs/PI_MBUS_300.pdf
    
    D0 = uint16(D);
    receivedCRC = D0(end-1:end);
    computedCRC = computeModbusCRC(D0(1:end-2));
    
    % COMPARE
    valid = all(receivedCRC == computedCRC);
end    
