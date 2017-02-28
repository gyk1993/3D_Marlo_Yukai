function ResponseLength = getModbusResponseLength(ModbusFunction, ModbusData) %#codegen
    % Returns the expected number of bytes in a valid (error-free) response
    % to a Modbus command. These values are derived from the Modbus
    % Application Protocol Specification v1.1b
    % http://www.modbus.org/docs/Modbus_Application_Protocol_V1_1b.pdf
    
    switch (ModbusFunction)
        case 03 % Read Holding Registers
            NumReg = ModbusData(4);
            ResponseLength = 2 + 2*NumReg;
        case 06 % Write Single Register
            ResponseLength = uint16(5);
        case 16 % Write Multiple Registers
            ResponseLength = uint16(5);
        case 70 % Start Streaming
            ResponseLength = uint16(2);
        case 106 % Lock/unlock storage
            ResponseLength = uint16(2);
        otherwise
            ResponseLength = uint16(0);
    end
end
