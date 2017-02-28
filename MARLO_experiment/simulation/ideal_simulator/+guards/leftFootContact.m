function [ value, direction, domainTransition ] = leftFootContact( t, x, current_domain )
%LEFTFOOTCONTACT Summary of this function goes here
%   Detailed explanation goes here

swingFoot_pos = p_LeftFoot(x);

value = swingFoot_pos(3);
direction = -1;
domainTransition = current_domain.nextDomainTransition;


end

