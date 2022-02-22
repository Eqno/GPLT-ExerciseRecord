#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

const int MAXM = 1500, MAXN = 150, MAXL = 65;
int m, n, l, t, ans = 0;
int mat[MAXM][MAXN][MAXL];
bool vis[MAXM][MAXN][MAXL];

int dfs(int i, int j, int k)
{
    if (i<0 || i>=m || j<0
        || j>=n || k<0 || k>=l)
        return 0;
    if (vis[i][j][k] || !mat[i][j][k])
        return 0;
    vis[i][j][k] = true;
    int res = mat[i][j][k];
    res += dfs(i-1, j, k);
    res += dfs(i+1, j, k);
    res += dfs(i, j-1, k);
    res += dfs(i, j+1, k);
    res += dfs(i, j, k-1);
    res += dfs(i, j, k+1);
    return res;
}

struct Coord { int i, j, k; };
inline void judgeAndPush(queue<Coord *> &q, int i, int j, int k)
{
    if (i<0 || i>=m || j<0
        || j>=n || k<0 || k>=l
        || vis[i][j][k] || !mat[i][j][k])
        return;
    q.push(new Coord({i, j, k}));
    vis[i][j][k] = true;
}
int bfs(int i, int j, int k)
{
    if (vis[i][j][k] || !mat[i][j][k]) return 0;
    int res = 0;
    queue<Coord *> q;
    vis[i][j][k] = true;
    q.push(new Coord({i, j, k}));
    while (q.size())
    {
        Coord *c = q.front();
        q.pop();
        res += mat[c->i][c->j][c->k];
        judgeAndPush(q, c->i-1, c->j, c->k);
        judgeAndPush(q, c->i+1, c->j, c->k);
        judgeAndPush(q, c->i, c->j-1, c->k);
        judgeAndPush(q, c->i, c->j+1, c->k);
        judgeAndPush(q, c->i, c->j, c->k-1);
        judgeAndPush(q, c->i, c->j, c->k+1);
        delete c;
    }
    return res;
} 

int main()
{
    cin >> m >> n >> l >> t;
    for (int k=0; k<l; k++)
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                cin >> mat[i][j][k];
    for (int k=0; k<l; k++)
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int siz = bfs(i, j, k);
                if (siz >= t) ans += siz;
            }
    cout << ans << endl;
    return 0;
}