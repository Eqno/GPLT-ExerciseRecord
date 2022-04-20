#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MAXN = 1e5+10;
int tmp[105];
string box[MAXN];
unordered_map<string, int> m;

int main()
{
    int n, s, c = 0;
    scanf("%d%d", &n, &s);
    for (int i=0; i<n; i++)
        cin >> box[i];
    for (int i=0; i<n/s; i++)
    {
        for (int j=0; j<s; j++)
            scanf("%d", &tmp[j]);
        for (int j=s-1; j>=0; j--)
            m[box[c++]] = tmp[j];
    }
    int k;
    scanf("%d", &k);
    while (k --)
    {
        string b;
        cin >> b;
        if (! m[b]) cout << "Wrong Number" << endl;
        else cout << m[b] << endl;
    }
    return 0;
}