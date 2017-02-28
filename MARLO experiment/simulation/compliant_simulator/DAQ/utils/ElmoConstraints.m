function [constaints, TR, A] = ElmoConstraints() 
% This function is used to determine the position and velocity constraints
% (in ticks) to be used on the Elmo drives. These constraints should be
% updated anytime the MARLOSafetyLimits are changed.
	addpath('..\')
	Calibration = getCalibrationParams2();
	q = zeros(13,1); dq = zeros(13,1);
	[~, qmin, qmax, dqmin, dqmax, ~, ~, ~] = MARLOBasicSafetyLimits2(q, dq);

	convertPosition = @(q, ind) (deg2rad(q) - Calibration. AbsCalAngle(ind)) / Calibration.AbsCalConst(ind) +  Calibration.AbsCalTick(ind);
	convertVelocity = @(dq, ind) (deg2rad(dq) / Calibration.AbsCalConst(ind));

	constaints.minPosition_motor_q1R = int32(convertPosition(qmin(9),5) / 4);
	constaints.minPosition_motor_q1L = int32(convertPosition(qmin(10),7) / 4);
	constaints.minPosition_motor_q2R = int32(convertPosition(qmin(11),6) / 4);
	constaints.minPosition_motor_q2L = int32(convertPosition(qmin(12),8) / 4);

	constaints.maxPosition_motor_q1R = int32(convertPosition(qmax(9),5) / 4);
	constaints.maxPosition_motor_q1L = int32(convertPosition(qmax(10),7) / 4);
	constaints.maxPosition_motor_q2R = int32(convertPosition(qmax(11),6) / 4);
	constaints.maxPosition_motor_q2L = int32(convertPosition(qmax(12),8) / 4);

	constaints.minVelocity_motor_q1R = int32(convertVelocity(dqmin(9),5) / 4);
	constaints.minVelocity_motor_q1L = int32(convertVelocity(dqmin(10),7) / 4);
	constaints.minVelocity_motor_q2R = int32(convertVelocity(dqmin(11),6) / 4);
	constaints.minVelocity_motor_q2L = int32(convertVelocity(dqmin(12),8) / 4);

	constaints.maxVelocity_motor_q1R = int32(convertVelocity(dqmax(9),5) / 4);
	constaints.maxVelocity_motor_q1L = int32(convertVelocity(dqmax(10),7) / 4);
	constaints.maxVelocity_motor_q2R = int32(convertVelocity(dqmax(11),6) / 4);
	constaints.maxVelocity_motor_q2L = int32(convertVelocity(dqmax(12),8) / 4);
	
	% Target Position Windows
	% Allowing for half a degree window
	TR = int32((deg2rad(0.5) / Calibration.AbsCalConst(5)) / 4);
	
	% Target Position Windows
	% Allowing for half a degree window
	A = int32((deg2rad(5) / Calibration.AbsCalConst(5)) / 4);
end