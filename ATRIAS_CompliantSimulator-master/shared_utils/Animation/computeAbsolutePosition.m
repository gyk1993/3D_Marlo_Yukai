function [p0, v0, pSwing, pStance] = computeAbsolutePosition(t, q, dq, stance_leg)
    
    if isstruct(t);
        log = t;
        t = log.t;
        q = log.q;
        dq = log.dq;
        stance_leg = log.ControlState.StanceLeg;
        stance_leg(log.ControlState.ControllerMode<=2) = 1-stance_leg(log.ControlState.ControllerMode<=2);
        StepNum = cumsum([0; diff(stance_leg)~=0]);
    else
        StepNum = cumsum([1; diff(stance_leg)~=0]);
    end
    %if nargin>3 && ZeroYaw
    %    q(:,1) = 0;
    %end
    
    n  = size(q,1);
    p0 = zeros(n, 3);
    v0 = p0;
    pSwing = p0;
    for k=1:n
        if stance_leg(k)==0
            %[~, p0(k,:), ~, pSwing(k,:)] = ATRIAS3D_Control_PointsRight(q(k,:)');
            %[p0(k,:), v0(k,:), pSwing(k,:)] = HipPosVelRight_FixParams(q(k,:)', dq(k,:)'); 
            [p0(k,:), v0(k,:), pSwing(k,:)] = CATRIAS3D_HipPosVel_Right(q(k,:)', dq(k,:)'); 
        else
            %%[~, p0(k,:), ~, pSwing(k,:)] = ATRIAS3D_Control_PointsLeft(q(k,:)');
            %[p0(k,:), v0(k,:), pSwing(k,:)] = HipPosVelLeft_FixParams(q(k,:)', dq(k,:)'); 
            [p0(k,:), v0(k,:), pSwing(k,:)] = CATRIAS3D_HipPosVel_Left(q(k,:)', dq(k,:)'); 
        end
    end
    
    idxStep = [find(diff(stance_leg)); n];
    pStance = zeros(length(idxStep), 3);
    for k=1:length(idxStep)-1
        pStance(k+1,:) = pSwing(idxStep(k), :);
        s = linspace(0, 1, idxStep(k+1)-idxStep(k))';
        pst =  [repmat(pStance(k+1,1:2), length(s), 1) (1-s)*pStance(k+1,3)];
        pSwing(idxStep(k)+1:idxStep(k+1), :) = pSwing(idxStep(k)+1:idxStep(k+1), :) + pst;
        p0(idxStep(k)+1:idxStep(k+1), :)     = p0(idxStep(k)+1:idxStep(k+1), :) + pst;
    end
    pStance = pStance(StepNum+1,:);
end
