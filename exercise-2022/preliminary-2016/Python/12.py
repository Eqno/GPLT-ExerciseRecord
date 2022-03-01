INF = int(0x3f3f3f3f)
class Info:
    def __init__(self):
        self.len = 0
        self.tim = 0
mat = {}
dis = {}
tim = {}
num = {}
vis = set()
n, m = int(input().split(' '))
def dijkstra1(s):
    for k, v in mat[s].items():
        dis[k] = v.len
        tim[k] = v.tim
    vis.add(s)
    for i in 

for _ in range(m):
    a, b, o, l, t = map(int, input().split(' '))
    if a not in mat:
        mat[a] = {}
        if b not in mat[a]:
            mat[a][b] = Info()
        mat[a][b].len = l
        mat[a][b].tim = t
    if o == 1:
        if b not in mat:
            mat[b] = {}
            if a not in mat[b]:
                mat[b][a] = Info()
            mat[b][a].len = l
            mat[b][a].tim = t
s, e = map(int, input().split(' '))
dijkstra1(s)