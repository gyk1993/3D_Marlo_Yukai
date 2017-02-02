function p = KVHSerial04_compiledPortWidths()
	p = struct('PortName',cell(11,1),'PortWidth',-1);

	% PortName: KVHSerial04/R
	p(1).PortName = 'KVHSerial04/R';
	p(1).PortWidth = 3;

	% PortName: KVHSerial04/A
	p(2).PortName = 'KVHSerial04/A';
	p(2).PortWidth = 3;

	% PortName: KVHSerial04/status
	p(3).PortName = 'KVHSerial04/status';
	p(3).PortWidth = 1;

	% PortName: KVHSerial04/sequence
	p(4).PortName = 'KVHSerial04/sequence';
	p(4).PortWidth = 1;

	% PortName: KVHSerial04/temperature
	p(5).PortName = 'KVHSerial04/temperature';
	p(5).PortWidth = 1;

	% PortName: KVHSerial04/valid
	p(6).PortName = 'KVHSerial04/valid';
	p(6).PortWidth = 1;

	% PortName: KVHSerial04/Sync
	p(7).PortName = 'KVHSerial04/Sync';
	p(7).PortWidth = 37;

	% PortName: KVHSerial04/EulerAngles
	p(8).PortName = 'KVHSerial04/EulerAngles';
	p(8).PortWidth = 3;

	% PortName: KVHSerial04/Rk
	p(9).PortName = 'KVHSerial04/Rk';
	p(9).PortWidth = 9;

	% PortName: KVHSerial04/Iterations
	p(10).PortName = 'KVHSerial04/Iterations';
	p(10).PortWidth = 1;

	% PortName: KVHSerial04/SequenceIter
	p(11).PortName = 'KVHSerial04/SequenceIter';
	p(11).PortWidth = 5;
end
