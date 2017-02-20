syms qHR qAR qBR qHL qAL qBL real

u_q=[qHR qAR qBR qHL qAL qBL]';
output_right=[1/2*(qAR+qBR);1/2*(qAL+qBL);qBR-qAR;qBL-qAL;qHR;qHL];
output_left=[1/2*(qAL+qBL);1/2*(qAR+qBR);qBL-qAL;qBR-qAR;qHL;qHR];

M_right=jacobian(output_right,u_q);
M_left=jacobian(output_left,u_q);
M_right=double(M_right);
M_left=double(M_left);