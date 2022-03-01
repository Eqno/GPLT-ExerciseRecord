class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
def build(l, r, t):
    if l > r:
        return None
    node = Node(post[t])
    index = ind[node.val]
    node.left = build(l, index-1, t-(r-index+1))
    node.right = build(index+1, r, t-1)
    return node
def travel(root):
    if root == None:
        return
    ans = []
    q = [root]
    while len(q):
        node = q.pop(0)
        ans.append(node.val)
        if node.left != None:
            q.append(node.left)
        if node.right != None:
            q.append(node.right)
    print(*ans)
n = int(input())
post = input().split(' ')
mid = input().split(' ')
ind = {}
for i, j in enumerate(mid):
    ind[j] = i
travel(build(0, n-1, n-1))