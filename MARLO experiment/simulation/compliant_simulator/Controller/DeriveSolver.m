a = sym('a', [1, 6], 'real');
da = sym('da', 'real');
s = sym('s', 'real');
y = sym('y', 'real');

poly = bezier(a + [da, zeros(1,5)], s);
poly = simplify(poly);

sol = solve(poly == y, da);
sol = simplify(sol)