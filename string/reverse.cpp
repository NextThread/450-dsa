#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    /*    stl    */
    reverse(s.begin(), s.end());
    cout << s << '\n';
    /*   Normal implmentation   */
    for(int i = 0 ; i < s.length() ; i++) swap(s[i], s[s.length()-i-1]);
    cout << s << '\n';
}