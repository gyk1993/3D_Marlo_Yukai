function GRF = transformForceTorque(log)
    % TRANSFORMFORCETORQUE Transform force/torque from foot to world frame
    %
    %   The world frame is modulo yaw.
    %
    %   Forces need only be rotated into the proper frame. Thus, if FRW is
    %   the force on the right foot in the world frame and FRR is the force
    %   on the right foot in the right sensor frame, then
    %
    %       FRW = Ry(qyT) * Rx(qxT) * Ry(q3R) * Rx(q1R) * Rz(qcalR) * FRR
    %
    %   where Rx, Ry, and Rz are basic rotation matrices about the x, y,
    %   and z-axes, respectively, and qcalR is the rotation about the
    %   z-axis which aligns the right sensor frame with the right shank
    %   frame.
    %
    %   Torques are first rotated exactly the same as forces. Then an
    %   additional term is added in order to compute the torque about the
    %   COM. This additional term results from moving the point of
    %   application of the forces from the foot (or ankle) to the COM. This
    %   additional torque is equal to the cross product between the vector
    %   dR from the COM to the right foot (or dL from the COM to the left
    %   foot) with the force vector. Thus, if TRCW is the torque about the
    %   COM due to reactions at the right foot expressed in the world
    %   frame, TRRW is the torque at the right foot expressed in the world
    %   frame, and FRW is the force at the right foot expressed in the
    %   world frame, then
    %
    %       TRCW = TRRW + dR x FRW
    %            = TRRW + S(dR) * FRW
    %
    %   where S(k) is the 3x3 skew-symmetric cross-product matrix.
    %
    %
    %   In addition to world-frame forces and torques, this function
    %   computes the parameterized location of the foot rotation indicator
    %   (FRI) point (A. Goswami, "Postural Stability of Biped Robots and
    %   the Foot-Rotation Indicator (FRI) Point," IJRR 1999), which
    %   coincides with the COP/ZMP when the FRI is inside the support
    %   region. The result is parameterized because the absolute height of
    %   the COM above the ground surface is not known. If the height Pz of
    %   the COM can be estimated from the geometry of the foot, then the
    %   the X-Y components of the FRI point P = [Px; Py; Pz] can be
    %   calculated as an affine function of the parameterized FRI values
    %   P0, P1:
    %
    %       [Px; Py] = P0 + P1*Pz.
    %
    %   "The FRI point [is] the point on the foot/ground contact surface...
    %   at which the resultant moment of the force/torque impressed on the
    %   foot is normal to the surface." To compute the FRI point, we assume
    %   that each foot has negligible mass, so that the FRI point P
    %   satisfies (see equation (6) of Goswami 1999)
    %
    %       [1 0 0; 0 1 0] * (TCW + P x FW) = [0; 0]
    %
    %   or, equivalently,
    %
    %       [TCWx; TCWy] = [0 -FWz FWy; FWz 0 -FWx] * [Px; Py; Pz]
    %
    %   where TCW is the total (sum of left and right) torques at the COM
    %   expressed in the world frame, FW is the total ground reaction force
    %   expressed in the world frame, and P is the position of the FRI
    %   point relative to the COM. Note that this relation consists of two
    %   equations in three unknowns. We solve for [Px; Py] as functions of
    %   Pz, yielding
    %
    %       [TCWx; TCWy] - [FWy; -FWx]*Pz = [0 -FWz; FWz 0] * [Px; Py]
    %
    %   or, equivalently,
    %
    %       [Px; Py] = 1/FWz * [0 -1; 1 0] * ([TCWx; TCWy] - [FWy; -FWx]*Pz) 
    %                = P0 + P1*Pz
    %   
    %   where
    %
    %       P0 = [-TCWy/FWz; TCWx/FWz]
    %       P1 = [FWx/FWz; -FWy/FWz]
    %
    %
    %   In order to make the code more efficient, functions are defined to
    %   compute the product of a rotation matrix Rx(), Ry(), Rz() or the
    %   cross-product matrix S() with each row of another matrix in a
    %   single call. This turned out to be about 27 times faster than doing
    %   everything in one big loop, where the code more closely resembles
    %   the math.
    
    % Extract coordinates
    qyT = log.q(:,2);
    qxT = log.q(:,3);
    q1R = log.q(:,4);
    q1L = log.q(:,6);
    q3R = log.q(:,10);
    q3L = log.q(:,13);
    
    % Compute dR, dL
    qModYaw = [0*log.q(:,1) log.q(:,2:end)];
    n = size(log.q, 1);
    GRF.Right.d = zeros(n, 3);  % dR
    GRF.Left.d  = zeros(n, 3);  % dL
    for k=1:n
        GRF.Right.d(k,:) = -CATRIAS3D_pcmRight(qModYaw(k,:).');
        GRF.Left.d(k,:) = -CATRIAS3D_pcmLeft(qModYaw(k,:).');
    end
    
    if ~isfield(log, 'FT') || isempty(log.FT)
        return
    end
    
    % The F/T data is returned in the FT frame, which differs from the
    % shank frame by a rotation of qcalR or qcalL about the z-axis. The
    % z-axis for both frames points DOWN the shank.
    qcalR = -pi/2 * ones(size(q1R)); % Right shank to right FT frame
    qcalL = pi/2 * ones(size(q1R));  % Left shank to left FT frame
    
    % Convert right F/T to world frame modulo yaw
    GRF.Right.Force = RY(qyT, RX(qxT, RY(q3R, RX(q1R, RZ(qcalR, log.FT(:,1:3))))));
    GRF.Right.Torque = RY(qyT, RX(qxT, RY(q3R, RX(q1R, RZ(qcalR, log.FT(:,4:6))))));
    GRF.Right.Torque = GRF.Right.Torque + S(GRF.Right.d, GRF.Right.Force);
    
    % Convert left F/T to world frame modulo yaw
    % Left hip angle q3L is defined as a clockwise rotation, not
    % counter-clockwise, so we must negate q3L.
    GRF.Left.Force = RY(qyT, RX(qxT, RY(-q3L, RX(q1L, RZ(qcalL, log.FT(:,7:9))))));
    GRF.Left.Torque = RY(qyT, RX(qxT, RY(-q3L, RX(q1L, RZ(qcalL, log.FT(:,10:12))))));
    GRF.Left.Torque = GRF.Left.Torque + S(GRF.Left.d, GRF.Left.Force);
    
    % Compute parameterized FRI
    FW  = GRF.Right.Force + GRF.Left.Force;
    TCW = GRF.Right.Torque + GRF.Left.Torque;
    GRF.FRI.P0 = [-TCW(:,2)./FW(:,3)  TCW(:,1)./FW(:,3)]; % P0 = [-TCWy/FWz; TCWx/FWz]
    GRF.FRI.P1 = [  FW(:,1)./FW(:,3)  -FW(:,2)./FW(:,3)]; % P1 = [  FWx/FWz; -FWy/FWz]
end

% Rotate each ROW of matrix X by the corresponding angle in q about X axis
function Y = RX(q, X)
    cq = cos(q);
    sq = sin(q);
    Y = [X(:,1) cq.*X(:,2)-sq.*X(:,3) sq.*X(:,2)+cq.*X(:,3)];
end

% Rotate each ROW of matrix X by the corresponding angle in q about Y axis
function Y = RY(q, X)
    cq = cos(q);
    sq = sin(q);
    Y = [cq.*X(:,1)+sq.*X(:,3) X(:,2) -sq.*X(:,1)+cq.*X(:,3)];
end

% Rotate each ROW of matrix X by the corresponding angle in q about Z axis
function Y = RZ(q, X)
    cq = cos(q);
    sq = sin(q);
    Y = [cq.*X(:,1)-sq.*X(:,2) sq.*X(:,1)+cq.*X(:,2)  X(:,3)];
end

% Multiply the kth ROW of matrix X by the skew-symmetric matrix S(w(k,:))
function Y = S(w, X)
    % S(w) = 
    % [  0   -w(3)  w(2); ...
    %   w(3)   0   -w(1); ...
    %  -w(2)  w(1)   0]
    Y = [-w(:,3).*X(:,2)+w(:,2).*X(:,3)   w(:,3).*X(:,1)-w(:,1).*X(:,3)  -w(:,2).*X(:,1)+w(:,1).*X(:,2)];
end
