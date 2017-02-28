function [q_new, dq_new] = ConvertNewSpringlessToSpringCoord(q_old, dq_old)
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


q_new(1:3,:) = q_old(1:3,:);
q_new(4:6,:) = q_old(4:6,:);
q_new(7:8,:) = q_old(5:6,:);
q_new(9:10,:) = q_old(7:8,:);
q_new(11:13,:) = q_old(9:11,:);
q_new(14:15,:) = q_old(10:11,:);
q_new(16:17,:) = q_old(12:13,:);

dq_new(1:3,:) = dq_old(1:3,:);
dq_new(4:6,:) = dq_old(4:6,:);
dq_new(7:8,:) = dq_old(5:6,:);
dq_new(9:10,:) = dq_old(7:8,:);
dq_new(11:13,:) = dq_old(9:11,:);
dq_new(14:15,:) = dq_old(10:11,:);
dq_new(16:17,:) = dq_old(12:13,:);


q_new = [basePos; q_new];
dq_new = [baseVel; dq_new];

end
