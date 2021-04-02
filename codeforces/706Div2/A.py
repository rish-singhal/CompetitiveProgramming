t = int(input())

for _ in range(t):
	n, k = [int(i) for i in input().split()] 
	s = input()

	if k == 0:
		print("YES")
		continue

	if n % 2 == 0 and k == n/2:
		print("NO")
		continue
		
	if s[0:k] == s[n:n - k - 1:-1]:
		print("YES")
	else:
		print("NO")