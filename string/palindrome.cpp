#include <bits/stdc++.h>
using namespace std;

bool ispalin(string s)
{
    int lo = 0, hi = s.length()-1;
    while(lo <= hi)
    {
        if(s[lo++] != s[hi--]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if(ispalin(s)) cout << "yes" << '\n';
    else cout << "no" << '\n';
}