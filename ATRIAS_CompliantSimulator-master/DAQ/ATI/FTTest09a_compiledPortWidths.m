function p = FTTest09a_compiledPortWidths()
	p = struct('PortName',cell(6,1),'PortWidth',-1);

	% PortName: FTTest09a/FTCount
	p(1).PortName = 'FTTest09a/FTCount';
	p(1).PortWidth = 1;

	% PortName: FTTest09a/FTStatus
	p(2).PortName = 'FTTest09a/FTStatus';
	p(2).PortWidth = 8;

	% PortName: FTTest09a/FT
	p(3).PortName = 'FTTest09a/FT';
	p(3).PortWidth = 48;

	% PortName: FTTest09a/CalibrationSerial
	p(4).PortName = 'FTTest09a/CalibrationSerial';
	p(4).PortWidth = 1;

	% PortName: FTTest09a/FTInterfaceStatus
	p(5).PortName = 'FTTest09a/FTInterfaceStatus';
	p(5).PortWidth = 1;

	% PortName: FTTest09a/FTSetupStatus
	p(6).PortName = 'FTTest09a/FTSetupStatus';
	p(6).PortWidth = 1;
end
