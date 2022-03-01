h, m = map(int, input().split(':'))
if (h>0 and h<12) or ((h==0 or h==12) and m==0):
    print('Only %02d:%02d.  Too early to Dang.' % (h, m))
else:
    n = h + (1 if m!=0 else 0) - 12
    for _ in range(n):
        print('Dang', end='')