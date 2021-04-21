from math import gcd
n = int(input()); ans = [];prod = 1
for i in range(1, n):
    if gcd(i, n) == 1: ans.append(i); prod = (prod*i)%n
if prod != 1: ans.remove(prod)
print(len(ans)); print(*ans)
