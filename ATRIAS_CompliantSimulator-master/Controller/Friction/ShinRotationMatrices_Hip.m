function [R1,R5]= ShinRotationMatrices_Hip(q)
%#codegen
%%%%%%  ShinRotationMatrices_Hip.m
%%%%  11-Jan-2013 09:28:56
%%%%
%%%% Authors(s): Grizzle
%%%%
%%%%
%%%%
%%%%
%%%%
%%%%
xT=q(1);  
yT=q(2);  
zT=q(3);  
qzT=q(4);  
qyT=q(5);  
qxT=q(6);  
q1R=q(7);  
q2R=q(8);  
q1L=q(9);  
q2L=q(10);  
qgr1R=q(11);  
qgr2R=q(12);  
q3R=q(13);  
qgr1L=q(14);  
qgr2L=q(15);  
q3L=q(16);  
%%%%
%%%%
R1=zeros(3,3);
R1(1,1)=cos(qzT)*cos(qyT)*cos(q3R)-(sin(qzT)*sin(qxT)+cos(qzT)*...
         sin(qyT)*cos(qxT))*sin(q3R);
R1(1,2)=(-sin(qzT)*cos(qxT)+cos(qzT)*sin(qyT)*sin(qxT))*...
         cos(q1R)+(cos(qzT)*cos(qyT)*sin(q3R)+(sin(qzT)*sin(qxT)+cos(qzT)*...
         sin(qyT)*cos(qxT))*cos(q3R))*sin(q1R);
R1(1,3)=-(-sin(qzT)*cos(qxT)+cos(qzT)*sin(qyT)*sin(qxT))*...
         sin(q1R)+(cos(qzT)*cos(qyT)*sin(q3R)+(sin(qzT)*sin(qxT)+cos(qzT)*...
         sin(qyT)*cos(qxT))*cos(q3R))*cos(q1R);
R1(2,1)=sin(qzT)*cos(qyT)*cos(q3R)-(-cos(qzT)*sin(qxT)+sin(qzT)*...
         sin(qyT)*cos(qxT))*sin(q3R);
R1(2,2)=(cos(qzT)*cos(qxT)+sin(qzT)*sin(qyT)*sin(qxT))*...
         cos(q1R)+(sin(qzT)*cos(qyT)*sin(q3R)+(-cos(qzT)*...
         sin(qxT)+sin(qzT)*sin(qyT)*cos(qxT))*cos(q3R))*sin(q1R);
R1(2,3)=-(cos(qzT)*cos(qxT)+sin(qzT)*sin(qyT)*sin(qxT))*...
         sin(q1R)+(sin(qzT)*cos(qyT)*sin(q3R)+(-cos(qzT)*...
         sin(qxT)+sin(qzT)*sin(qyT)*cos(qxT))*cos(q3R))*cos(q1R);
R1(3,1)=-sin(qyT)*cos(q3R)-cos(qyT)*cos(qxT)*sin(q3R);
R1(3,2)=cos(qyT)*sin(qxT)*cos(q1R)+(-sin(qyT)*sin(q3R)+cos(qyT)*...
         cos(qxT)*cos(q3R))*sin(q1R);
R1(3,3)=-cos(qyT)*sin(qxT)*sin(q1R)+(-sin(qyT)*sin(q3R)+cos(qyT)*...
         cos(qxT)*cos(q3R))*cos(q1R);
%%%%
%%%%
R5=zeros(3,3);
R5(1,1)=cos(qzT)*cos(qyT)*cos(q3L)+(sin(qzT)*sin(qxT)+cos(qzT)*...
         sin(qyT)*cos(qxT))*sin(q3L);
R5(1,2)=(-sin(qzT)*cos(qxT)+cos(qzT)*sin(qyT)*sin(qxT))*...
         cos(q1L)+(-cos(qzT)*cos(qyT)*sin(q3L)+(sin(qzT)*...
         sin(qxT)+cos(qzT)*sin(qyT)*cos(qxT))*cos(q3L))*sin(q1L);
R5(1,3)=-(-sin(qzT)*cos(qxT)+cos(qzT)*sin(qyT)*sin(qxT))*...
         sin(q1L)+(-cos(qzT)*cos(qyT)*sin(q3L)+(sin(qzT)*...
         sin(qxT)+cos(qzT)*sin(qyT)*cos(qxT))*cos(q3L))*cos(q1L);
R5(2,1)=sin(qzT)*cos(qyT)*cos(q3L)+(-cos(qzT)*sin(qxT)+sin(qzT)*...
         sin(qyT)*cos(qxT))*sin(q3L);
R5(2,2)=(cos(qzT)*cos(qxT)+sin(qzT)*sin(qyT)*sin(qxT))*...
         cos(q1L)+(-sin(qzT)*cos(qyT)*sin(q3L)+(-cos(qzT)*...
         sin(qxT)+sin(qzT)*sin(qyT)*cos(qxT))*cos(q3L))*sin(q1L);
R5(2,3)=-(cos(qzT)*cos(qxT)+sin(qzT)*sin(qyT)*sin(qxT))*...
         sin(q1L)+(-sin(qzT)*cos(qyT)*sin(q3L)+(-cos(qzT)*...
         sin(qxT)+sin(qzT)*sin(qyT)*cos(qxT))*cos(q3L))*cos(q1L);
R5(3,1)=-sin(qyT)*cos(q3L)+cos(qyT)*cos(qxT)*sin(q3L);
R5(3,2)=cos(qyT)*sin(qxT)*cos(q1L)+(sin(qyT)*sin(q3L)+cos(qyT)*...
         cos(qxT)*cos(q3L))*sin(q1L);
R5(3,3)=-cos(qyT)*sin(qxT)*sin(q1L)+(sin(qyT)*sin(q3L)+cos(qyT)*...
         cos(qxT)*cos(q3L))*cos(q1L);
%%%%
%%%%
end