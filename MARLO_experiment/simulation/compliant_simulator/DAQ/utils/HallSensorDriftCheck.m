function [handle, offset] = HallSensorDriftCheck(log)
	%HALLSENSORDRIFTCHECK Analyzes the drift of the hall sensors given the
	% log data
	%Uses the absolute dirty encoder readings from the renichau sensors
	% as a reference.
	%NOTE that the order of the variables might not be the same over time
	% for different experiments/log files...
	
	q_inc = log.HallPosition; % [1 2 3 4] correspond to 1R, 2R, 1L, 2L
	q_joint = log.EncoderAnglesDirty(:, [5 6 7 8]); % [5 6 7 8] correspond to 1R, 2R, 1L, 2L
	% q_joint = log.q(:, [8 9 11 12]); % [8 9 11 12] correspond to 1R, 2R, 1L, 2L
	
	offset = zeros(size(q_inc));
	scale = pi/1800; % Scale factor for the Hall sensor
	
	% The relation is:
	%   q_joint == offset + scale*q_inc
	
	for i = 1:size(q_inc, 1)
		offset(i, :) = rad2deg(q_joint(i, :) - scale.*q_inc(i, :));
	end
	
	handle = figure;
	
	hold on
	plot(log.t, offset);
	xlabel('time (s)');
	ylabel('offset (degrees)');
	hold off
end
