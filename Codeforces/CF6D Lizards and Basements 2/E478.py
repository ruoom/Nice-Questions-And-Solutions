def getints(): return map(int, raw_input().split())

def search(dep, now, u, v): # u = a[dep - 1], v = a[dep]
	global ans, f
	if dep == n - 1:
		ans, f = now, g[:]
		return
	g[dep] = u / q + 1 if u >= 0 else 0
	v -= p * g[dep]
	w = a[dep + 1] - q * g[dep]
	now += g[dep]
	while now < ans:
		search(dep + 1, now, v, w)
		v -= p
		w -= q
		g[dep] += 1
		now += 1

n, p, q = getints()
a = getints()
t = a[-1] / q + 1
a[-2] -= p * t
a[-3] -= q * t

ans, g = 999, [0] * n
search(1, 0, a[0], a[1])

f[-2] += t
print ans + t
for i in xrange(n):
	for j in xrange(f[i]): print i + 1,
