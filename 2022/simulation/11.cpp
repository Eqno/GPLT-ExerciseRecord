#include <cstddef>
#include <errno.h>
#include <queue>
#include <iostream>
#include <type_traits>
#include <unordered_map>
using namespace std;

const int MAXN = 50;
int inorder[MAXN], postorder[MAXN];
unordered_map<int, int> m;

struct Node
{
    int num, depth;
    Node* left, * right;
};

Node* build(int t, int d, int l, int r)
{
    if (l > r) return nullptr;
    int i = m[postorder[t]];
    Node* root = new Node({postorder[t], d});
    root->left = build(t-(r-i)-1, d+1, l, i-1);
    root->right = build(t-1, d+1, i+1, r);
    return root;
}

vector<int> ansl, ansr;

void travel(Node* root)
{
    if (root == nullptr) return;
    int lastd = 1;
    Node* lastn = root;
    ansl.emplace_back(root->num);
    queue<Node*> q({root});
    while (q.size())
    {
        Node* t = q.front(); q.pop();
        if (t->depth > lastd)
        {
            ansl.emplace_back(t->num);
            lastd = t->depth;
            ansr.emplace_back(lastn->num);
        }
        lastn = t;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    ansr.emplace_back(lastn->num);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &inorder[i]);
        m[inorder[i]] = i;
    }
    for (int i=0; i<n; i++)
        scanf("%d", &postorder[i]);
    travel(build(n-1, 1, 0, n-1));
    cout << "R:";
    for (auto i: ansr) cout << " " << i;
    cout << endl << "L:";
    for (auto i: ansl) cout << " " << i;
    return 0;
}