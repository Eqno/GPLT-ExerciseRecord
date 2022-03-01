S = input().split(' ')
try:
    a = int(S[0])
    if a<1 or a>1000:
        a = '?'
except ValueError:
    a = '?'
if len(S) > 2:
    b = '?'
else:
    try:
        b = int(S[1])
        if b<1 or b>1000:
            b = '?'
    except ValueError:
        b = '?'
print(a, '+', b, '=', a+b if type(a)==int and type(b)==int else '?')
