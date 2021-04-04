t = int(input())

for _ in range(t):
	n = int(input())
	a = [[],[]]
	for i in range(2*n):
		l, r = map(int, input().split())
		if l: a[0].append(abs(l))
		else: a[1].append(abs(r))
	
	print(sum((a*a + b*b)**0.5 for a,b in zip(*map(sorted, a))))