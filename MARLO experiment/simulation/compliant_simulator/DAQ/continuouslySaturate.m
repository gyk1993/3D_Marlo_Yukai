function usat = continuouslySaturate(u, q, thresholds, width, umax)
    
    usat = min(max(-umax, u), umax); % Base saturation
    
    if q >= thresholds(2)+width      % Prohibit any positive current
        usat = min(usat, 0);
    elseif q >= thresholds(2)        % Linearly saturate positive current
        usat = min(usat, (thresholds(2)+width-q)/width*umax);
    elseif q <= thresholds(1)-width  % Prohibit any negative current
        usat = max(usat, 0);
    elseif q <= thresholds(1)        % Linearly saturate negative current
        usat = max(usat, -(q-thresholds(1)+width)/width*umax);
    end
end
