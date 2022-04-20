#include <cstring>
#include <iostream>
using namespace std;

const int MAXM = 365*24*60+10;
int v[MAXM], w[MAXM], f[MAXM];

int main()
{
    register int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for (register int i=1; i<=n; i++)
        scanf("%d", &w[i]);
    for (register int i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    // memset(f, 0x3f, sizeof f);
    // f[0] = 0;
    // for (int i=1; i<=n; i++)
    //     for (int j=sum; j>=v[i]; j--)
    //         f[j] = min(f[j], f[j-v[i]]+w[i]);
    // while (f[sum] > m) sum --;
    // cout << sum << endl;

    for (register int i=1; i<=n; i++)
        for (register int j=m; j>=w[i]; j--)
            f[j] = max(f[j], f[j-w[i]]+v[i]);
    printf("%d\n", f[m]);
    return 0;
}