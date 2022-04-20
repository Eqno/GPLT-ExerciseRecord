#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 105;
int mat[MAXN][MAXN];

int main()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            scanf("%d", &mat[i][j]);
    int c = 1;
    for (int j=2; j<=n; j+=2)
    {
        for (int i=n; i>=1; i--)
        {
            if (i > c)
                mat[i][j] = mat[i-c][j];
            else mat[i][j] = x;
        }
        c ++;
        if (c == k + 1) c = 1;
    }
    vector<int> ans;
    for (int i=1; i<=n; i++)
    {
        int sum = 0;
        for (int j=1; j<=n; j++)
            sum += mat[i][j];
        ans.emplace_back(sum);
    }
    printf("%d", ans[0]);
    for (int i=1; i<ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}