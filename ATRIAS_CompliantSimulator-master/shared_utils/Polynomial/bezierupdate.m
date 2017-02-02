function alpha = bezierupdate(alpha, s, B, colidx)
    % BEZIERUPDATE modifies Bezier parameters to match a value (and
    % possibly derivatives) at a particular value of s.
    %
    % BEZIERUPDATE(alpha, s, B, colidx), where B is a column vector with as
    % many rows as alpha has and colidx is a scalar, computes a new value
    % for the (colidx)-th column of alpha such that the Bezier polynomial
    % with the modified parameters has the value B at s.
    %
    % If B is a matrix, then successive columns are taken to be derivatives
    % of the Bezier polynomial (with respect to s) at the given value of s.
    % colidx should have as many elements as B has columns.
    %
    % This code is not at all optimized!
    
    [n,m] = size(alpha);
    M = m - 1;
    b = binom(M).';
    x = ones(M+1, 1);
    y = ones(M+1, 1);
    for i=1:M
        x(i+1)=s*x(i);
        y(M+1-i)=(1-s)*y(M+2-i);
    end
    K=(0:M);
    S = x * y.';
    
    % We can represent the value of the Bezier polynomial and its
    % derivatives as
    %   B = alpha*R
    % for an appropriately formed matrix R. We want to keep track of terms
    % multiplying each column of alpha. The value of B(s,alpha) is
    %   B(s,alpha) = alpha * (b .* diag(S));
    % When taking the derivative of B(s,alpha), each monomial term
    % generates two monomials of lower degree.
    ncols = size(B,2);
    R = zeros(M+1, ncols);
    for k = 0:ncols-1
        R(:,k+1) = (b .* diag(S)); % d^k/ds^k B(s,alpha) = alpha * R(:,k+1);
        S = diag(K)*[zeros(1,M+1); S(1:end-1,:)] - [S(:,2:end) zeros(M+1,1)]*diag(M-K);
    end
    
    % Now we want to solve 
    %   B = alpha*R
    % but only modify the columns of alpha specified in colidx. To do so we
    % split alpha into two parts:
    %   B = alpha(:,colidx)*R(colidx,:) + alpha(:,othercol)*R(othercol,:)
    othercol = setdiff(1:M+1, colidx);
    Y = B - alpha(:,othercol)*R(othercol,:);
    alphacol = Y/R(colidx,:);
    alpha(:,colidx) = alphacol;
end
