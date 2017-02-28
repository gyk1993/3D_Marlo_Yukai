function [Valid, T, varargout] = microstrainParsePacket(P, CMD)
    %#codegen
    P = P(:);
    
    if nargin<2
        CMD = P(1);
    end
    
    Valid = (P(1)==CMD) && verifyChecksum(P);
    
    switch CMD
        case 223 % hex2dec('DF'); (Quaternion)
            Q = parseSingle(P(2:17,:));
            T = parseUint32(P(18:21,:)) / 62500;
            varargout{1} = Q;
            
        case 195 % hex2dec('C3'); (DeltaAngle and DeltaVelocity)
            DeltaAngle = parseSingle(P(2:13,:));
            DeltaVelocity = parseSingle(P(14:25,:));
            T = parseUint32(P(26:29,:)) / 62500;
            varargout{1} = DeltaAngle;
            varargout{1} = DeltaVelocity;
            
        otherwise
            Valid = false;
    end
end

function S = parseSingle(P)
    Stmp1  = uint32(reshape(P,4,[]));
    Stmp2  = 16777216*Stmp1(1,:) + 65536*Stmp1(2,:) + 256*Stmp1(3,:) + Stmp1(4,:);
    Stmp3  = typecast(Stmp2,'single');
    S      = double(Stmp3');
end

function S = parseUint32(P)
    Stmp1  = uint32(reshape(P,4,[]));
    Stmp2  = 16777216*Stmp1(1,:) + 65536*Stmp1(2,:) + 256*Stmp1(3,:) + Stmp1(4,:);
    S      = double(Stmp2');
end

function Valid = verifyChecksum(P)
    % Calculate the checksum
    tChksum = mod(sum(P(1:end-2)), 2^16);
    % Extract the big-endian checksum from reply
    tResponseChksum = P(end-1)*256 + P(end);
    % Compare the checksums
    Valid = (tChksum == tResponseChksum);
end
