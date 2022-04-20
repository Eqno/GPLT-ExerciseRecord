s = input()
l = len(s)
if s[0] == '-':
    l -= 1
n = s.count('2') / l
if s[0] == '-':
    n *= 1.5
if int(s) % 2 == 0:
    n *= 2
print("%.2f%%" % (n*100))