class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
def build(l, r, t):
    if l > r:
        return None
    node = Node(pre[t])
    index = ind[node.val]
    node.left = build(l, index-1, t+1)
    node.right = build(index+1, r, t+(index-l+1))
    return node
def travel(root):
    if root == None:
        return
    ans = []
    q = [root]
    while len(q):
        node = q.pop(0)
        ans.append(node.val)
        if node.right != None:
            q.append(node.right)
        if node.left != None:
            q.append(node.left)
    print(*ans)
n = int(input())
mid = input().split(' ')
pre = input().split(' ')
ind = {}
for i, j in enumerate(mid):
    ind[j] = i
travel(build(0, n-1, 0))