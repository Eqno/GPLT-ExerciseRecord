#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
int h[MAXN];
vector<vector<int>> s;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &h[i]);
    int m;
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        int k;
        scanf("%d", &k);
        s.push_back({});
        for (int j=0; j<k; j++)
        {
            int t;
            scanf("%d", &t);
            s.back().push_back(t);
        }
    }
    vector<int> ans;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<s.size(); j++)
        {
            bool flag = true;
            for (int k=0; k<s[j].size(); k++)
            {
                if (h[i+k] != s[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(j+1);
                // printf("%d\n", j+1);
                // for (int k=0; k<s[j].size(); k++)
                //     printf("%d %d\n", h[i+k], s[j][k]);
                i += s[j].size() - 2;
                // printf("%d\n\n", i);
                break;
            }
        }
    }
    printf("%d", ans[0]);
    for (int i=1; i<ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}