from re import L


n = int(input())
m = []
f = []
s = []
for _ in range(n):
    gend, name = input().split(' ')
    if gend == '1':
        m.append(name)
    else:
        f.append(name)
    s.append([gend, name])
for i in s:
    if i[1] in m:
        print(i[1], end=' ')
        m.remove(i[1])
    elif i[1] in f:
        print(i[1], end=' ')
        f.remove(i[1])
    else:
        continue
    if i[0] == '1':
        print(f[len(f)-1])
        f.remove(f[len(f)-1])
    else:
        print(m[len(m)-1])
        m.remove(m[len(m)-1])
    if len(m) == 0 or len(f) == 0:
        break