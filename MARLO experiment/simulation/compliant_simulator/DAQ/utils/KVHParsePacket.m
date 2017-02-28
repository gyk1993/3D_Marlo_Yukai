function [Rotation,Acceleration,Status,Sequence,Temperature,Valid] = KVHParsePacket(P)
    %#codegen
    CMD = hex2dec(['FE';'81';'FF';'55']);
    P = P(:);
    Valid = 0;
    if all(P(1:4) == CMD(1:4))
        Valid = kvhCheckCRC_mex(P);
    end
    
    Rotation     = parseSingle(P(5:16,:));
    Acceleration = parseSingle(P(17:28,:));
    Status       = double(P(29));
    Sequence     = double(P(30));
    Temperature  = parseInt16(P(31:32)); 
end

function S = parseSingle(P)
    Stmp1  = uint32(reshape(P,4,[]));
    Stmp2  = 16777216*Stmp1(1,:) + 65536*Stmp1(2,:) + 256*Stmp1(3,:) + Stmp1(4,:);
    Stmp3  = typecast(Stmp2,'single');
    S      = double(Stmp3');
end

function S = parseInt16(P)
    Stmp1 = uint16(reshape(P,2,[]));
    Stmp2 = 256*Stmp1(1,:) + Stmp1(2,:);
    S = double(Stmp2');
end
