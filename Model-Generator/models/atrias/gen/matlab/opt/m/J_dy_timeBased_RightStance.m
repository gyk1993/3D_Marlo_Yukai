function out1 = J_dy_timeBased_RightStance(in1,in2)
%J_DY_TIMEBASED_RIGHTSTANCE
%    OUT1 = J_DY_TIMEBASED_RIGHTSTANCE(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    26-Jan-2017 22:34:18

N = in2(:,1);
T = in1(:,33);
a_1_1 = in1(:,34);
a_1_2 = in1(:,40);
a_1_3 = in1(:,46);
a_1_4 = in1(:,52);
a_1_5 = in1(:,58);
a_1_6 = in1(:,64);
a_2_1 = in1(:,35);
a_2_2 = in1(:,41);
a_2_3 = in1(:,47);
a_2_4 = in1(:,53);
a_2_5 = in1(:,59);
a_2_6 = in1(:,65);
a_3_1 = in1(:,36);
a_3_2 = in1(:,42);
a_3_3 = in1(:,48);
a_3_4 = in1(:,54);
a_3_5 = in1(:,60);
a_3_6 = in1(:,66);
a_4_1 = in1(:,37);
a_4_2 = in1(:,43);
a_4_3 = in1(:,49);
a_4_4 = in1(:,55);
a_4_5 = in1(:,61);
a_4_6 = in1(:,67);
a_5_1 = in1(:,38);
a_5_2 = in1(:,44);
a_5_3 = in1(:,50);
a_5_4 = in1(:,56);
a_5_5 = in1(:,62);
a_5_6 = in1(:,68);
a_6_1 = in1(:,39);
a_6_2 = in1(:,45);
a_6_3 = in1(:,51);
a_6_4 = in1(:,57);
a_6_5 = in1(:,63);
a_6_6 = in1(:,69);
index = in2(:,2);
t5 = N-1.0;
t6 = 1.0./t5;
t7 = index-1.0;
t8 = t6.*t7;
t2 = t8-1.0;
t3 = t2.^2;
t4 = 1.0./T.^2;
t9 = t3.^2;
t10 = t7.^2;
t11 = 1.0./t5.^4;
t12 = t10.^2;
t13 = 1.0./t5.^3;
t14 = 1.0./t5.^2;
t15 = 1.0./T;
t16 = t9.*t15.*5.0;
t17 = t3.*t10.*t14.*t15.*3.0e1;
t18 = t6.*t7.*5.0;
t19 = t18-5.0;
t20 = t11.*t12.*t15.*5.0;
t21 = t2.*t3.*t6.*t7.*t15.*2.0e1;
t22 = t17+t21;
t27 = t2.*t7.*t10.*t13.*t15.*2.0e1;
t23 = -t17-t27;
t24 = t7.*t10.*t13.*t15.*t19.*4.0;
t25 = t20+t24;
t26 = -t16-t21;
out1 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,a_1_1.*t4.*t9.*-5.0+a_2_1.*t4.*t9.*5.0-a_5_1.*t4.*t11.*t12.*5.0+a_6_1.*t4.*t11.*t12.*5.0-a_3_1.*t3.*t4.*t10.*t14.*3.0e1+a_4_1.*t3.*t4.*t10.*t14.*3.0e1+a_2_1.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_1.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_1.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_1.*t4.*t7.*t10.*t13.*t19.*4.0,a_1_2.*t4.*t9.*-5.0+a_2_2.*t4.*t9.*5.0-a_5_2.*t4.*t11.*t12.*5.0+a_6_2.*t4.*t11.*t12.*5.0-a_3_2.*t3.*t4.*t10.*t14.*3.0e1+a_4_2.*t3.*t4.*t10.*t14.*3.0e1+a_2_2.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_2.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_2.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_2.*t4.*t7.*t10.*t13.*t19.*4.0,a_1_3.*t4.*t9.*-5.0+a_2_3.*t4.*t9.*5.0-a_5_3.*t4.*t11.*t12.*5.0+a_6_3.*t4.*t11.*t12.*5.0-a_3_3.*t3.*t4.*t10.*t14.*3.0e1+a_4_3.*t3.*t4.*t10.*t14.*3.0e1+a_2_3.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_3.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_3.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_3.*t4.*t7.*t10.*t13.*t19.*4.0,a_1_4.*t4.*t9.*-5.0+a_2_4.*t4.*t9.*5.0-a_5_4.*t4.*t11.*t12.*5.0+a_6_4.*t4.*t11.*t12.*5.0-a_3_4.*t3.*t4.*t10.*t14.*3.0e1+a_4_4.*t3.*t4.*t10.*t14.*3.0e1+a_2_4.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_4.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_4.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_4.*t4.*t7.*t10.*t13.*t19.*4.0,a_1_5.*t4.*t9.*-5.0+a_2_5.*t4.*t9.*5.0-a_5_5.*t4.*t11.*t12.*5.0+a_6_5.*t4.*t11.*t12.*5.0-a_3_5.*t3.*t4.*t10.*t14.*3.0e1+a_4_5.*t3.*t4.*t10.*t14.*3.0e1+a_2_5.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_5.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_5.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_5.*t4.*t7.*t10.*t13.*t19.*4.0,a_1_6.*t4.*t9.*-5.0+a_2_6.*t4.*t9.*5.0-a_5_6.*t4.*t11.*t12.*5.0+a_6_6.*t4.*t11.*t12.*5.0-a_3_6.*t3.*t4.*t10.*t14.*3.0e1+a_4_6.*t3.*t4.*t10.*t14.*3.0e1+a_2_6.*t2.*t3.*t4.*t6.*t7.*2.0e1-a_3_6.*t2.*t3.*t4.*t6.*t7.*2.0e1+a_4_6.*t2.*t4.*t7.*t10.*t13.*2.0e1-a_5_6.*t4.*t7.*t10.*t13.*t19.*4.0,t16,0.0,0.0,0.0,0.0,0.0,-t16-t2.*t3.*t6.*t7.*t15.*2.0e1,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20,0.0,0.0,0.0,0.0,0.0,0.0,t16,0.0,0.0,0.0,0.0,0.0,t26,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20,0.0,0.0,0.0,0.0,0.0,0.0,t16,0.0,0.0,0.0,0.0,0.0,t26,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20,0.0,0.0,0.0,0.0,0.0,0.0,t16,0.0,0.0,0.0,0.0,0.0,t26,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20,0.0,0.0,0.0,0.0,0.0,0.0,t16,0.0,0.0,0.0,0.0,0.0,t26,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20,0.0,0.0,0.0,0.0,0.0,0.0,t16,0.0,0.0,0.0,0.0,0.0,t26,0.0,0.0,0.0,0.0,0.0,t22,0.0,0.0,0.0,0.0,0.0,t23,0.0,0.0,0.0,0.0,0.0,t25,0.0,0.0,0.0,0.0,0.0,-t20],[6,69]);
