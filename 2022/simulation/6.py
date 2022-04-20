n = int(input())
for _ in range(n):
    s = input()
    l = len(s)
    for i in range(l):
        f = 1
        if str.isupper(s[i]):
            if i < l-1:
                if s[i+1]!=str.lower(s[i]) \
                    and s[i+1]!=str.upper(chr(ord(s[i])+1)):
                    print('N')
                    f = 0
                    break
        else:
            if i < l-1:
                if s[i+1]!=str.upper(s[i]) \
                    and s[i+1]!=str.lower(chr(ord(s[i])-1)):
                    print('N')
                    f = 0
                    break
    if f:
        print('Y')