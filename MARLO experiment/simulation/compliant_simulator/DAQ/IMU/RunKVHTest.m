
%% Setup and open COM port
ser = serial('COM6','BaudRate',921600,'InputBufferSize', 2^30);
fopen(ser)

%%
HDR = hex2dec(['FE'; '81'; 'FF'; '55']);
Rx = @(t) [1 0 0 ; 0 cos(t) -sin(t); 0 sin(t) cos(t)];
Ry = @(t) [cos(t) 0 sin(t); 0 1 0 ; -sin(t) 0 cos(t)];
Rz = @(t) [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
Rot = @(q) Rz(q(1))*Ry(q(2))*Rx(q(3)); % Robot to world

%%
flushinput(ser);
%%
D   = fread(ser, ser.BytesAvailable);
idx = strfind(D', HDR');
idx = idx(idx<length(D)-35); % only find full packets

%%
N           = length(idx);
R           = zeros(N,3);
A           = zeros(N,3);
status      = zeros(N,1);
sequence    = zeros(N,1);
temperature = zeros(N,1);
valid       = zeros(N,1);

for k=1:length(idx)
    [R(k,:),A(k,:),status(k),sequence(k),temperature(k),valid(k)] = KVHParsePacket(D(idx(k)+(0:35)));
end


dseq = diff(sequence);
dseq(dseq==-127 & sequence(1:end-1)==127) = 1;
statusbits = bitget(repmat(status,1,6), repmat([1 2 3 5 6 7], length(status), 1));

%%
figure(1); clf;
h(1)=subplot(2,3,1); plot(sequence); title('Sequence');
h(2)=subplot(2,3,2); plot(dseq); title('diff(Sequence)');
h(3)=subplot(2,3,3); plot(temperature); title('Temperature (C)');
h(4)=subplot(2,3,[4 5]); plot(statusbits); title('Status'); legend('Gyro X', 'Gyro Y', 'Gyro Z', 'Accel X', 'Accel Y', 'Accel Z');
h(5)=subplot(2,3,6); plot(valid); title('Valid CRC');


figure(2); clf;
h(6)=gca; plot(R); hold on; plot(valid,'c'); hold off; title('DeltaAngle');
set(gca,'YLim',[-3 3]);

figure(3); clf;
h(7)=gca; plot(A); hold on; plot(valid,'c'); hold off; title('Accel');
set(gca,'YLim',[-3 3]);

linkaxes(h,'x');

%%
t=0.001*(1:length(sequence));
Accel = A;
Rhat = zeros(3,3,length(t));
a0 = mean(Accel(1:5,:));
a0 = a0/norm(a0);
qy0 = asin(a0(1));
qx0 = asin(-a0(2)/cos(qy0));
%qx0 = asin(-a0(2));
%qy0 = asin(a0(1)/cos(qx0));
Rhat0 = Rot([0 qy0 qx0]);

Rhat(:,:,1) = Rhat0;
dt = (t(2)-t(1));
S = @(w) [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
for j=2:length(t)
    da = R(j,:)';
    k = da/norm(da);
    theta = norm(da);
    Rk = eye(3)*cos(theta) + S(k)*sin(theta) + (1-cos(theta))*(k*k');
    Rhat(:,:,j) = Rhat(:,:,j-1)*Rk;
end
%%
Rhat = RHAT;
t=(1:length(RHAT))*0.001;
%qThat = M_to_ZYX(Rhat)'; XYZ = [3 2 1];
qThat = M_to_XYZ(Rhat)'; XYZ = [1 2 3];



%figure(10); clf;
%plot(t,Accel);
%{
figure(11); clf;
plot(t,cumsum(R)*180/pi); hold on; plot(t,qThat(:,XYZ)*180/pi, '--'); hold off; title('Cumsum R (-) and Euler angles (--)'); ylabel('(deg)');
figure(12); clf;
plot(t,cumsum(R)*180/pi-qThat(:,XYZ)*180/pi); hold off; title('Cumsum R - Euler angles'); ylabel('(deg)');
%}
figure(11); clf;
plot(t,qThat(:,XYZ)*180/pi); title('Euler angles'); ylabel('(deg)');
