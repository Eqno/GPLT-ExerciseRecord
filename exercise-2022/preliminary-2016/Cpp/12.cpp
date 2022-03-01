#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 600, INF = 0x3f3f3f3f;
vector<int> dis_ans, time_ans;
int dis_path[MAXN], time_path[MAXN];
int n, m, len[MAXN][MAXN], tim[MAXN][MAXN];
int vis[MAXN], dis[MAXN], spd[MAXN], num[MAXN];

void dijkstra1(int s)
{
    memset(spd, INF, sizeof spd);
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    for (int i=0; i<n; i++)
    {
        spd[i] = tim[s][i];
        dis[i] = len[s][i];
        if (tim[s][i] < INF)
            time_path[i] = s;
    }
    vis[s] = true;
    for (int i=0; i<n; i++)
    {
        int minn = INF, p = -1;
        for (int j=0; j<n; j++)
            if (!vis[j] && spd[j]<minn)
                minn = spd[p=j];
        vis[p] = true;
        for (int j=0; j<n; j++)
            if (! vis[j])
            {
                if (spd[p]+tim[p][j] < spd[j])
                {
                    spd[j] = spd[p] + tim[p][j];
                    dis[j] = dis[p] + len[p][j];
                    time_path[j] = p;
                }
                else if (spd[p]+tim[p][j]==spd[j]
                    && dis[p]+len[p][j] < dis[j])
                {
                    dis[j] = dis[p] + len[p][j];
                    time_path[j] = p;
                }
            }
    }
}

void dijkstra2(int s)
{
    memset(dis, INF, sizeof dis);
    memset(num, INF, sizeof num);
    memset(vis, 0, sizeof vis);
    for (int i=0; i<n; i++)
    {
        dis[i] = len[s][i];
        if (len[s][i] < INF)
        {
            num[i] = 1;
            dis_path[i] = s;
        }
    }
    vis[s] = true;
    for (int i=0; i<n; i++)
    {
        int minn = INF, p = -1;
        for (int j=0; j<n; j++)
            if (!vis[j] && dis[j]<minn)
                minn = spd[p=j];
        vis[p] = true;
        for (int j=0; j<n; j++)
            if (! vis[j])
            {
                if (dis[p]+len[p][j] < dis[j])
                {
                    dis[j] = dis[p] + len[p][j];
                    num[j] = num[p] + 1;
                    dis_path[j] = p;
                }
                else if (dis[p]+len[p][j]==dis[j]
                    && num[p]+1 < num[j])
                {
                    num[j] = num[p] + 1;
                    dis_path[j] = p;
                }
            }
    }
}

int main()
{
    memset(len, INF, sizeof len);
    memset(tim, INF, sizeof tim);
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        len[i][i] = 0;
        tim[i][i] = 0;
    }
    for (int i=0; i<m; i++)
    {
        int a, b, o, l, t;
        cin >> a >> b >> o >> l >> t;
        len[a][b] = l;
        tim[a][b] = t;
        if (o != 1)
        {
            len[b][a] = l;
            tim[b][a] = t;
        }
    }
    int s, e;
    cin >> s >> e;
    dijkstra1(s);
    for (int p=time_path[e]; p!=s; p=time_path[p])
        time_ans.push_back(p);
    reverse(time_ans.begin(), time_ans.end());    
    dijkstra2(s);
    for (int p=dis_path[e]; p!=s; p=dis_path[p])
        dis_ans.push_back(p);
    reverse(dis_ans.begin(), dis_ans.end());
    int flag = 1, index = 0;
    while (index<min(dis_ans.size(), time_ans.size()))
    {
        if (dis_ans[index] != time_ans[index])
        {
            flag = 0;
            break;
        }
        index ++;
    }
    if (index<dis_ans.size() || index<time_ans.size())
        flag = 0;
    if (flag)
    {
        printf("Time = %d; ", spd[e]);
        printf("Distance = %d: ", dis[e]);
        cout << s << " => ";
        for (auto i: time_ans) printf("%d => ", i);
        printf("%d\n", e);
    }
    else
    {
        printf("Time = %d: ", spd[e]);
        cout << s << " => ";
        for (auto i: time_ans) printf("%d => ", i);
        printf("%d\n", e);
        printf("Distance = %d: ", dis[e]);
        cout << s << " => ";
        for (auto i: dis_ans) printf("%d => ", i);
        printf("%d\n", e);
    }
    return 0;
}