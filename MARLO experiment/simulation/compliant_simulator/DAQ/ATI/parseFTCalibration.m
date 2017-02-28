function Cal = parseFTCalibration(D)
    % Converts a byte stream returned from the Modbus read holding register
    % command into a F/T calibration structure defined in the Digital F/T
    % manual. This structure has the following form:
    % {
    %     uint8 CalibSerialNumber[8];
    %     uint8 CalibPartNumber[32];
    %     uint8 CalibFamilyId[4];
    %     uint8 CalibTime[20];
    %     float BasicMatrix[6][6];
    %     uint8 ForceUnits;
    %     uint8 TorqueUnits;
    %     float MaxRating[6];
    %     int32 CountsPerForce;
    %     int32 CountsPerTorque;
    %     uint16 GageGain[6];
    %     uint16 GageOffset[6];
    %     uint8 Resolution[6];
    %     uint8 Range[6];
    %     uint16 ScaleFactor16[6];
    %     uint8 UserField1[16];
    %     uint8 UserField2[16];
    %     uint8 SpareData[16];
    % }
    
    Cal.CalibSerialNumber = parseUint8(D(1:8));
    Cal.CalibPartNumber   = parseUint8(D(9:40));
    Cal.CalibFamilyId     = parseUint8(D(41:44));
    Cal.CalibTime         = parseUint8(D(45:64));
    Cal.BasicMatrix       = reshape(parseFloat(D(65:208)), 6, 6);
    Cal.ForceUnits        = parseUint8(D(209));
    Cal.TorqueUnits       = parseUint8(D(210));
    Cal.MaxRating         = parseFloat(D(211:234));
    Cal.CountsPerForce    = parseInt32(D(235:238));
    Cal.CountsPerTorque   = parseInt32(D(239:242));
    Cal.GageGain          = parseUint16(D(243:254));
    Cal.GageOffset        = parseUint16(D(255:266));
    Cal.Resolution        = parseUint8(D(267:272));
    Cal.Range             = parseUint8(D(273:278));
    Cal.ScaleFactor16     = parseUint16(D(279:290));
    Cal.UserField1        = parseUint8(D(291:306));
    Cal.UserField2        = parseUint8(D(307:322));
    Cal.SpareData         = parseUint8(D(323:338));
end

function s = parseUint8(D)
    s = double(D);
end

function d = parseFloat(D)
    u = uint32(parseUint32(D));
    f = typecast(u, 'single');
    d = double(f);
end

function u = parseUint32(D)
    D1 = double(D);
    u = D1(1:4:end)*16777216 + D1(2:4:end)*65536 + D1(3:4:end)*256 + D1(4:4:end);
end

function u = parseInt32(D)
    u = parseUint32(D); % TODO
end

function u = parseUint16(D)
    D1 = double(D);
    u = D1(1:2:end)*256 + D1(2:2:end);
end
