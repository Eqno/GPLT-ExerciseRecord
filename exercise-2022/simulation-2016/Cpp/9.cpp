#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> st[51];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {   
        int m;
        scanf("%d", &m);
        for (int j=1; j<=m; j++)
        {
            int num;
            scanf("%d", &num);
            st[i].emplace(num);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i=1; i<=k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        double nc = 0, nt = 0;
        auto sa = st[a], sb = st[b];
        for (auto j: sa)
            if (sb.find(j) != sb.end())
                nc ++;
        for (auto j: sa)
            sb.emplace(j);
        nt = sb.size();
        printf("%.2f%%\n", nc/nt*100);
    }
    return 0;
}