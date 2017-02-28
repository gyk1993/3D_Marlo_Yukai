g = 9.81;
mTotal = 55;

GroundModel.n        = 1.5;
GroundModel.k        = 45e5; %45e5 % BGB 2013-07-24
GroundModel.sigma0   = 260.0;
GroundModel.sigma1   = 0.6;
GroundModel.alpha0   = 0.285;
% GroundModel.alpha0   = 0.285*3; % DDA 2016-2-9   
GroundModel.alpha2   = 0.18; 
GroundModel.alpha3   = 0.3; % (Ksqrt)
GroundModel.lambda_a = 9e6; %9e6 % BGB 2013-07-24
GroundModel.lambda_b = 0.3; %  (KsqrtVert)
GroundModel.mu_s     = 0.7;
GroundModel.GRF_UpperLimit = 4*g*mTotal;
GroundModel.GRF_LowerLimit = -0.25*g*mTotal;

createBusObject(GroundModel, 'GroundModelParamsBus');
