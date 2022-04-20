def dev(a, b):
    return int(a / b)
def mod(a, b):
    return a - dev(a, b) * b
def gcd(a, b):
    return a if b==0 else gcd(b, mod(a, b))
def lcm(a, b):
    return dev(a, gcd(a, b)) * b

fenzi = 0
fenmu = 1
n = int(input())
for i in input().split(' '):
    newzi, newmu = map(int, i.split('/'))
    l = lcm(fenmu, newmu)
    fenzi = fenzi*dev(l, fenmu) + newzi*dev(l, newmu)
    fenmu = l
    g = gcd(fenzi, fenmu)
    fenzi = dev(fenzi, g)
    fenmu = dev(fenmu, g)
zhengshu = dev(fenzi, fenmu)
fenshu = mod(fenzi, fenmu)
flag = False
if zhengshu != 0:
    print(zhengshu, end='')
    flag = True
if fenshu != 0:
    if flag:
        print(' ', end='')
    print(fenshu, fenmu, sep='/')
elif not flag:
    print(0)
