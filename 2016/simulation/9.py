s = []
n = int(input())
for _ in range(n):
    s.append(set(input().split(' ')[1:]))
k = int(input())
for _ in range(k):
    a, b = map(int, input().split(' '))
    nc = len(s[a-1] & s[b-1])
    nt = len(s[a-1] | s[b-1])
    print('%.2f%%' % (nc/nt*100))
