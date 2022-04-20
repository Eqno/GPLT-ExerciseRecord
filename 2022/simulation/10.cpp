#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node
{
    string name;
    int type;
    double avg;
};
vector<Node> node;

bool cmp(const Node &a, const Node &b)
{ 
    if (a.type != b.type)
        return a.type > b.type;
    return a.avg < b.avg;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        string name;
        cin >> name;
        unordered_map<int, int> s;
        double v = 0;
        int k;
        scanf("%d", &k);
        for (int j=0; j<k; j++)
        {
            int t;
            scanf("%d", &t);
            s[t] ++;
        }
        for (auto j: s) v += j.second;
        node.emplace_back(Node({name, int(s.size()), v/s.size()}));
    }
    sort(node.begin(), node.end(), cmp);
    if (node.size()) cout << node[0].name;
    else { cout << "- - -"; return 0; }
    for (int i=1; i<min(3, int(node.size())); i++)
        cout << " " << node[i].name;
    int cot = 3;
    while (cot > node.size())
        cout << " -", cot --;
    return 0;
}