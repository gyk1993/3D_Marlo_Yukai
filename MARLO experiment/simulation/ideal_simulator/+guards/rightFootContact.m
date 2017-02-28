function [ value, direction, domainTransition ] = rightFootContact( t, x, current_domain)
%LEFTFOOTCONTACT Summary of this function goes here
%   Detailed explanation goes here

swingFoot_pos = p_RightFoot(x);

value = swingFoot_pos(3);
direction = -1;
domainTransition = current_domain.nextDomainTransition;


end

