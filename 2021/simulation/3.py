n, m, s = map(int, input().split(' '))
goods = []
for _ in range(n):
    goods.append([i for i in input()])
opt = list(map(int, input().split(' ')))
stk, ans = [], []
for i in opt:
    if i == -1:
        break
    if i==0 and len(stk):
        ans.append(stk.pop())
    else:
        if len(goods[i-1]):
            if len(stk) >= s:
                ans.append(stk.pop())
            stk.append(goods[i-1][0])
            goods[i-1] = goods[i-1][1:]
print(*ans, sep='')