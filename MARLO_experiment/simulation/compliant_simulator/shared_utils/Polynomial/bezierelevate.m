function alpha_out = bezierelevate(alpha,Mdes)
    %#codegen
    M = size(alpha,2)-1; % original M
    if nargin<2
        Mdes = M+1; % desired M
    end
    
    if Mdes < M
        error('BEZIERELEVATE:CannotReduce','Cannot reduce polynomial degree.');
    end
    
    alpha_out = [alpha, zeros(size(alpha,1), Mdes-M)];
    while (M < Mdes)
        alpha_out(:,1:M+2) = elevate1(alpha_out(:,1:M+1), M);
        M = M+1;
    end
end

function alpha_out = elevate1(alpha, M)
    %#codegen
    % From http://en.wikipedia.org/wiki/B%C3%A9zier_curve#Degree_elevation
    % \mathbf{P'}_i = \frac{i}{n+1}\mathbf{P}_{i-1} + \frac{n+1-i}{n+1}\mathbf{P}_i,\quad i=0,\ldots, n+1. 
    alpha_out = alpha*([diag((M+1):-1:1)/(M+1) zeros(M+1,1)] + [zeros(M+1,1) diag(1:1:(M+1))/(M+1)]);
end
