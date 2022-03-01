a = 0
r = 1
n = int(input())
for i in range(1, n+1):
    r *= i
    a += r
print(a)