function [x_R_qHLeft] = R_qHLeft(x)
%R_qHLeft
%    x_R_qHLeft = R_qHLeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:11

t1=x(5);
t2=x(12);
t3=cos(t2);
t4=x(6);
t5=cos(t4);
t6=sin(t1);
t7=x(4);
t8=cos(t1);
t9=sin(t7);
t10=sin(t2);
t11=cos(t7);
t12=sin(t4);
t13=t5.*t6.*t9;
t14=t11.*t12;
t15=t13 + t14;
t16=(-1).*t11.*t5.*t6;
t17=t12.*t9;
t18=t16 + t17;
x_R_qHLeft=[(-1).*t10.*t6 + t3.*t5.*t8,t15.*t3 + t10.*t8.*t9,t18.*t3 + (-1).* ...
  t10.*t11.*t8,(-1).*t12.*t8,t11.*t5 + (-1).*t12.*t6.*t9,t11.*t12.* ...
  t6 + t5.*t9,t3.*t6 + t10.*t5.*t8,t10.*t15 + (-1).*t3.*t8.*t9,t10.* ...
  t18 + t11.*t3.*t8];

end %function