function [q_new, dq_new] = ConvertToNewCoord(q_old, dq_old)
%#codegen
if size(q_old,1) > 13
    basePos = q_old(1:3,:);
    baseVel = dq_old(1:3,:);
    
    q_old = q_old(4:end,:);
    dq_old = dq_old(4:end,:);
else
    basePos = zeros(0, size(q_old,2));
    baseVel = zeros(0, size(dq_old,2));
end

q_new = zeros(17,size(q_old,2));
dq_new = zeros(17,size(dq_old,2));

% q_new = [pitch; roll; yaw;
%          qHR; qAR; qBR; qAgrR; qBgrR; FourBarAR; FourBarBR;
%          qHL; qAL; qBL; qAgrL; qBgrL; FourBarAL; FourBarBL];

% Orientation
q_new(1:3,:) = q_old([3,2,1],:); 
dq_new(1:3,:) = dq_old([3,2,1],:); 

% Right Side
q_new(4:8,:) = q_old([10,4,5,8,9],:); 
dq_new(4:8,:) = dq_old([10,4,5,8,9],:); 
q_new(9:10,:) = q_old([5,4],:) - q_old([4,5],:);
dq_new(9:10,:) = dq_old([5,4],:) - dq_old([4,5],:);


% Left Side
q_new(11:15,:) = q_old([13,6,7,11,12],:); 
dq_new(11:15,:) = dq_old([13,6,7,11,12],:); 
q_new(16:17,:) = q_old([7,6],:) - q_old([6,7],:);
dq_new(16:17,:) = dq_old([7,6],:) - dq_old([6,7],:);
q_new(11,:) = -q_new(11,:);
dq_new(11,:) = -dq_new(11,:);


q_new = [basePos; q_new];
dq_new = [baseVel; dq_new];

end
