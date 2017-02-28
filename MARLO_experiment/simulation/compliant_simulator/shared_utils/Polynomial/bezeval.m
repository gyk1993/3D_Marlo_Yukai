function y = bezeval(alpha,s)
    if nargin<2 || isempty(s)
        s=0:0.001:1;
    end
    
    y(size(alpha,1),length(s)) = 0;
    for k=1:length(s)
        y(:,k) = bezier(alpha,s(k));
    end
end
