n, m = map(int, input().split(' '))
f = 0
for _ in range(n):
    title = input()
    if f or title.find('qiandao')!=-1 or title.find('easy')!=-1:
        continue
    if m <= 0:
        print(title)
        f = 1
    m -= 1
if not f:
    print('Wo AK le')

'''
5 0
L1-1 is a qiandao problem.
L1-2 is so...easy.
L1-3 is easy.
L1-4 is qiandao.
Wow, such L1-5, so easy.
'''