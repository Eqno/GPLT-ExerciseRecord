#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<char> st;

int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    for (auto i: p) st.insert(i);
    for (auto i: s)
        if (st.find(i) == st.end())
            putchar(i);
    if (s.empty()) putchar('\n');
    return 0;
}