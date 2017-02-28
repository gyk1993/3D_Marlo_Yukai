function valid = kvhCheckCRC(D0)
    %#codegen
    
    % Loosely based on Code Fragment 3 from
    % http://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks
    D32 = parseUint32(D0);
    receivedCRC = D32(9);
    D32(9) = uint32(0);

    generatorPolynomial = uint32(79764919);   % 0x04C11DB7
    xorIn               = uint32(4294967295); % 0xFFFFFFFF
    
    % XOR IN = 0xFFFFFFFF
    remainderPolynomial = bitxor(D32(1), xorIn);
    
    for k=2:9
        for l=32:-1:1
            nextbit = bitget(D32(k),l);
            if bitget(remainderPolynomial,32) % coefficient of xn-1 of remainderPolynomial = 1
                remainderPolynomial = bitxor(bitshift(remainderPolynomial,1)+nextbit, generatorPolynomial);
            else
                remainderPolynomial = bitshift(remainderPolynomial,1)+nextbit;
            end
        end
    end
    
    % COMPARE
    valid = ~bitxor(remainderPolynomial, receivedCRC);
end

function U = parseUint32(D)
    Utmp1 = uint32(reshape(D,4,[]));
    Utmp2 = 16777216*Utmp1(1,:) + 65536*Utmp1(2,:) + 256*Utmp1(3,:) + Utmp1(4,:);
    U = Utmp2';
end
