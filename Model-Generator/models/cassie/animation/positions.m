function [ pelvis, fixedleft, hipabductionleft, hiprotationleft, hipflexionleft, ...
    kneejointleft, fixedkneetoshinleft, anklejointleft, toejointleft, toebottomleft, toebottomleftback, toebottomleftfront, ...
    fixedright, hipabductionright, hiprotationright, hipflexionright, kneejointright, ...
    fixedkneetoshinright, anklejointright, toejointright, toebottomright, toebottomrightback, toebottomrightfront] = positions( q )
%POSITIONS 
%   Calls all of the generated forward kinematic functions

pelvis = q(1:3);

% Left Side
tmp = p_fixedleft(q).'; 
fixedleft = tmp(1:3);

tmp = p_hipabductionleft(q).';
hipabductionleft = tmp(1:3);

tmp = p_hiprotationleft(q).'; 
hiprotationleft = tmp(1:3);

tmp = p_hipflexionleft(q).'; 
hipflexionleft = tmp(1:3);

tmp = p_kneejointleft(q).'; 
kneejointleft = tmp(1:3);

tmp = p_fixedkneetoshinleft(q).'; 
fixedkneetoshinleft = tmp(1:3);

tmp = p_anklejointleft(q).'; 
anklejointleft = tmp(1:3);

tmp = p_toejointleft(q).'; 
toejointleft = tmp(1:3);

tmp = p_toebottomleft(q).'; 
toebottomleft = tmp(1:3);

tmp = p_toebottomleftback(q).'; 
toebottomleftback = tmp(1:3);

tmp = p_toebottomleftfront(q).'; 
toebottomleftfront = tmp(1:3);

% Right Side
tmp = p_fixedright(q).'; 
fixedright = tmp(1:3);

tmp = p_hipabductionright(q).';
hipabductionright = tmp(1:3);

tmp = p_hiprotationright(q).'; 
hiprotationright = tmp(1:3);

tmp = p_hipflexionright(q).'; 
hipflexionright = tmp(1:3);

tmp = p_kneejointright(q).'; 
kneejointright = tmp(1:3);

tmp = p_fixedkneetoshinright(q).'; 
fixedkneetoshinright = tmp(1:3);

tmp = p_anklejointright(q).'; 
anklejointright = tmp(1:3);

tmp = p_toejointright(q).'; 
toejointright = tmp(1:3);

tmp = p_toebottomright(q).'; 
toebottomright = tmp(1:3);

tmp = p_toebottomrightback(q).'; 
toebottomrightback = tmp(1:3);

tmp = p_toebottomrightfront(q).'; 
toebottomrightfront = tmp(1:3);

end

