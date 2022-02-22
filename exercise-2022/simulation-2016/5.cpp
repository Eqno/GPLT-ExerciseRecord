#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll n, s = 1, r = 0;
    cin >> n;
    for (int i=1; i<=n; i++)
        s *= i, r += s;
    cout << r << endl;
    return 0;
}