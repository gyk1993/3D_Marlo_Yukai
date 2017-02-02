function [Rk, wk, Ak, Seqk, ValidStates] = estimateOrientation(DeltaAngle,Acceleration,Rkm1,wkm1,Akm1,Status,Sequence,Seqkm1,Reset) %#codegen
	% Estimate the rotation matrix Rk representing the orientation of the
	% IMU with respect to the world at the current time step (step k).
	%
	% Inputs:
	%   DeltaAngle: a rotation vector (i.e., a vector whose direction
	%   coincides with the axis of rotation and whose magnitude is the
	%   rotation angle in radians).
	%
	%   Acceleration: IMU-measured acceleration
	%
	%   Rkm1: This should be the last value Rk returned from this function.
	%   The initial value is ignored as long as (Reset) is true the first
	%   time this function is called.
	%
	%   wk: This should be the last value wk returned from this function.
	%   The initial value can safely be [0; 0; 0] if the robot is at rest
	%   initially (or when (Reset) is deasserted).
	%
	%   Akm1: This should be the last value Ak returned from this function.
	%   The initial value can be either [0; 0; 0] or the initial
	%   Acceleration (these yield equivalent results).
	%
	%   Status: An 8-bit integer corresponding to the KVH IMU status byte.
	%   When the packet CRC fails, this input should be zero.
	%
	%   Sequence: Message counter sent by the IMU. This starts at 0 and
	%   increments by 1 with each packet sent, up to 127, at which point it
	%   rolls over.
	%
	%   Seqkm1: Previous Sequence input.
	%
	%   Reset: When (Reset) is true, the rotation matrix
	%   Rk is computed by assuming the IMU is stationary so that the
	%   measured Acceleration is opposite the direction the gravitational
	%   force. When (Reset) is true, the acceleration is not used, and the
	%   rotation matrix Rk is computed by accumulating DeltaAngle
	%   rotations.
	%
	% Outputs:
	%
	%   Rk: Orientation matrix representing the current orientation of the
	%   IMU with respect to the world frame. Note that when represented
	%   with ZYX Euler angles, the initial yaw (i.e., the yaw at when the
	%   (Reset) input drops to 0) is arbitrary. If it is desired to have
	%   zero yaw in that configuration, this should be handled outside this
	%   function.
	%
	%   wk: Estimated angular velocity in the IMU frame
	%
	%   Ak: The filtered acceleration estimate. This value is only used
	%   when (Reset) is true.
	%
	%   Seqk: Last valid Sequence number seen.
	%
	%
	% The initial orientation estimate is computed by assuming the robot is
	% stationary in the world frame, so that the measured acceleration is
	% simply due to the gravitational force. When the IMU is upright on a
	% horizontal surface, the measured acceleration (in g's) is roughly
	%   Acceleration = [0; 0; 1]
	% When the IMU is at rest in another configuration, the measured
	% Acceleration will be some other unit vector. There is not a unique
	% rotation matrix which maps the measured Acceleration into the world
	% frame z-axis, since any subsequent rotation about the z-axis would
	% leave the Acceleration aligned with the vertical. To account for this
	% non-uniqueness, we represent the initial orientation not with a
	% rotation matrix but with a unit length vector in R^3 (i.e., a point
	% on the 2-sphere S^2).
	%
	% We will compute the initial orientation estimate by filtering the
	% Acceleration when (Reset==1). In order to derive the filter we need
	% to know how to combine points on the 2-sphere in a meaningful way. It
	% turns out that, given a set of points x1, x2, ..., xn in S^2, the
	% normalized sum
	%   xhat = (x1 + x2 + ... + xn)/||x1 + x2 + ... + xn||
	% is another point on the 2-sphere which maximizes the sum of the
	% cosines of the angles between xhat and each xi, i=1,...,n, which is
	% roughly equivalent to minimizing the sum of the angles between xhat
	% and each xi, i=1,...,n. We can also use a weighted sum. Thus it is
	% straightforward to implement a filter on S^2; we need only augment
	% the standard filter with a normalization of the result.
	%
	% Note that the average is well defined only if
	%   (x1 + x2 + ... + xn) ~= 0.
	% For the "one-pole filter" used below, assuming
	% (accelFilterAlpha~=0.5), the weighted sum can only be zero if
	% (Acceleration==0) and (Akm1==0). Since (Reset) should be true only
	% when the robot is stationary, we should never have (Acceleration==0).
	% In any case, we guard against the unlikely possibility by checking
	% for zero Acceleration.
	%
	% To compute a rotation matrix which maps a unit vector x1 to the
	% z-axis, we have many choices. For example, we could compute an axis
	% of rotation by taking the cross product between x1 and unit z-vector.
	% Then we have to compute the rotation angle and finally compute the
	% rotation matrix equivalent to this axis-angle representation. If the
	% original unit vector x1 is already aligned with the z-axis, this
	% method cannot be used (in this case the rotation matrix can be taken
	% as the identity; however, we have to choose a tolerance for
	% determining if the two vectors are aligned). A better choice is
	% rotate 180 degrees around an axis half way between x1 and the z-axis.
	% We can easily compute the axis of rotation w as the normalized sum
	%   w = (x1+zhat)/||x1+zhat||.
	% The matrix associated with this rotation is
	%   R = 2 w*w^T - I.
	%
	% After the initial estimate is computed, we simply update the current
	% estimate by a group operation using the IMU-derived DeltaAngle. Thus
	% we convert DeltaAngle to a rotation matrix R and update R(k) from
	% R(k-1) as
	%   Rk = Rkm1 * R
	
	DT = 0.001; % SAMPLE TIME USED TO ESTIMATE ANGULAR VELOCITY wk
	accelFilterAlpha = 0.98;
	
	Rk = Rkm1;
	Ak = Akm1;
	Seqk = Seqkm1;
	
	% Mask the status byte to get accelerometer and gyro status. For now we
	% just ignore invalid data.
	Status = bitxor(Status, uint8(119)); % invert so '0' means valid
	AccelValid = ~bitand(Status, uint8(112));
	GyroValid  = ~bitand(Status, uint8(7));
	SequenceValid = (Sequence>=0 && Sequence<127); % To do: why not <= 127
	
	%% Estimate angular velocity
	if (GyroValid)
		wk = DeltaAngle/DT;
	else
		wk = wkm1;
	end
	
	if (Reset && AccelValid)
		%% Compute initial orientation estimate (modulo yaw)
		
		% Normalize to ensure Acceleration lies on the 2-sphere S^2
		normAccel = norm(Acceleration);
		if (normAccel < 1e-8)
			Acceleration = [0; 0; 1];
		else
			Acceleration = Acceleration/normAccel;
		end
		% First-order IIR filter with a pole at z=accelFilterAlpha
		Ak = accelFilterAlpha*Akm1 + (1-accelFilterAlpha)*Acceleration;
		% Normalize to ensure Ak lies on the 2-sphere S^2
		% Assuming (accelFilterAlpha~=0.5), norm(Ak) should never be zero.
		Ak = Ak/norm(Ak);
		
		% Compute the axis of rotation K and the rotation matrix Rk
		K = Ak + [0; 0; 1];
		K = K/norm(K);
		Rk = 2*(K*K') - eye(3);
		
		
	elseif (GyroValid && SequenceValid)
		%% Update orientation estimate
		
		% If we missed (n-1) packets, we assume that the angular velocity
		% is constant during that time period. This means the robot should
		% have rotated n times as much as DeltaAngle indicates. If we don't
		% miss any packets, then n = Sequence-Seqkm1 = 1 and we have
		%   theta = norm(DeltaAngle).
		Seqk = Sequence;
		n = Sequence-Seqkm1;
		if (n<0)
			n = n+128;
		end
		% To do: count Squence Valid instead of n
		
		theta = n*norm(DeltaAngle);
		if (theta > 3e-8)
			% Avoid division by zero. The threshold 3e-8 (rad/ms) is
			% slighly less than the angular velocity of the Earth on its
			% axis, which is
			%   2*pi/(23*3600 + 56*60 + 04.09053)/1000
			%     = 7.292115855377075e-08 (rad/ms)
			% If the measured rotation is less than this, we ignore it.
			w = DeltaAngle/theta;
			S = [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
			R = eye(3)*cos(theta) + S*sin(theta) + (1-cos(theta))*(w*w');
			Rk = Rkm1*R;
		end
	end
	
	ValidStates = [AccelValid; GyroValid; SequenceValid];
end
