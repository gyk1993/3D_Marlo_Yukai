function EulerAngles = M_to_ZYX(M)
    %#codegen
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
    qY = asin(-M(3,1,:));
    qX = atan2(M(3,2,:), M(3,3,:));
    qZ = atan2(M(2,1,:), M(1,1,:));
    EulerAngles = [squeeze(qZ)'; squeeze(qY)'; squeeze(qX)'];
end
