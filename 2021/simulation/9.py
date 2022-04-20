s = input()
if len(s) == 4:
    n = int(s[:2])
    m = s[2:]
    if n < 22:
        print('20'+('%02d'%n)+'-'+m)
    else:
        print('19'+('%02d'%n)+'-'+m)
else:
    n = s[:4]
    m = s[4:]
    print(n+'-'+m)