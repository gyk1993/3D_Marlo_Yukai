function [F, dd] = LuGreHertzian(zG, dzG, d, v, GroundModel,GroundHeight)
if nargin < 6
    GroundHeight = 0;
end
    % Normal forces
    %Fn = abs(zG).^GroundModel.n .* (GroundModel.k - GroundModel.lambda_a*dzG - GroundModel.lambda_b*sign(dzG).*sqrt(abs(dzG))); % Plestan et al. 2003
    Fn = abs(zG-GroundHeight).^GroundModel.n .* (GroundModel.k - GroundModel.lambda_a*dzG) - GroundModel.lambda_b*abs(zG-GroundHeight).*sign(dzG).*sqrt(abs(dzG));
    Fn = max(GroundModel.GRF_LowerLimit, min(Fn, GroundModel.GRF_UpperLimit));
    Fn  = (zG<GroundHeight).*Fn; % consider rough terrain. DDA 2016-2-9
    
    % Tangential forces
    [dd, mu] = LuGre(d, v, GroundModel);
    dd = ([1;1]*(zG<GroundHeight)).*dd;  % consider rough terrain. DDA 2016-2-9
    F = [mu.*[abs(Fn); abs(Fn)]; Fn];
end

function [dd, mu] = LuGre(d, v, GroundModel)
    % Compute terms in LuGre friction model, as modified in Plestan et al.
    % 2003. Note that even that paper seems to have an error, as it
    % reported a term alpha3*sign(dv)*sqrt(abs(v)), but it seems from the
    % text that what was intended was alpha3*sign(v)*sqrt(abs(v)).
    dd = v - abs(v)*GroundModel.sigma0/GroundModel.alpha0.*d;
    mu = -(GroundModel.sigma0*d + GroundModel.sigma1*dd + GroundModel.alpha2*v + GroundModel.alpha3*sign(v).*sqrt(abs(v)));
    mu = max( -GroundModel.mu_s/sqrt(2), min(mu, GroundModel.mu_s/sqrt(2)) );
end
