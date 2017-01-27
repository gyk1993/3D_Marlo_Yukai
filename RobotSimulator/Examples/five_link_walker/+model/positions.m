function [ pH, pT, pRK, pR, pLK, pL ] = positions( q )
%POSITIONS 
%   Calls all of the generated forward kinematic functions

pH = q(1:2);

tmp = model.torso(q).'; 
pT = tmp(1:2);

tmp = model.rightKnee(q).'; 
pRK = tmp(1:2);

tmp = model.rightFoot(q).'; 
pR = tmp(1:2);

tmp = model.leftKnee(q).'; 
pLK = tmp(1:2);

tmp = model.leftFoot(q).'; 
pL = tmp(1:2);



end

