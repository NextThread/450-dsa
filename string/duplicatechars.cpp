#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    vector<char> res;
    for(char ch : s) {
        mp[ch]++;
        if(mp[ch] > 1) res.push_back(ch);
    }
    for(auto it : res) cout << it << ' ';
}