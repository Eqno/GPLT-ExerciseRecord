import functools
class Pers:
    def __init__(self, num):
        self.num = num
        self.red = 0
        self.val = 0
def mycmp(self, other):
    if self.val > other.val:
        return -1
    elif self.val < other.val:
        return 1
    elif self.red > other.red:
        return -1
    elif self.red < other.red:
        return 1
    elif self.num < other.num:
        return -1
    elif self.num > other.num:
        return 1
    else:
        return -1
geted = {}
n = int(input())
for pers in range(1, n+1):
    info = list(map(int, input().split(' ')[1:]))
    if pers not in geted:
        geted[pers] = Pers(pers)
    for i in range(0, len(info), 2):
        num = info[i]
        val = info[i+1]
        geted[pers].val -= val
        if num not in geted:
            geted[num] = Pers(num)
        geted[num].red += 1
        geted[num].val += val
geted = list(geted.values())
for i in geted:
    i.val /= 100
geted.sort(key=functools.cmp_to_key(mycmp))
for i in geted:
    print('%d %.2f' % (i.num, i.val))