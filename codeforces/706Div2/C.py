t = int(input())

for _ in range(t):
	n = int(input())
	le = []
	ri = []
	for i in range(2*n):
		l, r = map(int, input().split())
		if l: le.append(abs(l))
		else: ri.append(abs(r))

	le.sort()
	ri.sort()
	
	print(sum((a*a + b*b)**0.5 for a,b in zip(le,ri))) 
