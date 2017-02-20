% q_new = [pitch; roll; yaw;
%          qHR; qAR; qBR; qAgrR; qBgrR; FourBarAR; FourBarBR;
%          qHL; qAL; qBL; qAgrL; qBgrL; FourBarAL; FourBarBL];
% q_opt=[x;y;z;pitch;roll;yaw;qHR;qAR;qBR;FourBarAR;FourBarBR;qHL;qAL;qBL;;FourBarAL;FourBarBL];
syms pitch roll yaw qHR qAR qBR qAgrR qBgrR FourBarAR FourBarBR qHL qAL qBL qAgrL qBgrL FourBarAL FourBarBL
syms x y z
q_new = [pitch; roll; yaw;
          qHR; qAR; qBR; qAgrR; qBgrR; FourBarAR; FourBarBR;
          qHL; qAL; qBL; qAgrL; qBgrL; FourBarAL; FourBarBL];
q_opt=[x;y;z;pitch;roll;yaw;qHR;qAR;qBR;FourBarAR;FourBarBR;qHL;qAL;qBL;;FourBarAL;FourBarBL];

c2o_transform=jacobian(q_opt,q_new);
c2o_transform=double(c2o_transform);