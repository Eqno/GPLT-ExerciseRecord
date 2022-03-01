#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> post, mid;
unordered_map<int, int> ind;
struct Node { int val; Node *left, *right; };

Node *build(int l, int r, int rid)
{
    if (l > r) return nullptr;
    Node *node = new Node();
    node->val = post[rid];
    int index = ind[node->val];
    node->left = build(l, index-1, rid-(r-index+1));
    node->right = build(index+1, r, rid-1);
    return node;
}

void travel(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    if (root) q.push(root);
    while (q.size())
    {
        Node *node = q.front();
        q.pop();
        ans.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    if (ans.size()) printf("%d", ans[0]);
    for (int i=1; i<ans.size(); i++)
        printf(" %d", ans[i]);
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        post.push_back(num);
    }
    for (int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        mid.push_back(num);
    }
    for (int i=0; i<n; i++)
        ind[mid[i]] = i;
    travel(build(0, n-1, n-1));
    return 0;
}