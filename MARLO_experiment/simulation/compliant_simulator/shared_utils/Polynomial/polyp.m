function value = polyp( poly_cor,s,s_corr_max)
    if nargin<3,
        s_corr_max = 0.5;
    end
    a0=poly_cor(:,1);
    if s<=s_corr_max
        a1=poly_cor(:,2);
        a2=poly_cor(:,3);
        a3=poly_cor(:,4);
        a4=poly_cor(:,5);
        value=a0+s*(a1+s*(a2+s*(a3+s*a4)));
    else
        value=0*a0;
    end
end
