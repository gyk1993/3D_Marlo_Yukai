function EulerAngles = MtoEuler(M_WI, IMUParams)
    %#codegen
    
    %Inputs are the three Euler angles (ZYX convention) in degrees which parametrize the
    %matrix M_RI, and the 9 elements of the M_WI matrix reported by the IMU
    M_RI_Z_rad = IMUParams(1)*pi/180;
    M_RI_Y_rad = IMUParams(2)*pi/180;
    M_RI_X_rad = IMUParams(3)*pi/180;
    
    %Form the M_RI matrix from the paramters
    M_RI = RotZ(M_RI_Z_rad)*RotY(M_RI_Y_rad)*RotX(M_RI_X_rad);
    
    
    %Form the M_WI matrix from the inputs
    M_IW = M_WI.';
    
    %Create the matrix that takes us from world frame 1 (z-down) to world frame
    %2 (z-up)
    M_W_W2 = [0 1 0;1 0 0;0 0 -1];
    
    M_RW = M_IW*M_RI; %Relationship between robot frame and world frame 1 (z-down)
    
    M_RW2 = M_W_W2*M_RW; %Relationship between robot frame and world frame 2 (z-up)
    
    EulerAngles = M_to_ZYX(M_RW2);
end

function EulerAngles = M_to_ZYX(M_RW_in)
    % M_to_ZYX.m
    % Author: Kevin Galloway
    % Date: 29AUG12
    %
    % Summary: This function takes a matrix (or array of matrices) M_RW_in and
    % returns the Euler angles based on the ZYX convention. AngX refers to
    % rotation around the X axis, AngY refers to rotation about the Y axis, and
    % AngZ refers to rotation about the Z axis. If M_RW_in is an array of
    % matrices (i.e. a multidimensional array), then AngX, AngY and AngZ
    % will be vectors.
    M31_RW_in = M_RW_in(3,1);
    M32_RW_in = M_RW_in(3,2);
    M33_RW_in = M_RW_in(3,3);
    M21_RW_in = M_RW_in(2,1);
    M11_RW_in = M_RW_in(1,1);
    AngY_out = asin(-M31_RW_in);
    AngX_out = atan2(M32_RW_in,M33_RW_in);
    AngZ_out = atan2(M21_RW_in,M11_RW_in);
    EulerAngles = [AngZ_out; AngY_out; AngX_out];
end

function M_X = RotX(phi)
    M_X = [1 0 0; 0 cos(phi) -sin(phi); 0 sin(phi) cos(phi)];
end

function M_Y = RotY(theta)
    M_Y = [cos(theta) 0 sin(theta); 0 1 0; -sin(theta) 0 cos(theta)];
end

function M_Z = RotZ(psi)
    M_Z = [cos(psi) -sin(psi) 0; sin(psi) cos(psi) 0; 0 0 1];
end
