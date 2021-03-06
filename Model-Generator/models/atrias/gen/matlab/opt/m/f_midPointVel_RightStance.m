function out1 = f_midPointVel_RightStance(in1,N)
%F_MIDPOINTVEL_RIGHTSTANCE
%    OUT1 = F_MIDPOINTVEL_RIGHTSTANCE(IN1,N)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    26-Jan-2017 22:32:32

T = in1(:,1);
ddq1_1 = in1(:,18);
ddq1_2 = in1(:,19);
ddq1_3 = in1(:,20);
ddq1_4 = in1(:,21);
ddq1_5 = in1(:,22);
ddq1_6 = in1(:,23);
ddq1_7 = in1(:,24);
ddq1_8 = in1(:,25);
ddq1_9 = in1(:,26);
ddq3_1 = in1(:,66);
ddq3_2 = in1(:,67);
ddq3_3 = in1(:,68);
ddq3_4 = in1(:,69);
ddq3_5 = in1(:,70);
ddq3_6 = in1(:,71);
ddq3_7 = in1(:,72);
ddq3_8 = in1(:,73);
ddq3_9 = in1(:,74);
ddq1_10 = in1(:,27);
ddq1_11 = in1(:,28);
ddq1_12 = in1(:,29);
ddq1_13 = in1(:,30);
ddq1_14 = in1(:,31);
ddq1_15 = in1(:,32);
ddq1_16 = in1(:,33);
ddq3_10 = in1(:,75);
ddq3_11 = in1(:,76);
ddq3_12 = in1(:,77);
ddq3_13 = in1(:,78);
ddq3_14 = in1(:,79);
ddq3_15 = in1(:,80);
ddq3_16 = in1(:,81);
dq1_1 = in1(:,2);
dq1_2 = in1(:,3);
dq1_3 = in1(:,4);
dq1_4 = in1(:,5);
dq1_5 = in1(:,6);
dq1_6 = in1(:,7);
dq1_7 = in1(:,8);
dq1_8 = in1(:,9);
dq1_9 = in1(:,10);
dq2_1 = in1(:,34);
dq2_2 = in1(:,35);
dq2_3 = in1(:,36);
dq2_4 = in1(:,37);
dq2_5 = in1(:,38);
dq2_6 = in1(:,39);
dq2_7 = in1(:,40);
dq2_8 = in1(:,41);
dq2_9 = in1(:,42);
dq3_1 = in1(:,50);
dq3_2 = in1(:,51);
dq3_3 = in1(:,52);
dq3_4 = in1(:,53);
dq3_5 = in1(:,54);
dq3_6 = in1(:,55);
dq3_7 = in1(:,56);
dq3_8 = in1(:,57);
dq3_9 = in1(:,58);
dq1_10 = in1(:,11);
dq1_11 = in1(:,12);
dq1_12 = in1(:,13);
dq1_13 = in1(:,14);
dq1_14 = in1(:,15);
dq1_15 = in1(:,16);
dq1_16 = in1(:,17);
dq2_10 = in1(:,43);
dq2_11 = in1(:,44);
dq2_12 = in1(:,45);
dq2_13 = in1(:,46);
dq2_14 = in1(:,47);
dq2_15 = in1(:,48);
dq2_16 = in1(:,49);
dq3_10 = in1(:,59);
dq3_11 = in1(:,60);
dq3_12 = in1(:,61);
dq3_13 = in1(:,62);
dq3_14 = in1(:,63);
dq3_15 = in1(:,64);
dq3_16 = in1(:,65);
t2 = N-1.0;
t3 = 1.0./t2;
out1 = [dq1_1.*(-1.0./2.0)+dq2_1-dq3_1.*(1.0./2.0)-T.*t3.*(ddq1_1-ddq3_1).*(1.0./8.0);dq1_2.*(-1.0./2.0)+dq2_2-dq3_2.*(1.0./2.0)-T.*t3.*(ddq1_2-ddq3_2).*(1.0./8.0);dq1_3.*(-1.0./2.0)+dq2_3-dq3_3.*(1.0./2.0)-T.*t3.*(ddq1_3-ddq3_3).*(1.0./8.0);dq1_4.*(-1.0./2.0)+dq2_4-dq3_4.*(1.0./2.0)-T.*t3.*(ddq1_4-ddq3_4).*(1.0./8.0);dq1_5.*(-1.0./2.0)+dq2_5-dq3_5.*(1.0./2.0)-T.*t3.*(ddq1_5-ddq3_5).*(1.0./8.0);dq1_6.*(-1.0./2.0)+dq2_6-dq3_6.*(1.0./2.0)-T.*t3.*(ddq1_6-ddq3_6).*(1.0./8.0);dq1_7.*(-1.0./2.0)+dq2_7-dq3_7.*(1.0./2.0)-T.*t3.*(ddq1_7-ddq3_7).*(1.0./8.0);dq1_8.*(-1.0./2.0)+dq2_8-dq3_8.*(1.0./2.0)-T.*t3.*(ddq1_8-ddq3_8).*(1.0./8.0);dq1_9.*(-1.0./2.0)+dq2_9-dq3_9.*(1.0./2.0)-T.*t3.*(ddq1_9-ddq3_9).*(1.0./8.0);dq1_10.*(-1.0./2.0)+dq2_10-dq3_10.*(1.0./2.0)-T.*t3.*(ddq1_10-ddq3_10).*(1.0./8.0);dq1_11.*(-1.0./2.0)+dq2_11-dq3_11.*(1.0./2.0)-T.*t3.*(ddq1_11-ddq3_11).*(1.0./8.0);dq1_12.*(-1.0./2.0)+dq2_12-dq3_12.*(1.0./2.0)-T.*t3.*(ddq1_12-ddq3_12).*(1.0./8.0);dq1_13.*(-1.0./2.0)+dq2_13-dq3_13.*(1.0./2.0)-T.*t3.*(ddq1_13-ddq3_13).*(1.0./8.0);dq1_14.*(-1.0./2.0)+dq2_14-dq3_14.*(1.0./2.0)-T.*t3.*(ddq1_14-ddq3_14).*(1.0./8.0);dq1_15.*(-1.0./2.0)+dq2_15-dq3_15.*(1.0./2.0)-T.*t3.*(ddq1_15-ddq3_15).*(1.0./8.0);dq1_16.*(-1.0./2.0)+dq2_16-dq3_16.*(1.0./2.0)-T.*t3.*(ddq1_16-ddq3_16).*(1.0./8.0)];
