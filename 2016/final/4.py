import math

n = int(input())
for _ in range(n):
    a = int(input())
    if a == 2:
        print('Yes')
        continue
    if a==1 or a==0:
        print('No')
        continue
    f = False
    for i in range(2, math.floor(math.sqrt(a))+1):
        if a % i == 0:
            print('No')
            f = True
            break
    if not f:
        print('Yes')