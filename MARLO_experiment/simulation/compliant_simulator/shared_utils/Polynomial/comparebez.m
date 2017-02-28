function comparebez(alpha1,alpha2,alpha3,s)
    
    if nargin<4 || isempty(s)
        s=0:0.001:1;
    end
    B1(size(alpha1,1),length(s)) = 0;
    B2(size(alpha2,1),length(s)) = 0;
    if nargin>2
        B3(size(alpha3,1),length(s)) = 0;
    end
    
    for k=1:length(s)
        B1(:,k) = bezier(alpha1,s(k));
        B2(:,k) = bezier(alpha2,s(k));
        if nargin>2
            B3(:,k) = bezier(alpha3,s(k));
        end
    end
    plot(s,B1.'); hold on;
    if ~verLessThan('MATLAB', '8.4.0')
        set(gca, 'ColorOrderIndex', 1);
    end
    plot(s,B2,'--');
    if nargin>2
        if ~verLessThan('MATLAB', '8.4.0')
            set(gca, 'ColorOrderIndex', 1);
        end
        plot(s,B3,':');
    end
    hold off;
end
