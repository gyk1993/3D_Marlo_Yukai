function [ value, direction, domainTransition ] = leftFootContact( t, x, current_domain )
%LEFTFOOTCONTACT Summary of this function goes here
%   Detailed explanation goes here

q = x(1:end/2);

[pH, pT, pRK, pR, pLK, pL] = model.positions(q);

value = pL(2);
direction = -1;
domainTransition = current_domain.nextDomainTransition;


end

