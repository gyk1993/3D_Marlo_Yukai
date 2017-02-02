function p = SingleLeg_R2014a_compiledPortWidths()
	p = struct('PortName',cell(18,1),'PortWidth',-1);

	% PortName: EtherCATStatus
	p(1).PortName = 'EtherCATStatus';
	p(1).PortWidth = 6;

	% PortName: LegEncoder
	p(2).PortName = 'LegEncoder';
	p(2).PortWidth = 1;

	% PortName: MotorEncoder
	p(3).PortName = 'MotorEncoder';
	p(3).PortWidth = 1;

	% PortName: ToeSensor
	p(4).PortName = 'ToeSensor';
	p(4).PortWidth = 1;

	% PortName: LimitSwitch
	p(5).PortName = 'LimitSwitch';
	p(5).PortWidth = 1;

	% PortName: ID
	p(6).PortName = 'ID';
	p(6).PortWidth = 1;

	% PortName: State
	p(7).PortName = 'State';
	p(7).PortWidth = 1;

	% PortName: Counter
	p(8).PortName = 'Counter';
	p(8).PortWidth = 1;

	% PortName: ErrorFlags
	p(9).PortName = 'ErrorFlags';
	p(9).PortWidth = 1;

	% PortName: IncEncoder
	p(10).PortName = 'IncEncoder';
	p(10).PortWidth = 1;

	% PortName: LegEncoderTimestamp
	p(11).PortName = 'LegEncoderTimestamp';
	p(11).PortWidth = 1;

	% PortName: MotorEncoderTimestamp
	p(12).PortName = 'MotorEncoderTimestamp';
	p(12).PortWidth = 1;

	% PortName: IncEncoderTimestamp
	p(13).PortName = 'IncEncoderTimestamp';
	p(13).PortWidth = 1;

	% PortName: MotorVoltage
	p(14).PortName = 'MotorVoltage';
	p(14).PortWidth = 1;

	% PortName: LogicVoltage
	p(15).PortName = 'LogicVoltage';
	p(15).PortWidth = 1;

	% PortName: Thermistors
	p(16).PortName = 'Thermistors';
	p(16).PortWidth = 6;

	% PortName: AmpMeasuredCurrent
	p(17).PortName = 'AmpMeasuredCurrent';
	p(17).PortWidth = 2;

	% PortName: KneeForce
	p(18).PortName = 'KneeForce';
	p(18).PortWidth = 2;
end
