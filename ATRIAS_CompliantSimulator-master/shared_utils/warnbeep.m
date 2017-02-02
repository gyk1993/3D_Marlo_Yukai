function warnbeep()
    f  = 2000; % (Hz)
    A  = 0.6;
    Fs = 16000;
    t  = (0:1/Fs:0.05);
    sound(A*sin(2*pi*f*t));
end
