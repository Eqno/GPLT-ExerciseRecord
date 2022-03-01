#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double min(double a, double b)
{ return a<b ? a : b; }

int read(int n)
{
    string s;
    cin >> s;
    int res = 0;
    if (s[0] == 'G')
    {
        res = n;
        s.erase(s.begin());
    }
    int ans = 0;
    for (auto i: s)
        ans = ans*10 + i-'0';
    return ans + res;
}

#define INF 0x7f7f7f7f7f7f7f7f
#define int long long
const int MAXN = 1e3+30;
int mat[MAXN][MAXN], dis[MAXN][MAXN], vis[MAXN];

void dijkstra(int s, int n)
{
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    for (int i=1; i<=n; i++)
        dis[s][i] = mat[s][i];
    for (int i=1; i<=n; i++)
    {
        int p = 0;
        for (int j=1; j<=n; j++)
            if (!vis[j] && dis[s][j]<=dis[s][p])
                p = j;
        if (p == 0) return ;
        vis[p] = 1;
        for (int j=1; j<=n; j++)
            if (!vis[j] && dis[s][p]+mat[p][j] < dis[s][j])
                dis[s][j] = dis[s][p] + mat[p][j];
    }
}

struct Can { int num, mindis; long double avgdis; };
vector<Can> can;

bool cmp(const Can &i, const Can &j)
{
    if (i.mindis != j.mindis)
        return i.mindis > j.mindis;
    else if (i.avgdis != j.avgdis)
        return i.avgdis < j.avgdis;
    return i.num < j.num;
}

void solve()
{
    memset(mat, 0x7f, sizeof mat);
    memset(dis, 0x7f, sizeof dis);
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    for (int i=1; i<=n+m; i++)
        mat[i][i] = 0;
    for (int i=0; i<k; i++)
    {
        int u, v, z;
        u = read(n);
        v = read(n);
        cin >> z;
        mat[u][v] = mat[v][u] = z;
    }
    for (int i=n+1; i<=n+m; i++)
        dijkstra(i, n+m);
    for (int i=n+1; i<=n+m; i++)
    {
        int mindis = INF, sumdis = 0;
        bool f = 1;
        for (int j=1; j<=n; j++)
        {
            mindis = min(mindis, dis[i][j]);
            sumdis += dis[i][j];
            if (dis[i][j] > d) f = 0;
        }
        long double avgdis = (long double) sumdis/n;
        if (f) can.push_back({i, mindis, avgdis});
    }
    if (! can.size())
    {
        cout << "No Solution" << endl;
        return ;
    }
    sort(can.begin(), can.end(), cmp);
    cout << 'G' << can[0].num-n << endl;
    printf("%.1Lf %.1Lf\n", (long double) can[0].mindis, round(can[0].avgdis*10)/10);
}


signed main()
{
    solve();
    return 0;
}