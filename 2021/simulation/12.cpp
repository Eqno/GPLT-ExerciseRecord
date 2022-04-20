#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 1e3;
int v[MAXN];
unordered_map<int, unordered_map<int, int>> s;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j=1; j<=k; j++)
        {
            int t;
            scanf("%d", &t);
            s[i][j] = t;
        }
    }
    int p = 1;
    for (int i=1; i<=m; i++)
    {
        int o;
        scanf("%d", &o);
        if (o == 0)
        {
            int t;
            scanf("%d", &t);
            p = s[p][t];
        }
        if (o == 1)
        {
            int t;
            scanf("%d", &t);
            v[t] = p;
            printf("%d\n", p);
        }
        if (o == 2)
        {
            int t;
            scanf("%d", &t);
            p = v[t];
        }
    }
    printf("%d\n", p);
    return 0;
}