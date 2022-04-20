s = input()
ng = s.count('G') + s.count('g')
np = s.count('P') + s.count('p')
nl = s.count('L') + s.count('l')
nt = s.count('T') + s.count('t')
while ng or np or nl or nt:
    if ng:
        print('G', end='')
        ng -= 1
    if np:
        print('P', end='')
        np -= 1
    if nl:
        print('L', end='')
        nl -= 1
    if nt:
        print('T', end='')
        nt -= 1