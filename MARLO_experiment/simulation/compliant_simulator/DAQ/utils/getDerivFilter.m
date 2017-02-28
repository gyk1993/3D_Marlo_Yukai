function FiltSys = getDerivFilter(N, M, m0, dt, deriv)
    % Get a structure with the state space matrices for a discrete-time
    % filter which estimates a derivative by polynomial fitting. The
    % resulting system is an FIR filter.
    
    if nargin<5; deriv=1; end
    
    [A,B,C,D] = num_der(N, M, m0, dt);
    C = C(deriv+1,:); % Get the row corresponding to the first derivative
    D = D(deriv+1,:); % Get the row corresponding to the first derivative
    
    [FiltSys.A, FiltSys.B, FiltSys.C] = dbalreal(A,B,C);
    FiltSys.D = D;
    FiltSys.x0 = 0*B(:,1);
    FiltSys.dt = dt;
end
