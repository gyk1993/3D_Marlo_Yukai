function value = polya( poly_cor, s, s_corr_max )
    if nargin<3
        s_corr_max = 0.5;
    end
    a2=poly_cor(:,3);
    if s<=s_corr_max
        a3=poly_cor(:,4);
        a4=poly_cor(:,5);
        value=2*a2+s*(6*a3+s*12*a4);
    else
        value=0*a2;
    end
end
