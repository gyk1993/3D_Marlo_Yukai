function [K_spring, K_damping] = ATRIAS3D_Spring_Constants(spring_k,zeta)
%#codegen
%This function allows the user to input spring constants for the 3D
%Compliant Ground Simulator

% k_damping = 2*zeta*sqrt(spring_k)*50;
% wd = 0.4740*sqrt(spring_k/2690.8); % period/s DDA 2015-10-01\Experiment02
% k_damping = 2*zeta*spring_k/wd/100;
k_damping = 2*zeta*sqrt(spring_k);

K_matrix = zeros(16);

K_matrix(7,7) = 1;
K_matrix(8,8) = 1;
K_matrix(9,9) = 1;
K_matrix(10,10) = 1;
K_matrix(11,11) = 1;
K_matrix(12,12) = 1;
K_matrix(14,14) = 1;
K_matrix(15,15) = 1;

K_matrix(7,11) = -1;
K_matrix(8,12) = -1;
K_matrix(9,14) = -1;
K_matrix(10,15) = -1;
K_matrix(11,7) = -1;
K_matrix(12,8) = -1;
K_matrix(14,9) = -1;
K_matrix(15,10) = -1;

K_spring = spring_k*K_matrix;
K_damping = k_damping*K_matrix;