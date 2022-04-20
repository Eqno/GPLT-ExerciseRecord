n, m = map(int, input().split(' '))
f = 0
for _ in range(n):
    title = input()
    if m <= 0 and f == 0:
        print(title)
        f = 1
    if title.find('qiandao')==-1 and title.find('easy')==-1:
        m -= 1
if f == 0:
    print('Wo AK le')