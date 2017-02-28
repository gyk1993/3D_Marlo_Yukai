function [pR, vR, J4R, JR1Col, pL, vL, J4L, JR5Col] = FootHeightAndVelocity(x, FootPoints, leg_length, torso_com_offset)
    %#codegen
    q  = x(1:16);
    dq = x(17:end);
    
    nPoints = size(FootPoints,2);
    
    [p4R,R1,J4R,JR1Col,p4L,R5,J4L,JR5Col] =  ...
        OriginalLeg_Springs_VariableLeg_COMoffset.ATRIAS3D_FootPointPosJacob_Hip(q, [leg_length; torso_com_offset]);
    
    % Reflect FootPoints in yz-plane (assumes feet are symmetrical)
    R5(:,1) = -R5(:,1);
    JR5Col(1:3,:) = -JR5Col(1:3,:);
    
    % Foot point positions   p^W = p_4R + R_R^W p^R 
    pR = zeros(3,nPoints);
    pL = zeros(3,nPoints);
    
    for k=1:nPoints
        pR(:,k) = p4R + R1*FootPoints(:,k);
        pL(:,k) = p4L + R5*FootPoints(:,k); 
    end
    
    % Foot point velocities
    vR  = zeros(3,nPoints);
    vL  = zeros(3,nPoints);
    DR  = JR1Col*dq;
    DL  = JR5Col*dq;
    v4R = J4R*dq;
    v4L = J4L*dq;
    
    for k=1:nPoints
        vR(:,k) = v4R + FootPoints(1,k)*DR(1:3) + FootPoints(2,k)*DR(4:6) + FootPoints(3,k)*DR(7:9);
        vL(:,k) = v4L + FootPoints(1,k)*DL(1:3) + FootPoints(2,k)*DL(4:6) + FootPoints(3,k)*DL(7:9);
    end
    
    %% BOARD UNDER FOOT
    pR(3, pR(2,:)<0) = pR(3, pR(2,:)<0) - 0.01;
    pL(3, pL(2,:)<0) = pL(3, pL(2,:)<0) - 0.01;
end
