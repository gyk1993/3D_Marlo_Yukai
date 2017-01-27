function [C] = C_func(x)
	q1 = x(1);
	q2 = x(2);
	dq1 = x(3);
	dq2 = x(4);
	
	m1 = 1;
	m2 = 1;
	l1 = 1;
	l2 = 1;
	
	h = m2*l1*l2*sin(q2);
	C = [-h*dq2, -h*dq1-h*dq2;
		h*dq1, 0];
end
