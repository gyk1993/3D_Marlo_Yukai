function [x_Jw_body_qHRight] = Jw_body_qHRight(x)
%Jw_body_qHRight
%    x_Jw_body_qHRight = Jw_body_qHRight(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:06

t1=x(4);
t2=x(6);
t3=x(5);
t4=sin(t1);
t5=cos(t2);
t6=sin(t3);
t7=cos(t1);
t8=sin(t2);
t9=x(7);
t10=cos(t3);
t11=cos(t9);
t12=sin(t9);
t13=(-1).*t5.*t6.*t7;
t14=t4.*t8;
t15=t13 + t14;
t16=(-1).*t10.*t11.*t4;
t17=t4.*t5.*t6;
t18=t7.*t8;
t19=t17 + t18;
t20=t12.*t19;
t21=t16 + t20;
t22=t5.*t7;
t23=(-1).*t4.*t6.*t8;
t24=t22 + t23;
t25=t5.*t6.*t7;
t26=(-1).*t4.*t8;
t27=t25 + t26;
t28=t11.*t19;
t29=t10.*t12.*t4;
t30=t28 + t29;
t31=t10.*t11.*t7;
t32=t12.*t15;
t33=t31 + t32;
t34=t11.*t15;
t35=(-1).*t10.*t12.*t7;
t36=t34 + t35;
t37=t4.*t5;
t38=t6.*t7.*t8;
t39=t37 + t38;
t40=t11.*t6;
t41=t10.*t12.*t5;
t42=t40 + t41;
t43=t10.*t11.*t5;
t44=(-1).*t12.*t6;
t45=t43 + t44;
t46=t10.^2;
t47=t8.^2;
t48=t39.^2;
t49=t24.^2;
t50=t36.^2;
t51=t30.^2;
t52=t45.^2;
t53=(-1).*t10.*t11.*t7;
x_Jw_body_qHRight=[0,0,0,0,0,0,0,0,0,t24.*t33 + t21.*((-1).*t4.*t5 + (-1).*t6.*t7.* ...
  t8),t21.*t36 + t30.*(t12.*t27 + t53),t30.*t39 + t24.*(t11.*t27 +  ...
  t10.*t12.*t7),(-1).*t10.*t21.*t4.*t8 + t42.*t6.*t8 + t10.*t33.* ...
  t7.*t8,t30.*(t10.*t12.*t4.*t5 + t11.*t4.*t6) + t45.*(t10.*t11 + ( ...
  -1).*t12.*t5.*t6) + t36.*((-1).*t10.*t12.*t5.*t7 + (-1).*t11.*t6.* ...
  t7),t24.*(t10.*t11.*t4.*t5 + (-1).*t12.*t4.*t6) + t39.*((-1).* ...
  t10.*t11.*t5.*t7 + t12.*t6.*t7) + (-1).*t10.*((-1).*t10.*t12 + ( ...
  -1).*t11.*t5.*t6).*t8,t27.*t33 + (-1).*t10.*t42.*t5 + t21.*((-1).* ...
  t4.*t5.*t6 + (-1).*t7.*t8),t12.*t24.*t30 + t12.*t36.*t39 + (-1).* ...
  t10.*t12.*t45.*t8,t11.*t46.*t47 + t11.*t48 + t11.*t49,0,t50 + t51  ...
  + t52,t24.*((-1).*t12.*t19 + t10.*t11.*t4) + t39.*((-1).*t12.*t15  ...
  + t53) + (-1).*t10.*((-1).*t10.*t12.*t5 + (-1).*t11.*t6).*t8,0,0, ...
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

end %function