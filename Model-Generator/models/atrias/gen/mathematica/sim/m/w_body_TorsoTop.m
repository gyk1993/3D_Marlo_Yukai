function [x_w_body_TorsoTop] = w_body_TorsoTop(x)
%w_body_TorsoTop
%    x_w_body_TorsoTop = w_body_TorsoTop(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:17

t1=x(5);
t2=sin(t1);
t3=x(6);
t4=cos(t1);
t5=cos(t3);
t6=x(4);
t7=sin(t6);
t8=sin(t3);
t9=x(20);
t10=x(21);
t11=x(22);
t12=cos(t6);
t13=t4.^2;
x_w_body_TorsoTop=[t2.*((-1).*t11.*t4.*t5 + t10.*t2.*t8) + (-1).*t4.*t7.*((-1).* ...
  t11.*t2.*t5.*t7 + (-1).*t11.*t12.*t8 + (-1).*t10.*t4.*t7.*t8 + ( ...
  -1).*t5.*t7.*t9 + (-1).*t12.*t2.*t8.*t9) + t12.*t4.*(t11.*t12.* ...
  t2.*t5 + t10.*t12.*t4.*t8 + (-1).*t11.*t7.*t8 + t12.*t5.*t9 + (-1) ...
  .*t2.*t7.*t8.*t9),t10.*t13.*t5 + (t2.*t5.*t7 + t12.*t8).*(t10.* ...
  t2.*t7 + (-1).*t12.*t4.*t9) + ((-1).*t12.*t2.*t5 + t7.*t8).*((-1) ...
  .*t10.*t12.*t2 + (-1).*t4.*t7.*t9),(-1).*t4.*t8.*((-1).*t10.*t2.* ...
  t5 + (-1).*t11.*t4.*t8) + (t5.*t7 + t12.*t2.*t8).*((-1).*t10.* ...
  t12.*t4.*t5 + t11.*t5.*t7 + t11.*t12.*t2.*t8 + t2.*t5.*t7.*t9 +  ...
  t12.*t8.*t9) + (t12.*t5 + (-1).*t2.*t7.*t8).*(t11.*t12.*t5 + t10.* ...
  t4.*t5.*t7 + (-1).*t11.*t2.*t7.*t8 + t12.*t2.*t5.*t9 + (-1).*t7.* ...
  t8.*t9)];

end %function