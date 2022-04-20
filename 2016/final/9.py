f = {}
def getf(x):
    f[x] = f.get(x, x)
    if x != f[x]:
        f[x] = getf(f[x])
    return f[x]
def merge(x, y):
    x = getf(x)
    y = getf(y)
    f[x] = y

e, ans = {}, []
n, m = map(int, input().split(' '))
for _ in range(m):
    u, v = input().split(' ')
    e[u] = e.get(u, set()); e[u].add(v)
    e[v] = e.get(v, set()); e[v].add(u)
k, s = int(input()), list(reversed(input().split(' ')))
for i in range(n):
    i = str(i)
    if i not in s:
        for j in e.get(i, set()):
            if j not in s:
                merge(i, j)
for ind, i in enumerate(s):
    t = set()
    for j in e.get(i, set()):
        if j not in s[ind:]:
            t.add(getf(j))
            merge(i, j)
    if len(t) > 1:
        ans.append('Red Alert: City %s is lost!' % i)
    else:
        ans.append('City %s is lost.' % i)
print(*reversed(ans), sep='\n')
if k >= n:
    print('Game Over.')