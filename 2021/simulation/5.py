emo = list(map(int, input().split(' ')))
while 1:
    opt = int(input())
    if opt<0 or opt>23:
        break
    print(emo[opt], 'Yes' if emo[opt]>50 else 'No')