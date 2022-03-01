rel = {}
vis = set()
zon = []
def dfs(n, l):
    if n in vis:
        return
    # print(n)
    vis.add(n)
    l.append(n)
    for i in rel[n]:
        dfs(i, l)
n = int(input())
for _ in range(n):
    p = input().split(' ')[1:]
    r = p[0]
    p = p[1:]
    if r not in rel:
        rel[r] = []
    for i in p:
        if i not in rel:
            rel[i] = []
        rel[r].append(i)
        rel[i].append(r)
for i in rel.keys():
    if i not in vis:
        l = []
        dfs(i, l)
        zon.append(l)
# print(rel)
m = int(input())
q = input().split(' ')
ans = []
added = set()
for i in q:
    if i not in rel or len(rel[i])==0:
        if i not in added:
            added.add(i)
            ans.append(i)
if len(ans):
    print(*ans)
else:
    print('No one is handsome')