#include <iostream>
using namespace std;

int quan[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
    int n, f = 0;
    cin >> n;
    while (n --)
    {
        string s;
        cin >> s;
        long long val = 0, ff = 0;
        for (int i=0; i<17; i++)
        {
            int num = s[i] - '0';
            if (num<0 || num>9)
            {
                ff = 1;
                break;
            }
            val += num * quan[i];
        }
        char code = m[val%11];
        if (ff || s[17] != code)
        {
            cout << s << endl;
            f = 1;
        }
    }
    if (! f) cout << "All passed" << endl;
    return 0;
}