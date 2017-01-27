function [ pH, pT, pR, pL ] = positions( q )
%POSITIONS 
%   Calls all of the generated forward kinematic functions

pH = q(1:2);

tmp = p_torso(q).'; 
pT = tmp(1:2);

tmp = p_rightFoot(q).'; 
pR = tmp(1:2);

tmp = p_leftFoot(q).'; 
pL = tmp(1:2);



end

