function [J1, J2] = posJacobians(x)
	q1 = x(1);
	q2 = x(2);
	dq1 = x(3);
	dq2 = x(4);
	
	m1 = 1;
	m2 = 1;
	l1 = 1;
	l2 = 1;
	
	J1 = [ -l1*sin(q1), 0;
		l1*cos(q1), 0];
	J2 = [ -l1*sin(q1), -l2*sin(q2);
		l1*cos(q1), l2*cos(q2)];
end
