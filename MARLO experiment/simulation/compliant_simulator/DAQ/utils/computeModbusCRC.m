function CRC = computeModbusCRC(D0)
    % Based on MODBUS Over Serial Line
    % http://www.modbus.org/docs/PI_MBUS_300.pdf
    
    D0 = uint16(D0);
    
    remainderPolynomial = uint16(hex2dec('FFFF'));
    generatorPolynomial = uint16(hex2dec('A001'));
    
    for k=1:length(D0)
        remainderPolynomial = bitxor(D0(k), remainderPolynomial);
        for l=1:8
            lsb = bitget(remainderPolynomial, 1);
            remainderPolynomial = bitshift(remainderPolynomial, -1);
            if lsb
                remainderPolynomial = bitxor(remainderPolynomial, generatorPolynomial);
            end
        end
    end
    
    CRC = uint8([bitand(remainderPolynomial, 255); bitshift(remainderPolynomial, -8)]);
end    
