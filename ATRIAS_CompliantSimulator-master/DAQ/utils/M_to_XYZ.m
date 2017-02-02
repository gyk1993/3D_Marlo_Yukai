function EulerAngles = M_to_XYZ(M)
    % M_to_ZYX.m
    % Author: Brian G. Buss
    % Date: 2014-04-07
    % Modified from M_to_XYZ
    %
    % Summary: This function takes a rotation matrix M and returns the XYZ
    % Euler angles. If M is an a multidimensional array, then EulerAngles
    % is a matrix of length size(M,3).
    qY = asin(M(1,3,:));
    qX = atan2(-M(2,3,:), M(3,3,:));
    qZ = atan2(-M(1,2,:), M(1,1,:));
    EulerAngles = [squeeze(qX)'; squeeze(qY)'; squeeze(qZ)'];
end
