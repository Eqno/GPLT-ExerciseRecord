#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
int f[MAXN], d[MAXN], vised[MAXN];
vector<vector<int>> path;

int getd(int x)
{
    if (x == f[x]) return 1;
    return getd(f[x]) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        f[i] = i;
    for (int i=0; i<n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j=0; j<k; j++)
        {
            int s;
            scanf("%d", &s);
            f[s] = i;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++)
        d[i] = getd(i);
    for (int i=0; i<n; i++)
        ans = max(ans, d[i]);
    for (int i=0; i<n; i++)
    {
        if (d[i] == ans)
        {
            vector<int> t;
            int ind = i;
            while (ind != f[ind])
            {
                t.push_back(ind);
                ind = f[ind];
            }
            t.push_back(ind);
            reverse(t.begin(), t.end());
            path.push_back(t);
        }
    }
    int m = 0;
    for (int i=0; i<path[0].size(); i++)
    {
        bool flag = true;
        for (int j=0; j<path.size(); j++)
            if (! vised[j]) {
                // printf("%d %d %d %d %d\n", i, j, m, path[j][i], path[m][i]);
                if (path[j][i] < path[m][i])
                {
                    m = j;
                    flag = false;
                    break;
                }
                else if (path[j][i] > path[m][i])
                    vised[j] = true;
            }
        if (! flag) break;
    }
    printf("%d\n%d", ans, path[m][0]);
    for (int i=1; i<path[m].size(); i++)
        printf(" %d", path[m][i]);
    return 0;
}