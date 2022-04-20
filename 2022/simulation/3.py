p, t, d = map(float, input().split(' '))
l = p * 2.455
if t == 1:
    l = p * 1.26
print('%.2f' % l, end=' ')
if l >= d:
    print('T_T')
else:
    print('^_^')