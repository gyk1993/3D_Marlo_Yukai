function set_scopes(tg, id)
    
    if id==1
        %% Controls
        
        scs=getscope(tg);
        scs.stop;
        scs(1).remsignal();
        scs(2).remsignal();
        scs(3).remsignal();
        scs(4).remsignal();
        scs(5).remsignal();
        scs(6).remsignal();
        
        scs(1).addsignal(getsignalid(tg,'Controller/controller/p1/s1'));
        scs(2).addsignal(getsignalid(tg,'Controller/controller/p1/s2'));
        scs(3).addsignal(getsignalid(tg,'Controller/controller/p1/s3'));
        scs(4).addsignal(getsignalid(tg,'Controller/controller/p1/s4'));
        scs(5).addsignal(getsignalid(tg,'Controller/controller/p1/s5'));
        scs(6).addsignal(getsignalid(tg,'Controller/controller/p1/s6'));
        set(scs(1:6), 'YLimit', [-30 30]);
        scs.start();
        
    elseif id==2
        %% Errors
        scs=getscope(tg);
        scs.stop;
        scs(1).remsignal();
        scs(2).remsignal();
        scs(3).remsignal();
        scs(4).remsignal();
        scs(5).remsignal();
        scs(6).remsignal();
        
        scs(1).addsignal(getsignalid(tg,'Controller/controller/p2/s1'));
        scs(2).addsignal(getsignalid(tg,'Controller/controller/p2/s2'));
        scs(3).addsignal(getsignalid(tg,'Controller/controller/p2/s3'));
        scs(4).addsignal(getsignalid(tg,'Controller/controller/p2/s4'));
        scs(5).addsignal(getsignalid(tg,'Controller/controller/p2/s5'));
        scs(6).addsignal(getsignalid(tg,'Controller/controller/p2/s6'));
        set(scs(1:6), 'YLimit', [-30 30]*pi/180);
        scs.start();
        
    elseif id==3
                %% Controls after saturation
        
        scs=getscope(tg);
        scs.stop;
        scs(1).remsignal();
        scs(2).remsignal();
        scs(3).remsignal();
        scs(4).remsignal();
        scs(5).remsignal();
        scs(6).remsignal();
        
        scs(1).addsignal(getsignalid(tg,'Saturation/s1'));
        scs(2).addsignal(getsignalid(tg,'Saturation/s2'));
        scs(3).addsignal(getsignalid(tg,'Saturation/s3'));
        scs(4).addsignal(getsignalid(tg,'Saturation/s4'));
        scs(5).addsignal(getsignalid(tg,'Saturation/s5'));
        scs(6).addsignal(getsignalid(tg,'Saturation/s6'));
        set(scs(1:6), 'YLimit', [-30 30]);
        scs.start();
        
    end
    