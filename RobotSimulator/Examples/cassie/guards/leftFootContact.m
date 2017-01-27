function [ value, direction, domainTransition ] = leftFootContact( t, x, current_domain )
%LEFTFOOTCONTACT Summary of this function goes here
%   Detailed explanation goes here

q = x(1:end/2);

[ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
    kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
    fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
    fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = positions(q);

value = toebottomleft(3);
direction = -1;
domainTransition = current_domain.nextDomainTransition;


end

