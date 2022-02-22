#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

const int MAXNUM = 11111;

struct Node
{
    int num, house, size;
    vector<Node *> rel;
};
unordered_map<int, Node *> ind;

struct Home
{
    int minnum, totper;
    double avghou, avgsiz;
};
vector<Home> homes;

void merge(Node *x, int ynum)
{
    Node *y = ind[ynum];
    if (! y)
    {
        y = new Node({ynum, 0});
        ind[ynum] = y;
    }

    x->rel.push_back(y);
    y->rel.push_back(x);
}

unordered_map<int, bool> vis;

void dfs(int num, Home *home)
{
    if (vis[num]) return ;
    vis[num] = true;

    Node *node = ind[num];
    home->totper ++;
    home->avgsiz += node->size;
    home->avghou += node->house;
    home->minnum = min(home->minnum, num);

    for (auto i: node->rel)
        dfs(i->num, home);
}

bool cmp(const Home &i, const Home &j)
{
    if (i.avgsiz != j.avgsiz)
        return i.avgsiz > j.avgsiz;
    else return i.minnum < j.minnum;
}

void solve()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int num, father, mother, k;
        cin >> num >> father >> mother >> k;
        
        Node *node = ind[num];
        if (! node)
        {
            node = new Node({num});
            ind[num] = node;
        }

        if (father != -1) merge(node, father);
        if (mother != -1) merge(node, mother);
        
        for (int j=0; j<k; j++)
        {
            int kid;
            cin >> kid;
            merge(node, kid);
        }
        int house, size;
        cin >> house >> size;

        node->house = house;
        node->size = size;
    }

    for (auto i: ind)
        if (! vis[i.first])
        {
            Home home = {MAXNUM};
            dfs(i.first, &home);
            home.avghou /= home.totper;
            home.avgsiz /= home.totper;
           
            homes.push_back(home);
        }
    cout << homes.size() << endl;
    sort(homes.begin(), homes.end(), cmp);
    for (auto i: homes)
    {
        printf("%04d %d %.3f %.3f\n",
            i.minnum, i.totper, i.avghou, i.avgsiz);
    }  
}

int main()
{
    solve();
    return 0;
}