function p = FTTest10_compiledPortWidths()
	p = struct('PortName',cell(7,1),'PortWidth',-1);

	% PortName: FTTest10/FTCount
	p(1).PortName = 'FTTest10/FTCount';
	p(1).PortWidth = 2;

	% PortName: FTTest10/FTStatus
	p(2).PortName = 'FTTest10/FTStatus';
	p(2).PortWidth = 16;

	% PortName: FTTest10/FT
	p(3).PortName = 'FTTest10/FT';
	p(3).PortWidth = 96;

	% PortName: FTTest10/CalibrationSerial
	p(4).PortName = 'FTTest10/CalibrationSerial';
	p(4).PortWidth = 2;

	% PortName: FTTest10/FTInterfaceStatus
	p(5).PortName = 'FTTest10/FTInterfaceStatus';
	p(5).PortWidth = 2;

	% PortName: FTTest10/FTSetupStatus
	p(6).PortName = 'FTTest10/FTSetupStatus';
	p(6).PortWidth = 2;

	% PortName: FTTest10/Gauge
	p(7).PortName = 'FTTest10/Gauge';
	p(7).PortWidth = 96;
end
