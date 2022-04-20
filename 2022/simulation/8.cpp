#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3e6;
vector<int> prime;
bool flag[MAXN];
void make_prime(int n)
{
    for (int i=2; i<=n; i++)
    {
        if (! flag[i]) prime.emplace_back(i);
        for (auto j: prime)
        {
            if (i * j > n) break;
            flag[i * j] = true;
            if (i % j == 0) break;
        }
    }
}

int main()
{
    make_prime(2e6);
    int m, n, ans = 0;
    scanf("%d%d", &m, &n);
    for (int p=0; p<prime.size(); p++)
    {
        if (prime[p] < m) continue;
        if (prime[p] > n) break;
        for (int q=p+1; q<prime.size(); q++)
        {
            if (prime[q] > n) break;
            for (int r=q+1; r<prime.size(); r++)
            {
                if (prime[r] > n) break;
                if (!flag[prime[p]*prime[q]+prime[r]]
                    && !flag[prime[q]*prime[r]+prime[p]]
                    && !flag[prime[r]*prime[p]+prime[q]])
                {
                    // printf("%d %d %d\n", prime[p], prime[q], prime[r]);
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}