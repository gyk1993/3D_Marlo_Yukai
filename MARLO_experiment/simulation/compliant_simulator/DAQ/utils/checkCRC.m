function valid = checkCRC(D0, generatorPolynomial, remainderPolynomial)
    % Loosely based on Code Fragment 3 from
    % http://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks
    
    switch class(D0)
        case 'uint8'
            N = 8;
        case 'uint16'
            N = 16;
        case 'uint32'
            N = 32;
        case 'uint64'
            N = 64;
        otherwise
            error('Cannot compute CRC for non-integer data');
    end
    
    receivedCRC = D0(end);
    D0(end) = 0;

    remainderPolynomial = bitxor(D0(1), remainderPolynomial);
    
    for k=2:length(D0)
        for l=N:-1:1
            nextbit = bitget(D0(k),l);
            if bitget(remainderPolynomial,N) % coefficient of xn-1 of remainderPolynomial = 1
                remainderPolynomial = bitxor(bitshift(remainderPolynomial,1)+nextbit, generatorPolynomial);
            else
                remainderPolynomial = bitshift(remainderPolynomial,1)+nextbit;
            end
        end
    end
    
    % COMPARE
    valid = ~bitxor(remainderPolynomial, receivedCRC);
end

