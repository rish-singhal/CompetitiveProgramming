h, *g = open(0)
h, w, x, y = map(int,h.split())

x -= 1
y -= 1

ans = 0

for i in range(x+1,h):
	if g[i][y] == '#':
		break
	ans += 1

for i in range(x-1,-1,-1):
	if g[i][y] == '#':
		break
	ans += 1

for i in range(y-1,-1,-1):
	if g[x][i] == '#':
		break
	ans += 1

for i in range(y+1,w):
	if g[x][i] == '#':
		break
	ans += 1

print(ans + (g[x][y]!='#'))