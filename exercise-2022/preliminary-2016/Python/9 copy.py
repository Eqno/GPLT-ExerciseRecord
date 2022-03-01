import functools
from webbrowser import get
class Pers:
    def __init__(self, num, red=0, val=0):
        self.num, self.red, self.val = num, red, val
def mycmp(a, b):
    cmp = lambda i, j: -1 if i > j else 1
    return cmp(a.val, b.val) if a.val != b.val else cmp(a.red, b.red) if a.red != b.red else -cmp(a.num, b.num)
geted, n = {}, int(input())
for pers in range(1, n+1):
    info = list(map(int, input().split(' ')[1:]))
    geted[pers] = geted.get(pers, Pers(pers))
    for i in range(0, len(info), 2):
        num, val = info[i], info[i+1]
        geted[pers].val -= val
        geted[num] = geted.get(num, Pers(num))
        geted[num].red += 1
        geted[num].val += val
geted = sorted([Pers(i.num, i.red, i.val/100) for i in geted.values()], key=functools.cmp_to_key(mycmp))
for i in geted: print('%d %.2f' % (i.num, i.val))
