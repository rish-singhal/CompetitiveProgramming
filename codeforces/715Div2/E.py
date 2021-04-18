for _ in range(int(input())):
	
	n, k = map(int, input().split())
	f = bin(k-1)[2:] 
	if k - 1:
		f += "0"
	if len(f) > n:
		print("-1")
		continue

	f = "0"*(n - len(f)) + f
	ans = []
	arr = []
	for i in range(n):
		arr += [i+1]
		if f[i] == "0":
			ans += arr[::-1]
			arr = []

	print(*ans)
