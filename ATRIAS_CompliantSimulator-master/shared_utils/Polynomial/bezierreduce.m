function [alpha, err, errNext] = bezierreduce(alpha,Mdes,errlim)
    M = size(alpha,2)-1; % original M
    if nargin<2 || isempty(Mdes)
        Mdes = 0;
        maxreduce = 1;
    else
        maxreduce = 0;
    end
    
    if nargin<3
        errlim = 1e-12; % maximum permissible error
    end
    
    if M<Mdes
        error('BEZIERREDUCE:CannotElevate','Cannot elevate polynomial degree.');
    end
    
    err = 0;
    errNext = 0;
    while (M>Mdes && errNext<=errlim)
        [alphaR,errNext] = reduce1(alpha, M);
        M = M-1;
        
        if (errNext<errlim)
            alpha = alphaR;
            err = errNext;
        end
    end
    
    if (M>Mdes && ~maxreduce)
        warning('BEZIERREDUCE:FailedReduction','Failed to reduce polynomial to desired degree.');
    end
end

function [alphaR,err] = reduce1(alpha, M)
    % From http://en.wikipedia.org/wiki/B%C3%A9zier_curve#Degree_elevation
    % \mathbf{P'}_i = \frac{i}{n+1}\mathbf{P}_{i-1} + \frac{n+1-i}{n+1}\mathbf{P}_i,\quad i=0,\ldots, n+1. 
    R = ([diag((M):-1:1)/(M) zeros(M,1)] + [zeros(M,1) diag(1:1:(M))/(M)]);
    alphaR = alpha/R;
    
    tmp = alphaR*R;
    err = norm(alpha(:) - tmp(:));
end
