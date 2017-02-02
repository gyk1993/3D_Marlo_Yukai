% This script computes the new inertia matrix If which results from the
% addition of a point mass to a rigid body with known parameters. We assume
% the initial mass m0, center of mass com0, and inertia I0 are known, and
% that the final (total) mass mf and comf are also known.
m0   = 0.39465;
mf   = 1.64;    % BGB 2014-12-28  (+/- 0.05 kg)
com0 = [0.00002; 0.00017; 0.15203];
comf = [0.00002; 0.00017; 0.49];     % BGB 2014-12-28  (+/- 0.5 cm)
I0   = [0.01260 0.00000 0.00000;...
        0.00000 0.01272 -0.00000;...
        0.00000 -0.00000 0.00019];
    

% To compute the new inertia tensor about the new COM, we assume that a
% single point mass m1 was added to the system at position com1.
m1   = mf - m0;
com1 = ((mf * comf) - (m0 * com0)) / m1;

% The inertia I1bar of this new point about the original COM is given by the
% parallel axis theorem. Here dbar is the vector from the original COM to
% the point mass position com1. The total inertia Ifbar about the original COM is
% the sum of the two.
dbar  = com1 - com0;
I1bar = m1 * ((dbar.'*dbar) * eye(3) - (dbar*dbar.'));
Ifbar = I0 + I1bar;

% Another application of the parallel axis theorem gives us the inertia
% about the new COM
d  = com0 - comf;
If = Ifbar - mf * ((d.'*d) * eye(3) - (d*d.'));

% The result is nearly diagonal; we'll make it completely so:
mat2str(diag(diag(I1)),4)
