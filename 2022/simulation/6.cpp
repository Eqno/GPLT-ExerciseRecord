#include <ctype.h>
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        bool f = true;
        for (int j=0; j<s.size()-1; j++)
        {
            if (isupper(s[j]) && s[j+1]!=tolower(s[j]) && s[j+1]!=toupper(s[j]+1)
                || islower(s[j]) && s[j+1]!=toupper(s[j]) && s[j+1]!=tolower(s[j]-1))
            {
                puts("N");
                f = false;
                break;
            }
        }
        if (f) puts("Y");
    }
    return 0;
}