from imaplib import Int2AP


n = int(input())
l = list(map(int, input().split(' ')))
odd = 0
eve = 0
for i in l:
    if i % 2 == 1:
        odd += 1
    if i % 2 == 0:
        eve += 1
print(odd, eve)