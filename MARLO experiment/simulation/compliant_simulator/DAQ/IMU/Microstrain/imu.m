function varargout = imu(cmd,rpt,arg)
    
    persistent s
    
    comport = 'COM4';
    %baudrate = 115200;
    baudrate = 4*115200;
    try
        if isempty(s)
            s = serial(comport,'BaudRate',baudrate,'DataTerminalReady','off','RequestToSend','off','InputBufferSize',80e4);
        end
        if ~strcmp(s.Status, 'open')
            fopen(s);
        end
    catch err
        A = instrfind();
        if isempty(A)
            err.getReport();
            return
        end
        fclose(A);
        delete(A);
        clear s;
        
        s = serial(comport,'BaudRate',baudrate,'DataTerminalReady','off','RequestToSend','off');
        fopen(s);
    end
    
    if nargin==0
        varargout{1} = s;
        return;
    end
    
    if nargin<2
        rpt = 1;
    end
    
    IMU_CMD_RAW_ACCEL_AND_RATE								    = 'C1';
    IMU_CMD_ACCEL_AND_RATE									    = 'C2';
    IMU_CMD_DELTA_ANG_AND_VEL   							    = 'C3';
    IMU_CMD_ORIENTATION_MATRIX   							    = 'C5';
    IMU_CMD_ORIENTATION_UPDATE    							    = 'C6';
    IMU_CMD_MAGNETOMETER_VECTOR   							    = 'C7';
    IMU_CMD_ACCEL_RATE_AND_ORIENTATION  					    = 'C8';
    IMU_CMD_WRITE_ACCEL_BIAS_CORRECTION  					    = 'C9';
    IMU_CMD_ACCEL_RATE_AND_MAGNETOMETER 					    = 'CB';
    IMU_CMD_ACCEL_RATE_MAGNETOMETER_AND_ORIENTATION 		    = 'CC';
    IMU_CMD_CAPTURE_GYRO_BIAS_CORRECTION            		    = 'CD';
    IMU_CMD_EULER_ANGLES           							    = 'CE';
    IMU_CMD_EULER_ANGLES_AND_RATES 							    = 'CF';
    IMU_CMD_TEMPERATURES           							    = 'D1';
    IMU_CMD_GYRO_STABILIZED_ACCEL_RATE_AND_MAGNETOMETER		    = 'D2';
    IMU_CMD_DELTA_ANG_AND_VEL_AND_MAGNETOMETER 				    = 'D3';
    IMU_CMD_STATIONARY_TEST 								    = 'DA';
    IMU_CMD_QUATERNION 										    = 'DF';
    IMU_CMD_READ_FIRMWARE_REV 								    = 'E9';
    
    IMU_ACK_RAW_ACCEL_AND_RATE								    = 31;
    IMU_ACK_ACCEL_AND_RATE									    = 31;
    IMU_ACK_DELTA_ANG_AND_VEL   							    = 31;
    IMU_ACK_ORIENTATION_MATRIX   							    = 43;
    IMU_ACK_ORIENTATION_UPDATE    							    = 43;
    IMU_ACK_MAGNETOMETER_VECTOR   							    = 19;
    IMU_ACK_WRITE_ACCEL_BIAS_CORRECTION  					    = 19;
    IMU_ACK_ACCEL_RATE_AND_ORIENTATION  					    = 67;
    IMU_ACK_ACCEL_RATE_AND_MAGNETOMETER 					    = 43;
    IMU_ACK_ACCEL_RATE_MAGNETOMETER_AND_ORIENTATION 		    = 79;
    IMU_ACK_CAPTURE_GYRO_BIAS_CORRECTION              		    = 19;
    IMU_ACK_EULER_ANGLES           							    = 19;
    IMU_ACK_EULER_ANGLES_AND_RATES 							    = 31;
    IMU_ACK_TEMPERATURES           							    = 15;
    IMU_ACK_GYRO_STABILIZED_ACCEL_RATE_AND_MAGNETOMETER		    = 43;
    IMU_ACK_DELTA_ANG_AND_VEL_AND_MAGNETOMETER 				    = 43;
    IMU_ACK_STATIONARY_TEST 								    = 7;
    IMU_ACK_QUATERNION 										    = 23;
    IMU_ACK_READ_FIRMWARE_REV 								    = 7;
    
    IMU_CMD_UNSET_CONTINUOUS_MODE_B0 = 'FA';
    IMU_CMD_UNSET_CONTINUOUS_MODE_B1 = '75';
    IMU_CMD_UNSET_CONTINUOUS_MODE_B2 = 'B4';
    
    IMU_CMD_SET_CONTINUOUS_MODE_B0 = 'C4';
    IMU_CMD_SET_CONTINUOUS_MODE_B1 = 'C1';
    IMU_CMD_SET_CONTINUOUS_MODE_B2 = '29';
    
    IMU_CMD_SOFT_RESET_B0 = 'FE';
    IMU_CMD_SOFT_RESET_B1 = '9E';
    IMU_CMD_SOFT_RESET_B2 = '3A';
    
    
    switch (cmd)
        case IMU_CMD_RAW_ACCEL_AND_RATE
            D = imu_cmd(s, cmd, IMU_ACK_RAW_ACCEL_AND_RATE, rpt);
            varargout = parseBytes(D,[3 3 1]);
            
        case IMU_CMD_ACCEL_AND_RATE
            D = imu_cmd(s, cmd, IMU_ACK_ACCEL_AND_RATE, rpt);
            varargout = parseBytes(D,[3 3 1]);
            
        case IMU_CMD_DELTA_ANG_AND_VEL
            D = imu_cmd(s, cmd, IMU_ACK_DELTA_ANG_AND_VEL, rpt);
            varargout = parseBytes(D,[3 3 1]);
            
        case IMU_CMD_ORIENTATION_MATRIX
            D = imu_cmd(s, cmd, IMU_ACK_ORIENTATION_MATRIX, rpt);
            varargout = parseBytes(D,[9 1]);
            
        case IMU_CMD_ORIENTATION_UPDATE
            D = imu_cmd(s, cmd, IMU_ACK_ORIENTATION_UPDATE, rpt);
            varargout = parseBytes(D,[9 1]);
            
        case IMU_CMD_MAGNETOMETER_VECTOR
            D = imu_cmd(s, cmd, IMU_ACK_MAGNETOMETER_VECTOR, rpt);
            varargout = parseBytes(D,[3 1]);
            
        case IMU_CMD_ACCEL_RATE_AND_ORIENTATION
            D = imu_cmd(s, cmd, IMU_ACK_ACCEL_RATE_AND_ORIENTATION, rpt);
            varargout = parseBytes(D,[3 3 9 1]);
            
        case IMU_CMD_ACCEL_RATE_AND_MAGNETOMETER
            D = imu_cmd(s, cmd, IMU_ACK_ACCEL_RATE_AND_MAGNETOMETER, rpt);
            varargout = parseBytes(D,[3 3 3 1]);
            
        case IMU_CMD_ACCEL_RATE_MAGNETOMETER_AND_ORIENTATION
            D = imu_cmd(s, cmd, IMU_ACK_ACCEL_RATE_MAGNETOMETER_AND_ORIENTATION, rpt);
            varargout = parseBytes(D,[3 3 3 9 1]);
            
        case IMU_CMD_EULER_ANGLES
            D = imu_cmd(s, cmd, IMU_ACK_EULER_ANGLES, rpt);
            varargout = parseBytes(D,[3 1]);
        
        case IMU_CMD_EULER_ANGLES_AND_RATES
            D = imu_cmd(s, cmd, IMU_ACK_EULER_ANGLES_AND_RATES, rpt);
            varargout = parseBytes(D,[3 3 1]);
            
        case IMU_CMD_TEMPERATURES
            D = imu_cmd(s, cmd, IMU_ACK_TEMPERATURES, rpt);
            varargout = {D}; %parseBytes(D,[3 1]);
            
        case IMU_CMD_GYRO_STABILIZED_ACCEL_RATE_AND_MAGNETOMETER
            D = imu_cmd(s, cmd, IMU_ACK_GYRO_STABILIZED_ACCEL_RATE_AND_MAGNETOMETER, rpt);
            varargout = parseBytes(D,[3 3 3 1]);
            
        case IMU_CMD_DELTA_ANG_AND_VEL_AND_MAGNETOMETER
            D = imu_cmd(s, cmd, IMU_ACK_DELTA_ANG_AND_VEL_AND_MAGNETOMETER, rpt);
            varargout = parseBytes(D,[3 3 3 1]);
            
        case IMU_CMD_STATIONARY_TEST
            D = imu_cmd(s, cmd, IMU_ACK_STATIONARY_TEST, rpt);
            varargout = {D}; %parseBytes(D,[3 1]);
            
        case IMU_CMD_QUATERNION
            D = imu_cmd(s, cmd, IMU_ACK_QUATERNION, rpt);
            varargout = parseBytes(D,[4 1]);
            
        case IMU_CMD_READ_FIRMWARE_REV
            D = imu_cmd(s, cmd, IMU_ACK_READ_FIRMWARE_REV, rpt);
            varargout{1} = parseUint32(D);
            
        case IMU_CMD_WRITE_ACCEL_BIAS_CORRECTION
            cmd = [hex2dec(['C9'; 'B7'; '44']); ...
                   fromSingle(arg(:))];
            D = imu_cmd(s, cmd, IMU_ACK_WRITE_ACCEL_BIAS_CORRECTION, rpt);
            varargout = parseBytes(D,[3 1]);
            
        case IMU_CMD_CAPTURE_GYRO_BIAS_CORRECTION
            cmd = [hex2dec(['CD'; 'C1'; '29']); ...
                   fromUint16(arg)];
            D = imu_cmd(s, cmd, IMU_ACK_CAPTURE_GYRO_BIAS_CORRECTION, rpt, arg/1000);
            varargout = parseBytes(D,[3 1]);
            
        case 'D0'
            cmd = [hex2dec(['D0'; 'C1'; '29']); ...
                   fromUint16(arg)];
            D = imu_cmd(s, cmd, 9, rpt, arg/1000);
            varargout{1} = parseUint16(D(1:2));
            varargout(2) = parseBytes(D(3:6),1);
            
        case IMU_CMD_UNSET_CONTINUOUS_MODE_B0
            cmd = [IMU_CMD_UNSET_CONTINUOUS_MODE_B0;
                   IMU_CMD_UNSET_CONTINUOUS_MODE_B1;
                   IMU_CMD_UNSET_CONTINUOUS_MODE_B2];
            D = imu_cmd(s, cmd, 0);
            
        case IMU_CMD_SET_CONTINUOUS_MODE_B0
            cmd = [IMU_CMD_SET_CONTINUOUS_MODE_B0;
                   IMU_CMD_SET_CONTINUOUS_MODE_B1;
                 IMU_CMD_SET_CONTINUOUS_MODE_B2];
            D = imu_cmd(s, cmd, 0);
    
        case IMU_CMD_SOFT_RESET_B0
            cmd = [IMU_CMD_SOFT_RESET_B0;
                   IMU_CMD_SOFT_RESET_B1;
                   IMU_CMD_SOFT_RESET_B2];
            D = imu_cmd(s, cmd, 0);
    end
end

function D = imu_cmd(s, cmd, bytes, rpt, wait)
    if (nargin<5)
        wait = 0;
    end
    if (nargin<4)
        rpt = 1;
    end
    if ischar(cmd)
        cmd = hex2dec(cmd);
    end
    D = zeros(bytes,rpt);
    
    K=0;
    while rpt>0
        n = min(rpt,min(20,ceil(1000/bytes)));
        rpt = rpt - n;
        fwrite(s, repmat(cmd, n, 1));
        if (wait>0)
            pause(wait);
        end
        for k=1:n
            tmp = fread(s,bytes);
            D(:,K+k) = tmp;
            
            if (bytes>=3)
                if (D(1,k)~=cmd(1))
                    warning('Response header byte does not match command header byte.')
                end
                computedChecksum = mod(sum(D(1:end-2,k)),2^16);
                receivedChecksum = 2^8*D(end-1,k)+D(end,k);
                if (receivedChecksum~=computedChecksum)
                    warning('Invalid checksum.')
                end
            end
        end
        K = K+n;
    end
    if (bytes>=3)
        D = D(2:end-2,:);
    end
end

function C = parseBytes(D, N)
    D = [parseSingle(D(1:end-4,:)); parseUint32(D(end-3:end,:))/62500];
    C = mat2cell(D,N);
end

function S = parseSingle(D)
    S = zeros(size(D,1)/4, size(D,2));
    for k=1:size(D,2)
        S(:,k) = double(typecast(uint8(reshape(flipud(reshape(D(:,k),4,[])), [], 1)),'single'));
    end
end

function S = parseUint32(D)
    S = zeros(size(D,1)/4, size(D,2));
    for k=1:size(D,2)
        S(:,k) = double(typecast(uint8(reshape(flipud(reshape(D(:,k),4,[])), [], 1)),'uint32'));
    end
end

function S = parseUint16(D)
    S = zeros(size(D,1)/2, size(D,2));
    for k=1:size(D,2)
        S(:,k) = double(typecast(uint8(reshape(flipud(reshape(D(:,k),2,[])), [], 1)),'uint16'));
    end
end

function D = fromSingle(S)
    D = reshape(flipud(reshape(typecast(single(S), 'uint8'), 4, [])), [], 1);
end

function D = fromUint16(S)
    D = reshape(flipud(reshape(typecast(uint16(S), 'uint8'), 2, [])), [], 1);
end
