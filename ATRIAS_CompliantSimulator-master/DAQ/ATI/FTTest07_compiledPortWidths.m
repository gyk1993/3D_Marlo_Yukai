function p = FTTest07_compiledPortWidths()
	p = struct('PortName',cell(12,1),'PortWidth',-1);

	% PortName: FTTest07/FTCount
	p(1).PortName = 'FTTest07/FTCount';
	p(1).PortWidth = 1;

	% PortName: FTTest07/FT
	p(2).PortName = 'FTTest07/FT';
	p(2).PortWidth = 48;

	% PortName: FTTest07/FTStatus
	p(3).PortName = 'FTTest07/FTStatus';
	p(3).PortWidth = 8;

	% PortName: FTTest07/ModbusResponse
	p(4).PortName = 'FTTest07/ModbusResponse';
	p(4).PortWidth = 256;

	% PortName: FTTest07/FTInterfaceStatus
	p(5).PortName = 'FTTest07/FTInterfaceStatus';
	p(5).PortWidth = 1;

	% PortName: FTTest07/SerialOut
	p(6).PortName = 'FTTest07/SerialOut';
	p(6).PortWidth = 256;

	% PortName: FTTest07/SerialIn
	p(7).PortName = 'FTTest07/SerialIn';
	p(7).PortWidth = 256;

	% PortName: FTTest07/Calibration
	p(8).PortName = 'FTTest07/Calibration';
	p(8).PortWidth = 188;

	% PortName: FTTest07/StreamingMode
	p(9).PortName = 'FTTest07/StreamingMode';
	p(9).PortWidth = 1;

	% PortName: FTTest07/ModbusCommand
	p(10).PortName = 'FTTest07/ModbusCommand';
	p(10).PortWidth = 256;

	% PortName: FTTest07/FTSetupStatus
	p(11).PortName = 'FTTest07/FTSetupStatus';
	p(11).PortWidth = 1;

	% PortName: FTTest07/Gauge
	p(12).PortName = 'FTTest07/Gauge';
	p(12).PortWidth = 48;
end
