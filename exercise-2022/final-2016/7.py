n = int(input())
for _ in range(n):
    h, w = map(int, input().split(' '))
    s = (h - 100) * 1.8
    if abs(w-s) < 0.1*s:
        print('You are wan mei!')
    elif w > s:
        print('You are tai pang le!')
    else:
        print('You are tai shou le!')
