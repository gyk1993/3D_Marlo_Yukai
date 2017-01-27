function [G] = G_func(x)
	q1 = x(1);
	q2 = x(2);
	dq1 = x(3);
	dq2 = x(4);
	
	m1 = 1;
	m2 = 1;
	l1 = 1;
	l2 = 1;
	g = 9.81;
	
	G = [m1*l1*g*cos(q1) + m2*g*(l2*cos(q1+q2) + l1*cos(q1));
		m2*l2*g*cos(q1+q2)];
end
