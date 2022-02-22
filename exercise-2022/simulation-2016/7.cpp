#include <iostream>
using namespace std;

int main()
{
    int n; char c;
    cin >> n >> c;
    for (int i=0; i<int((n+1)/2); i++)
    {
        for (int j=0; j<n; j++)
            putchar(c);
        putchar('\n');
    }
    return 0;
}