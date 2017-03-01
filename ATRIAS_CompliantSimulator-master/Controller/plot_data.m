% q_test=DataVec(1:17,:);
% u=DataVec(35:40,:);
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
joint={'uAR','uBR','uHR','uAL','uBL','uHL'};
for i=1:6
    subplot(2,3,i)
    plot(t,u(:,i));
    title(joint{i})
    axis([0 t(end) -6 6])
end
% Joint torque to leg knee torque

uL=(M_J2L*u')';
figure
index=[1 2 3 4 5 6];
joint={'uLegR','uKneeR','uHipR','uLegL','uKneeL','uHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,uL(:,i));
    title(joint{i})
    axis([0 t(end) -6 6])
end
%% plot h0

figure
index=[1 2 3 4 5 6];
joint={'qLegR','qKneeR','qHipR','qLegL','qKneeL','qHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,h0(i,:));
    title(joint{i})
end


figure
index=[1 2 3 4 5 6];
joint={'dqLegR','dqKneeR','dqHipR','dqLegL','dqKneeL','dqHipL'};
for i=1:6
    subplot(2,3,i)
    plot(t,dh0(i,:));
    title(joint{i})
end
%% plot hd dhd
figure
index=[1,3,5,2,4,6];
name={'hd Right Leg','hd Right Knee','hd Right Hip','hd Left Leg','hd Left Knee','hd Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,hd(index(i),:))
title(name{i})
end

figure
index=[1,3,5,2,4,6];
name={'dhd Right Leg','dhd Right Knee','dhd Right Hip','dhd Left Leg','dhd Left Knee','dhd Left Hip'};
for i=1:length(index)
subplot(2,3,i)
plot(t,dhd(index(i),:))
title(name{i})
end

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
plot(t,dy(index(i),:))
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
subplot(2,2,3)
plot(t,pitch_tune_fil);
title('filtered pitch tune');
subplot(2,2,4)
plot(t,roll_tune_fil);
title('filtered roll tune');

figure
plot(t,dh0(1,:)'+dq(:,6))
