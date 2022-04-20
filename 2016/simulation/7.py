n, c = input().split(' ')
n = int(n)
for i in range((n+1)//2):
    for j in range(n):
        print(c, end='')
    print()
