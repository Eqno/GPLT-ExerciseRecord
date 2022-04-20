def dev(a, b):
    return int(a / b)
def mod(a, b):
    return a - dev(a, b) * b

quan = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
zhi = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']
n = int(input())
printed = False
for _ in range(n):
    he = 0
    flag = 0
    shenfen = input()
    for i, c in enumerate(shenfen[0:17]):
        if c.isdigit():
            he += int(c)*quan[i]
        else:
            flag = 1
            break
    if flag or zhi[mod(he, 11)] != shenfen[17]:
        print(shenfen)
        printed = True
if not printed:
    print('All passed')