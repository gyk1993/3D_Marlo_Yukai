function alphabar = beziervReparameterize(alpha, slim)
    
    s = 0:0.01:1;
    n = length(s);
    sbar = (slim(:,2)-slim(:,1))*s + repmat(slim(:,1), 1, n);
    hdbar = zeros(size(alpha,1), n);
    for k=1:n
        hdbar(:,k) = bezierv(alpha,sbar(:,k));
    end
    alphabar = bezfit(s, hdbar, 5);
    
    if 0 % DEBUG
        hd = 0*hdbar;
        hdbar2 = 0*hdbar;
        for k=1:length(s)
            hd(:,k) = bezier(alpha,s(k));
            hdbar2(:,k) = bezier(alphabar,s(k));
        end
        
        figure; plot(s, hd', sbar', hdbar', 'r', sbar', hdbar2', ':g');
    end
end
