f = {}
e = {}
def getf(x):
    if x not in f or x==f[x]:
        if x not in f:
            f[x] = x
        return x
    f[x] = getf(f[x])
    return f[x]
def merge(x, y):
    x = getf(x)
    y = getf(y)
    f[x] = y
n, m, k = map(int, input().split(' '))
for _ in range(m):
    a, b, r = input().split(' ')
    if r == '1':
        merge(a, b)
    if r == '-1':
        if a not in e:
            e[a] = set()
        e[a].add(b)
        if b not in e:
            e[b] = set()
        e[b].add(a)
for _ in range(k):
    a, b = input().split(' ')
    friend = getf(a)==getf(b)
    enemy = (a in e and b in e[a]) or (b in e and a in e[b])
    if friend and not enemy:
        print('No problem')
    if not friend and not enemy:
        print('OK')
    if friend and enemy:
        print('OK but...')
    if not friend and enemy:
        print('No way')