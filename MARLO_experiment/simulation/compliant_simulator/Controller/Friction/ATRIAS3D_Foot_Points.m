function [p5L, p6L, p7L, p8L, p9L, p5R, p6R, p7R, p8R, p9R] = ATRIAS3D_Foot_Points(q,foot_adjust_params,foot_geometry)
%#codegen
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Determine location of points on the nontrivial feet
% Author: Kevin Galloway     Date: Jan.11, 2013
%
% Inputs:
%       q: [16x1 vector] configuration vector, in the form of 
%           [xT,yT,zT,qzT,qyT,qxT,q1R,q2R,q1L,q2L,qgr1R,qgr2R,q3R,qgr1L,qgr2L,q3L]
%       foot_adjust_params: [3x1 vector] Adjustment parameters (X,Y,Z) for the right 
%        foot (ZYX convention). We assume that any adjustment about Z-axis or Y-axis is symmetric 
%        (i.e. mirror) for the left. These parameters are given as angles 
%        (in radians) of rotation of the foot with respect to the flipped
%        shin axis (i.e. z positive pointing up the shin)
%       foot_geometry: [4x1 vector] Geometry of the prosthetic foot (in meters), in the
%       form of [foot_length, length_behind_heel, heel_width, toe_width]
%           -Defaults to geometry of MARLO prosthetic feet WITHOUT "flesh"
%           covering
%
% Outputs:
%        - Coordinates of foot points relative to world frame
%

if nargin < 3 %Default to MARLO prosthetic feet WITHOUT "flesh" covering (and with trivial height)
    %Foot geometry (in meters)
    foot_height = 0; %distance from the bottom of the foot to the ankle
    foot_length = .24; %length of the foot from heel to toe
    length_behind_heel = .07; %distance from the back of the heel to the ankle
    heel_width = .045; % width of the foot at the heel
    toe_width = .07; % width of the foot at the toes
    y_dist_ankle_to_toe = 0; %the y distance from the ankle point to the toe, along the foot midline
    z_dist_ankle_to_toe = 0; %the height of the toe above the ground, when the foot is flat on the ground
    
else
    foot_height = 0; %distance from the bottom of the foot to the ankle
    foot_length = foot_geometry(1);
    length_behind_heel = foot_geometry(2);
    heel_width = foot_geometry(3);
    toe_width = foot_geometry(4);
    y_dist_ankle_to_toe = foot_geometry(5);
    z_dist_ankle_to_toe = foot_geometry(6);
end
p5 = [-toe_width/2; foot_length-length_behind_heel; -foot_height];
p6 = [toe_width/2; foot_length-length_behind_heel; -foot_height];
p7 = [heel_width/2; -length_behind_heel; -foot_height];
p8 = [-heel_width/2; -length_behind_heel; -foot_height];
p9 = [0; y_dist_ankle_to_toe; z_dist_ankle_to_toe];

if nargin < 2 %Default to zero adjustment
    footX = 0; 
    footY = 0;
    footZ = 0;
else
    footX = foot_adjust_params(1);
    footY = foot_adjust_params(2);
    footZ = foot_adjust_params(3);
end
   
% Roation matrices to take us from foot frame to (flipped) shin frame
R_Foot2ShinR = Rz(footZ)*Ry(footY)*Rx(footX); %The rotation matrix that takes us from right foot frame to (flipped) right shin frame
R_Foot2ShinL = Rz(-footZ)*Ry(-footY)*Rx(footX); %The rotation matrix that takes us from left foot frame to (flipped) left shin frame

[R1,R5]= ShinRotationMatrices_Hip(q); %Get the shin rotation matrices
R1_flipped = R1*Rx(pi); %Rotate by pi around the x axis so that the z axis of R1 is positive up the leg. (More intuitive for applying the foot adjustment)
R5_flipped = R5*Rx(pi); %Rotate by pi around the x axis so that the z axis of R5 is positive up the leg. (More intuitive for applying the foot adjustment)

% Roation matrices to take us from foot frame to world frame
R_Foot2WorldR = R1_flipped*R_Foot2ShinR; 
R_Foot2WorldL = R5_flipped*R_Foot2ShinL;

%Get world-frame coordinates of shin end
[pcm p0 p0T pHR p1R p2R p3R p4R pHL p1L p2L p3L p4L] =  ATRIAS3D_Positions_Hip(q);

%Coordinates of foot points in world frame
p5R = p4R + R_Foot2WorldR*p5;
p6R = p4R + R_Foot2WorldR*p6;
p7R = p4R + R_Foot2WorldR*p7;
p8R = p4R + R_Foot2WorldR*p8;
p9R = p4R + R_Foot2WorldR*p9;
p5L = p4L + R_Foot2WorldL*p5;
p6L = p4L + R_Foot2WorldL*p6;
p7L = p4L + R_Foot2WorldL*p7;
p8L = p4L + R_Foot2WorldL*p8;
p9L = p4L + R_Foot2WorldL*p9;
end

function M_X = Rx(phi)
M_X = [1 0 0; 0 cos(phi) -sin(phi); 0 sin(phi) cos(phi)];
end

function M_Y = Ry(theta)
M_Y = [cos(theta) 0 sin(theta); 0 1 0; -sin(theta) 0 cos(theta)];
end

function M_Z = Rz(psi)
M_Z = [cos(psi) -sin(psi) 0; sin(psi) cos(psi) 0; 0 0 1];
end
