I = input

for _ in range(int(I())):
	n, k = map(int, I().split())
	v =  [int(i) for i in I().split()]
	v.sort()
	ma = v[-1]
	me = -1
	for i in range(len(v)):
		if i != v[i]:
			me = i
			break

	di = len(set(v))

	if me == -1:
		print(di + k)
		continue

	if k == 0:
		print(di)
		continue

	if v.count(((me + ma + 1)//2)):
		print(di)
	else:
		print(di + 1)
