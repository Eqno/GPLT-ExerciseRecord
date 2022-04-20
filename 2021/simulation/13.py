n, m = map(int, input().split(' '))
for _ in range(n):
    p = float(input())
    if p < m:
        print('On Sale! %.1f' % p)