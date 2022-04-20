n = int(input())
for _ in range(n):
    g, h, w = map(int, input().split(' '))
    if g == 1:
        if h < 130:
            print('duo chi yu!', end=' ')
        elif h == 130:
            print('wan mei!', end=' ')
        else:
            print('ni li hai!', end=' ')
        if w < 27:
            print('duo chi rou!')
        elif w == 27:
            print('wan mei!')
        else:
            print('shao chi rou!')
    else:
        if h < 129:
            print('duo chi yu!', end=' ')
        elif h == 129:
            print('wan mei!', end=' ')
        else:
            print('ni li hai!', end=' ')
        if w < 25:
            print('duo chi rou!')
        elif w == 25:
            print('wan mei!')
        else:
            print('shao chi rou!')
