#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

string start, endd;
struct Node
{
    string name;
    int num;
};
vector<Node> node;
unordered_map<string, int> indx;
const int MAXN = 300, INF = 0x3f3f3f3f;
int n, k, mat[MAXN][MAXN], vis[MAXN], cot[MAXN],
    dis[MAXN], num[MAXN], kill[MAXN], path[MAXN];

void dijkstra(int sta)
{
    vis[sta] = true;
    cot[sta] = 1;
    for (int i=0; i<n; i++)
    {
        dis[i] = mat[sta][i];
        if (dis[i] < INF)
        {
            num[i] = 1;
            kill[i] = node[i].num;
            path[i] = sta;
            cot[i] = cot[sta];
        }
    }
    for (int i=0; i<n; i++)
    {
        int minn = INF, p = -1;
        for (int j=0; j<n; j++)
            if (!vis[j] && dis[j] < minn)
                minn = dis[p=j];
        vis[p] = true;
        for (int j=0; j<n; j++)
            if (! vis[j])
            {
                if (dis[p]+mat[p][j] < dis[j])
                {
                    cot[j] = cot[p];

                    dis[j] = dis[p] + mat[p][j];
                    num[j] = num[p] + 1;
                    kill[j] = kill[p] + node[j].num;
                    path[j] = p;
                }
                else if (dis[p]+mat[p][j] == dis[j])
                {
                    cot[j] += cot[p];
                    if (num[p]+1 > num[j])
                    {
                        num[j] = num[p] + 1;
                        kill[j] = kill[p] + node[j].num;
                        path[j] = p;
                    }
                    if (num[p]+1==num[j] && kill[p]+node[j].num>kill[j])
                    {
                        kill[j] = kill[p] + node[j].num;
                        path[j] = p;
                    }
                }
            }
    }
}
int main()
{
    memset(mat, INF, sizeof mat);
    memset(dis, INF, sizeof dis);
    memset(path, INF, sizeof path);
    scanf("%d%d", &n, &k);
    cin >> start >> endd;
    indx[start] = 0;
    node.emplace_back(Node{start, 0});
    for (int i=1; i<n; i++)
    {
        string name;
        int num;
        cin >> name >> num;
        indx[name] = i;
        node.emplace_back(Node({name, num}));
    }
    for (int i=0; i<k; i++)
    {
        string a, b;
        int dis;
        cin >> a >> b >> dis;
        mat[indx[a]][indx[b]] = dis;
        mat[indx[b]][indx[a]] = dis;
    }
    dijkstra(indx[start]);
    vector<string> ans;
    for (int i=indx[endd]; i!=indx[start]; i=path[i])
        ans.emplace_back(node[i].name);
    reverse(ans.begin(), ans.end());
    cout << start;
    for (auto i: ans) cout << "->" << i;
    cout << endl;
    printf("%d %d %d\n", cot[indx[endd]], dis[indx[endd]], kill[indx[endd]]);
    return 0;
}