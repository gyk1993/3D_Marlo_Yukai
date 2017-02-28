function saveLogAliFormat(filename)
    [t, q, dq, u, y, dy, hd, s_saturated, s_actual, theta, stance_leg, serial_out, Switches, IMU] = parseLog(filename);
    s = s_saturated;
    ds = 0*s;
    state = [y, dy, s_saturated, ds, stance_leg, u, q, dq, Switches, IMU, hd];
    time = t;
    
    save(regexprep(filename, '(.)(\.mat)?$', '$1a.mat'), 'time', 'state');
end
