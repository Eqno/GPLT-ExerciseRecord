p = input()
s = set()
for i in p:
    s.add(int(i))
arr = sorted(list(s), reverse=True)
index = []
for i in p:
    index.append(arr.index(int(i)))
print('int[] arr = new int[]{', end='')
print(*arr, sep=',', end='')
print('};')
print('int[] index = new int[]{', end='')
print(*index, sep=',', end='')
print('};')
