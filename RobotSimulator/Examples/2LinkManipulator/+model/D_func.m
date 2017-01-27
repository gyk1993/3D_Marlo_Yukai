function [D] = D_func(x)
	q1 = x(1);
	q2 = x(2);
	dq1 = x(3);
	dq2 = x(4);
	
	m1 = 1;
	m2 = 1;
	l1 = 1;
	l2 = 1;
	
	D = [m1*l1*l1 + m2*(l1*l1 + l2*l2 + 2*l1*l2*cos(q2)), m2*l1*l2*cos(q2) + m2*l2*l2;
		m2*l1*l2*cos(q2) + m2*l2*l2, m2*l2*l2];
end
