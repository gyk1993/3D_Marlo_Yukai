function p = MicrostrainIMUTest02_compiledPortWidths()
	p = struct('PortName',cell(12,1),'PortWidth',-1);

	% PortName: MicrostrainIMUTest02/EulerAngles
	p(1).PortName = 'MicrostrainIMUTest02/EulerAngles';
	p(1).PortWidth = 3;

	% PortName: MicrostrainIMUTest02/EulerAngleDerivatives
	p(2).PortName = 'MicrostrainIMUTest02/EulerAngleDerivatives';
	p(2).PortWidth = 3;

	% PortName: MicrostrainIMUTest02/Data
	p(3).PortName = 'MicrostrainIMUTest02/Data';
	p(3).PortWidth = 18;

	% PortName: MicrostrainIMUTest02/Rk
	p(4).PortName = 'MicrostrainIMUTest02/Rk';
	p(4).PortWidth = 9;

	% PortName: MicrostrainIMUTest02/AngularRate
	p(5).PortName = 'MicrostrainIMUTest02/AngularRate';
	p(5).PortWidth = 3;

	% PortName: MicrostrainIMUTest02/Accel
	p(6).PortName = 'MicrostrainIMUTest02/Accel';
	p(6).PortWidth = 3;

	% PortName: MicrostrainIMUTest02/ID
	p(7).PortName = 'MicrostrainIMUTest02/ID';
	p(7).PortWidth = 1;

	% PortName: MicrostrainIMUTest02/State
	p(8).PortName = 'MicrostrainIMUTest02/State';
	p(8).PortWidth = 1;

	% PortName: MicrostrainIMUTest02/Counter
	p(9).PortName = 'MicrostrainIMUTest02/Counter';
	p(9).PortWidth = 1;

	% PortName: MicrostrainIMUTest02/ErrorFlags
	p(10).PortName = 'MicrostrainIMUTest02/ErrorFlags';
	p(10).PortWidth = 1;

	% PortName: MicrostrainIMUTest02/EtherCATStatus
	p(11).PortName = 'MicrostrainIMUTest02/EtherCATStatus';
	p(11).PortWidth = 4;

	% PortName: MicrostrainIMUTest02/Timer
	p(12).PortName = 'MicrostrainIMUTest02/Timer';
	p(12).PortWidth = 1;
end
