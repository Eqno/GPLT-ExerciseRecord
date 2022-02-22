#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{ return !b ? a : gcd(b, a%b); }

ll lcm(ll a, ll b)
{ return a / gcd(a, b) * b; }

void solve()
{
    int n;
    cin >> n;
    ll fenzi = 0, fenmu = 1;
    for (int i=0; i<n; i++)
    {
        ll tmpzi, tmpmu;
        scanf("%lld/%lld", &tmpzi, &tmpmu);
        ll l = lcm(fenmu, tmpmu);
        fenzi = l/fenmu*fenzi + l/tmpmu*tmpzi;
        fenmu = l;
        ll g = gcd(fenzi, fenmu);
        fenzi /= g, fenmu /= g;
    }
    ll zhengshu = fenzi / fenmu;
    ll fenshu = fenzi % fenmu;
    if (zhengshu) printf("%lld", zhengshu);
    if (fenshu)
    {
        if (zhengshu) putchar(' ');
        printf("%lld/%lld", fenshu, fenmu);
    }
    if (!zhengshu && !fenshu) puts("0");
}

int main()
{
    solve();
    return 0;
}