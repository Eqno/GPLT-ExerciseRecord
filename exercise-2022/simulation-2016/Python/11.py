import functools
MAXNUM = 11111
class Pers:
    def __init__(self, num, hou=0, siz=0):
        self.num = num
        self.hou = hou
        self.siz = siz
        self.rel = []
class Home:
    def __init__(self):
        self.minn = MAXNUM
        self.pnum = 0
        self.avgh = 0
        self.avgs = 0
ind = {}
vis = set()
homes = []
def merge(num, hou, siz, *rel):
    if num not in ind:
        ind[num] = Pers(num, hou, siz)
    else:
        ind[num].hou = hou
        ind[num].siz = siz
    for i in rel:
        if i == -1:
            continue
        if i not in ind:
            ind[i] = Pers(num=i)
        ind[num].rel.append(i)
        ind[i].rel.append(num)
def dfs(num, home):
    if num in vis:
        return
    vis.add(num)
    home.pnum += 1
    home.avgh += ind[num].hou
    home.avgs += ind[num].siz
    home.minn = min(home.minn, num)
    for i in ind[num].rel:
        dfs(i, home)
def mycmp(self, other):
    if self.avgs > other.avgs:
        return -1
    elif self.minn < other.minn:
        return -1
    else:
        return 1
n = int(input())
for _ in range(n):
    l = list(map(int, input().split(' ')))
    merge(l[0], l[-2], l[-1], l[1], l[2], *l[4:-2])
for i in ind.keys():
    if i not in vis:
        home = Home()
        dfs(i, home)
        homes.append(home)
for i in homes:
    i.avgh /= i.pnum
    i.avgs /= i.pnum
homes.sort(key=functools.cmp_to_key(mycmp))
print(len(homes))
for i in homes:
    print("%04d %d %.3f %.3f" %
        (i.minn, i.pnum, i.avgh, i.avgs))