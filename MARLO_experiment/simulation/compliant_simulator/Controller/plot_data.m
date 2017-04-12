% q_test=DataVec(1:17,:);
% u=DataVec(35:40,:);
DataVec=log.DataVec';
t=log.t;
% u=log.u_current;
q=DataVec(1:17,:);
dq=DataVec(18:34,:);
%%
% q=DataVec(1:17,:);
% dq=DataVec(18:34,:);
u=DataVec(35:40,:);
y=DataVec(41:46,:);
dy=DataVec(47:52,:);
s=DataVec(53,:);
cs=DataVec(54,:);
hd=DataVec(55:60,:);
dhd=DataVec(61:66,:);
h0=DataVec(67:72,:);
dh0=DataVec(73:78,:);
pitch_tune=DataVec(79,:);
roll_tune=DataVec(80,:);
pitch_tune_fil=DataVec(81,:);
roll_tune_fil=DataVec(82,:);
hd_j=DataVec(83:88,:);
dhd_j=DataVec(89:94,:);
y_j=DataVec(95:100,:);
dy_j=DataVec(101:106,:);
h0_j=DataVec(107:112,:);
dh0_j=DataVec(113:118,:);
spring_compressed=DataVec(119:122,:);
ground_force=DataVec(123:124,:);
s_force=DataVec(125:126,:);
V_measured=DataVec(127:129,:);
V_filtered=DataVec(130:132,:);
StanceLeg=DataVec(133,:);
hd_o=DataVec(134:139,:);
dhd_o=DataVec(140:145,:);


M_J2L=[1/2 1/2 0 0 0 0;
    -1 1 0 0 0 0;
    0 0 1 0 0 0;
    0 0 0 1/2 1/2 0;
    0 0 0 -1 1 0;
    0 0 0 0 0 1];



%% plot joint angles
figure

index=[7 8 13 9 10 16];
joint={'qAR','qBR','qHR','qAL','qBL','qHL'};
for i=1:length(index)
subplot(2,3,i)
plot(t,q(index(i),:))
title(joint{i})
end
%% plot x y z pitch roll yaw
figure
index=[1 2 3 6 5 4];
joint={'x' 'y' 'z' 'pitch' 'roll' 'yaw'};
for i=1:length(index)
subplot(2,3,i)
plot(t,q(:,index(i)))
title(joint{i})
end

figure
index=[1 2 3 6 5 4];
joint={'x velocity' 'y velocity' 'z velocity' 'pitch velocity' 'roll velocity' 'yaw velocity'};
for i=1:length(index)
subplot(2,3,i)
plot(t,dq(:,index(i)))
title(joint{i})
end

%% plot torque
figure
index=[1 2 3 4 5 6];
joint={'uHR','uAR','uBR','uHL','uAL','uBL'};
for i=1:6
    subplot(2,3,i)
    plot(t,u(i,:));
    title(joint{i})
    axis([0 t(end) -6 6])
end
% Joint torque to leg knee torque

uL=(M_J2L*u);
figure
index=[1 2 3 4 5 6];
joint={'uLegR','uKneeR','uHipR','uLegL','uKneeL','uHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,uL(i,:));
    title(joint{i})
    axis([0 t(end) -12 12])
end
%% plot h0

figure
index=[1 3 5 2 4 6];
joint={'qLegR','qKneeR','qHipR','qLegL','qKneeL','qHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,180/pi*h0(index(i),:));
    title(joint{i})
end


figure
index=[1 3 5 2 4 6];
joint={'dqLegR','dqKneeR','dqHipR','dqLegL','dqKneeL','dqHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,180/pi*dh0(index(i),:));
    title(joint{i})
end
%% plot hd dhd
figure
index=[1,3,5,2,4,6];
name={'hd Right Leg','hd Right Knee','hd Right Hip','hd Left Leg','hd Left Knee','hd Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*hd(index(i),:))
title(name{i})
end

figure
index=[1,3,5,2,4,6];
name={'dhd Right Leg','dhd Right Knee','dhd Right Hip','dhd Left Leg','dhd Left Knee','dhd Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*dhd(index(i),:))
title(name{i})
end

%% plot hd_j dhd_j
figure
index=[2 3 1 5 6 4];
name={'hd_AR','hd_BR','hd_HR','hd_AL','hd_BL','hd_HL'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*hd_j(index(i),:))
title(name{i})
end

figure
index=[2 3 1 5 6 4];
name={'dhd_AR','dhd_BR','dhd_HR','dhd_AL','dhd_BL','dhd_HL'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*dhd_j(index(i),:))
title(name{i})
end

%% plot y dy
figure
index=[1,3,5,2,4,6];
name={'y Right Leg','y Right Knee','y Right Hip','y Left Leg','y Left Knee','y Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*y(index(i),:))
title(name{i})
end

figure
index=[1,3,5,2,4,6];
name={'dy Right Leg','dy Right Knee','dy Right Hip','dy Left Leg','dy Left Knee','dy Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*dy(index(i),:))
title(name{i})
end

%% plot s cs
figure
subplot(1,2,1)
plot(t,s);
title('s')
subplot(1,2,2)
plot(t,cs);
title('cs')
%% plot foot placement tuning
figure
subplot(2,2,1)
plot(t,pitch_tune);
title('pitch tune');
subplot(2,2,2)
plot(t,roll_tune);
title('roll tune');
% subplot(2,2,3)
% plot(t,pitch_tune_fil);
% title('filtered pitch tune');
% subplot(2,2,4)
% plot(t,roll_tune_fil);
% title('filtered roll tune');

% figure
% plot(t,dh0(1,:)'+dq(:,6))
%% plot vertical ground force
figure
plot(t,ground_force(1,:))
hold on
plot(t,ground_force(2,:))
plot(t,100*StanceLeg,'g--')
hold off
legend('right','left','StanceLeg')
title('ground force')
%% plot s_R s_L
figure
subplot(3,1,1)
plot(t,s_force(1,:))
title('s_R')

subplot(3,1,2)
plot(t,s_force(2,:))
title('s_L')

subplot(3,1,3)
plot(t,StanceLeg)
title('StanceLeg')

%% plot velocity

figure
subplot(3,1,1)
plot(t,V_measured(1,:))
hold on
plot(t,V_filtered(1,:))
hold off
title('Vx')
legend('measured','filtered')
subplot(3,1,2)
plot(t,V_measured(2,:))
hold on
plot(t,V_filtered(2,:))
hold off
title('Vy')
legend('measured','filtered')
subplot(3,1,3)
plot(t,V_measured(3,:))
hold on
plot(t,V_filtered(3,:))
hold off
title('Vz')
legend('measured','filtered')
%% plot orignal bazier
figure
index=[1,3,5,2,4,6];
name={'hd_o Right Leg','hd_o Right Knee','hd_o Right Hip','hd_o Left Leg','hd_o Left Knee','hd_o Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*hd_o(index(i),:))
title(name{i})
end

figure
index=[1,3,5,2,4,6];
name={'dhd_o Right Leg','dhd_o Right Knee','dhd_o Right Hip','dhd_o Left Leg','dhd_o Left Knee','dhd_o Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*dhd_o(index(i),:))
title(name{i})
end
%% plot error for orginal bazier and actual outputs
figure
index=[1,3,5,2,4,6];
name={'yo Right Leg','yo Right Knee','yo Right Hip','yo Left Leg','yo Left Knee','yo Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,180/pi*(h0(index(i),:)-hd_o(index(i),:)))
title(name{i})
end


