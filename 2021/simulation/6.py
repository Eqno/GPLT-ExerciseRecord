import functools

n, m = map(int, input().split(' '))
dic = {}
for _ in range(n):
    out = input()
    dic[out] = dic.get(out, 0) + 1
class Item:
    def __init__(self, num, out):
        self.num = num
        self.out = out
ans = []
for k, v in dic.items():
    ans.append(Item(v, k))
def mycmp(a, b):
    if a.num != b.num:
        return -1 if a.num>b.num else 1
    else:
        l1, l2 = a.out.split(' '), b.out.split(' ')
        for i in range(len(l1)):
            if l1[i] >= l2[i]:
                return 1
        return -1
ans.sort(key=functools.cmp_to_key(mycmp))
print(len(ans))
for i in ans:
    print(i.num, i.out)
