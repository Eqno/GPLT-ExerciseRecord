def fun(num):
    sum = 0
    while num:
        sum += num % 10
        num //= 10
    return sum

n = int(input())
for _ in range(n):
    m = int(input())
    s = fun(2 * m)
    f = 0
    for i in range(3, 10):
        if s != fun(i * m):
            print('NO')
            f = 1
            break
    if f == 0:
        print(s)