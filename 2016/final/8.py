n, c = input().split(' ')
n = int(n)
s = input()
if n >= len(s):
    print(str(c*(n-len(s)))+s)
else:
    print(s[-n:-1]+s[-1])