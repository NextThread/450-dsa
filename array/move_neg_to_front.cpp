#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;     // need to maintain the order of positive elements
    cin >> n;
    vector<int> a(n), res;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] < 0) res.push_back(a[i]);
    }
    for(int i = 0 ; i < n ; i++) if(a[i] > 0) res.push_back(a[i]);
    for(int x : res) cout << x << ' ';
}