function out1 = f_hCont_LeftStance(in1)
%F_HCONT_LEFTSTANCE
%    OUT1 = F_HCONT_LEFTSTANCE(IN1)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    26-Jan-2017 22:33:58

h1_1 = in1(:,1);
h1_2 = in1(:,2);
h1_3 = in1(:,3);
h1_4 = in1(:,4);
h1_5 = in1(:,5);
h1_6 = in1(:,6);
h1_7 = in1(:,7);
h2_1 = in1(:,8);
h2_2 = in1(:,9);
h2_3 = in1(:,10);
h2_4 = in1(:,11);
h2_5 = in1(:,12);
h2_6 = in1(:,13);
h2_7 = in1(:,14);
out1 = [-h1_1+h2_1;-h1_2+h2_2;-h1_3+h2_3;-h1_4+h2_4;-h1_5+h2_5;-h1_6+h2_6;-h1_7+h2_7];
