a1, a2, n = map(int, input().split(' '))
ans = [a1, a2]
i1, i2 = 0, 1
for _ in range(n):
    res = ans[i1] * ans[i2]
    lst = []
    if res == 0:
        lst.append(0)
    while res:
        lst.append(res % 10)
        res //= 10
    lst.reverse()
    ans += lst
    i1 += 1
    i2 += 1
    if len(ans) > n:
        break
print(*ans[:n])
