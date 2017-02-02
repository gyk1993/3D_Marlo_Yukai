function p = MicrostrainIMUTest01_compiledPortWidths()
	p = struct('PortName',cell(8,1),'PortWidth',-1);

	% PortName: MicrostrainIMUTest01/Angles
	p(1).PortName = 'MicrostrainIMUTest01/Angles';
	p(1).PortWidth = 3;

	% PortName: MicrostrainIMUTest01/Rates
	p(2).PortName = 'MicrostrainIMUTest01/Rates';
	p(2).PortWidth = 3;

	% PortName: MicrostrainIMUTest01/IMU
	p(3).PortName = 'MicrostrainIMUTest01/IMU';
	p(3).PortWidth = 18;

	% PortName: MicrostrainIMUTest01/EtherCATStatus
	p(4).PortName = 'MicrostrainIMUTest01/EtherCATStatus';
	p(4).PortWidth = 4;

	% PortName: MicrostrainIMUTest01/ErrorFlags
	p(5).PortName = 'MicrostrainIMUTest01/ErrorFlags';
	p(5).PortWidth = 1;

	% PortName: MicrostrainIMUTest01/Counter
	p(6).PortName = 'MicrostrainIMUTest01/Counter';
	p(6).PortWidth = 1;

	% PortName: MicrostrainIMUTest01/State
	p(7).PortName = 'MicrostrainIMUTest01/State';
	p(7).PortWidth = 1;

	% PortName: MicrostrainIMUTest01/ID
	p(8).PortName = 'MicrostrainIMUTest01/ID';
	p(8).PortWidth = 1;
end
