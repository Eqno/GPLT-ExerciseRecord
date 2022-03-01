#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define int long long

struct Node { int x, y; };

bool readNode(vector<Node> &v)
{
    int k;
    cin >> k;
    while (k --)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    if (k > 5) return false;
    return true;
}

ll getIncisionLength(vector<Node> &n, ll &incLen, ll &f)
{
    int cot = 0;
    for (size_t i=0; i<n.size(); i++)
    {
        auto a = n[i], b = n[(i+1)%n.size()];
        if (a.x!=b.x && a.y!=b.y)
        {
            ll s = abs(a.x-b.x), t = abs(a.y-b.y);
            incLen = s*s + t*t, f = (i+1)%n.size(), cot ++;
        }
    }
    return cot;
}

void getCathetus(vector<Node> &n, vector<ll> &c)
{
    for (size_t i=0; i<n.size(); i++)
    {
        auto a = n[i], b = n[(i+1)%n.size()];
        if (a.x == b.x) c.push_back(abs(a.y-b.y));
        if (a.y == b.y) c.push_back(abs(a.x-b.x));
    }
}

bool judgeIncision(vector<Node> &m, vector<Node> &l, ll &f, ll &g)
{
    ll incLenM = -1, incLenL = -1;
    int nm = getIncisionLength(m, incLenM, f);
    int nl = getIncisionLength(l, incLenL, g);
    if (nm==1 && nl==1) return incLenM == incLenL;
    else if (nm==0 && nl==0)
    {
        vector<ll> cm, cl;
        getCathetus(m, cm);
        getCathetus(l, cl);
        for (auto i: cm)
            for (auto j: cl)
                if (i == j) return true;
        return false;
    }
    return false;
}

bool judge(vector<Node> &m, vector<Node> &l)
{
    ll f = -1, g = -1;
    if (! judgeIncision(m, l, f, g)) return false;
    if (f == -1 && g == -1) return true;
    ll s1 = abs(m[(f+1)%4].x-m[(f+2)%4].x);
    ll t1 = abs(m[(f+1)%4].y-m[(f+2)%4].y);
    ll s2 = abs(l[(g+1)%4].x-l[(g+2)%4].x);
    ll t2 = abs(l[(g+1)%4].y-l[(g+2)%4].y);
    return s1*s1 + t1*t1 == s2*s2 + t2*t2;
}

bool judgeEdge(vector<Node> &m, vector<Node> &l)
{
    ll f, g;
    return (m.size()==4 && l.size()==4 && judge(m, l))
        || (m.size()==4 && l.size()==3 && judgeIncision(m, l, f, g))
        || (m.size()==5 && l.size()==3 && judgeIncision(m, l, f, g))
        || (m.size()==3 && l.size()==3 && judgeIncision(m, l, f, g));
}

bool solve()
{
    vector<Node> a, b;
    if (!readNode(a) || !readNode(b))
        return false;
    vector<Node> *m = &a, *l = &b;
    if (a.size() < b.size()) m = &b, l = &a;
    return judgeEdge(*m, *l);
}

signed main()
{
    int n;
    cin >> n;
    while (n --)
    {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}