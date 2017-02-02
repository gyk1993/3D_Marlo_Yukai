function decodeErrorFlags(t,ErrorFlags,F0)
    
    %     medulla_error_estop         = 1<<0,
    %     medulla_error_limit_switch  = 1<<1,
    %     medulla_error_thermistor    = 1<<2,
    %     medulla_error_motor_voltage = 1<<3,
    %     medulla_error_logic_voltage = 1<<4,
    %     medulla_error_encoder       = 1<<5,
    %     medulla_error_halt          = 1<<6,
    %     medulla_error_amplifier     = 1<<7
    
    if isstruct(t)
        log = t;
        t = log.t;
        ErrorFlags = log.ErrorFlags;
    end
    if nargin<3
        F0 = 100;
    end
    
    ErrorFlags = uint8(ErrorFlags);
    
    ErrorFlagStrings = {'E-stop','Limit switch','Thermistor','Motor voltage','Logic voltage','Encoder','Halt','Amplifier'};
    %MedullaStrings   = 
    ErrorFlagsDecoded = arrayfun(@(b)bitget(ErrorFlags,b), 1:8, 'Uni', 0);
    
    figure(F0);
    h = zeros(6,1);
    for k=1:6
        h(k) = subplot(6,1,k); plot(t, ErrorFlagsDecoded{k});
        title(sprintf('%s (%d)',ErrorFlagStrings{k},k-1));
    end
    linkaxes(h,'x');
    set(h,'YLim',[-0.2 1.2]);
    %longdatacursor(h);
end
