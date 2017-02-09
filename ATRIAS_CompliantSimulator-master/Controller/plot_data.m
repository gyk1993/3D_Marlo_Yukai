figure
index=[13 16 7 9 8 10];
joint={'qHR','qHL','qAR','qAL','qBR','qBL'}
for i=1:length(index)
subplot(3,2,i)
plot(t,q(:,index(i)))
title(joint{i})
end

figure
index=[1 2 3 6 5 4];
joint={'x' 'y' 'z' 'pitch' 'roll' 'yaw'}
for i=1:length(index)
subplot(2,3,i)
plot(t,q(:,index(i)))
title(joint{i})
end

figure
for i=1:6(index)
subplot(2,3,i)
plot(t,q(:,index(i)))
title(joint{i})
end