function R = convertQtoRotation(q) %#codegen
    q = q(:); % ensure q is a column vector
    R = (q(1)^2 - 0.5) * eye(3) + (q(2:4)*q(2:4).') - q(1) * [0 -q(4) q(3); q(4) 0 -q(2); -q(3) q(2) 0];
end
