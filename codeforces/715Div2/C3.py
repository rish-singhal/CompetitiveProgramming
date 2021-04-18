v=sorted(map(int, [*open(0)][1].split()))
n=len(v); dp=[0]*n
for d in range(1, n):
	for i in range(0,n-d):
		dp[i] = min(dp[i:i+2]) + v[i+d] - v[i]

print(dp[0])