function [x_Jp_TorsoTop] = Jp_TorsoTop(x)
%Jp_TorsoTop
%    x_Jp_TorsoTop = Jp_TorsoTop(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:17

t1=x(5);
t2=cos(t1);
t3=x(4);
t4=sin(t3);
t5=cos(t3);
t6=sin(t1);
x_Jp_TorsoTop=[1,0,0,0,1,0,0,0,1,0,(-0.58).*t2.*t5,(-0.58).*t2.*t4,0.58.*t2, ...
  0.58.*t4.*t6,(-0.58).*t5.*t6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, ...
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

end %function