R = lambda:map(int, input().split())
t, = R()
for _ in range(t):
    n, k, = R()
    v = [*R()]
    su = sum(i for i in v)
    su1 = sum(i for i in v[:k])
    mi = su1
    for i in range(k, n):
    	su1 -= v[i - (k)] - v[i]
    	mi = min(mi, su1)

    print((mi*(mi+1)//2)+su-mi)