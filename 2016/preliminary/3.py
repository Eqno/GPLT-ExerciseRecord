a, b = map(int, input().split(' '))
n = int(input())
f = 0
g = 0
ended = 0
for _ in range(n):
    u, x, v, y = map(int, input().split(' '))
    # print(u, x, v, y, a, b, f, g)
    if ended!=0 or (x==u+v and y==u+v) or (x!=u+v and y!=u+v):
        continue
    # if ended != 0:
    #     continue
    if x == u+v:
        f += 1
    if y == u+v:
        g += 1
    if f > a:
        ended = 1
    if g > b:
        ended = 2
if ended == 1:
    print('A', g, sep='\n')
if ended == 2:
    print('B', f, sep='\n')