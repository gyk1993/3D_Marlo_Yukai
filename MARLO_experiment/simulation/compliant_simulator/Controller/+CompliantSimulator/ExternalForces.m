function [F] = ExternalForces(t, q, dq)
    isTest_holdInAir = false;
    isTest_dropTest = false;
    isTest_GradualdropTest = true;
    isTest_dropAndLiftTest = false;
    
    F = zeros(6, 1);
    kpboom = 10000;
    kdboom = 1000;
    
    height = 1.05;
    
    if isTest_holdInAir
        F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
        F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
        F(3) = F(3)+kpboom*(q(3)-height)+kdboom*dq(3); % Hang in the air
        F(4:6) = F(4:6)+kpboom*(q(4:6)-[0;0;0])+kdboom*dq(4:6);   % yaw, roll, pitch
    end
    
    if isTest_dropTest
        if t < 0.3
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
            F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
            F(3) = F(3)+kpboom*(q(3)-height)+kdboom*dq(3); % Hang in the air
            F(4:6) = F(4:6)+kpboom*(q(4:6)-[0;0;0])+kdboom*dq(4:6);   % yaw, roll, pitch
        else
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % x
            %F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % y
            F(4) = F(4)+kpboom*(q(4)-0)+kdboom*dq(4);   % Yaw
            %F(5) = F(5)+kpboom*(q(5)-0)+kdboom*dq(5);   % Roll
            %F(6) = F(6)+kpboom*(q(6)-0)+kdboom*dq(6);   % pitch
            
            F(2) = F(2)+kpboom*(q(2) - 0.1*sin(10*t))+kdboom*dq(2);   % y - sin()
            if 7 < t && t < 8
            %    F(6) = 1.5*50;
            end
        end
    end
    
    if isTest_GradualdropTest
        if t < 0.3
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
            F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
            F(3) = F(3)+kpboom*(q(3)-height)+kdboom*dq(3); % Hang in the air
            F(4:6) = F(4:6)+kpboom*(q(4:6)-[0;0;0])+kdboom*dq(4:6);   % yaw, roll, pitch
        else
            %F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % x
            %F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % y
            F(4) = F(4)+kpboom*(q(4)-0)+kdboom*dq(4);   % Yaw
            %F(5) = F(5)+kpboom*(q(5)-0)+kdboom*dq(5);   % Roll
            %F(6) = F(6)+kpboom*(q(6)-0)+kdboom*dq(6);   % pitch
            
            gradualHeight = height - 0.3*t;
            if q(3) < gradualHeight
                F(3) = F(3)+kpboom*(q(3)-gradualHeight)+kdboom*dq(3); % Hang in the air
                F(5) = F(5)+kpboom*(q(5)-0)+kdboom*dq(5);   % Roll
                F(6) = F(6)+kpboom*(q(6)-0)+kdboom*dq(6);   % pitch
            end
        end
    end
    
    if t > 10 && t < 10.35
        F(2) = F(2) + 100;
    end
    
    if isTest_dropAndLiftTest
        if t < 3
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
            F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
            F(3) = F(3)+kpboom*(q(3)-height)+kdboom*dq(3); % Hang in the air
            F(4:6) = F(4:6)+kpboom*(q(4:6)-[0;0;0])+kdboom*dq(4:6);   % pitch and Roll
        elseif t > 4.2
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
            F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
            F(3) = F(3)+kpboom*(q(3)-height)+kdboom*dq(3); % Hang in the air
            F(4:6) = F(4:6)+kpboom*(q(4:6)-[0;0;-pi/6])+kdboom*dq(4:6);   % pitch and Roll
        else
            F(1) = F(1)+kpboom*(q(1))+kdboom*dq(1);   % Side
            % F(2) = F(2)+kpboom*(q(2))+kdboom*dq(2);   % Side
            % F(5) = F(5)+kpboom*(q(5)-0)+kdboom*dq(5);   % Roll
        end
    end
end
