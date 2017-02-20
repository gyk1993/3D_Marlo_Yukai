% q_test=DataVec(1:17,:);
u=DataVec(33:40,:);
y=DataVec(41:46,:);
dy=DataVec(47:52,:);
s=DataVec(53,:);
cs=DataVec(54,:);



%% plot joint angles
figure

index=[7 8 13 9 10 16];
joint={'qAR','qBR','qHR','qAL','qBL','qHL'};
for i=1:length(index)
subplot(2,3,i)
plot(t,q(:,index(i)))
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
%% plot velocity for x y z pitch roll yaw
figure
index=[1 2 3 6 5 4];
joint={'x velocity' 'y velocity' 'z velocity' 'pitch velocity' 'roll velocity' 'yaw velocity'};
for i=1:length(index)
subplot(2,3,i)
plot(t,dq(:,index(i)))
title(joint{i})
end

%% plot torque
% figure
% 

%% plot y dy
figure
index=[1,3,5,2,4,6];
name={'y Right Leg','y Right Knee','y Right Hip','y Left Leg','y Left Knee','y Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,y(index(i),:))
title(name{i})
end

figure
index=[1,3,5,2,4,6];
name={'dy Right Leg','dy Right Knee','dy Right Hip','dy Left Leg','dy Left Knee','dy Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,dy(index(i),i))
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