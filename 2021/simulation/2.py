n = int(input())
lst = list(map(int, input().split(' ')))
print(min(lst), lst.count(min(lst)))
print(max(lst), lst.count(max(lst)))