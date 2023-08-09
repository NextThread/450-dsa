#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int start = 0, end = n-1;
    while(start <= end) swap(a[start++], a[end--]);
    for(int x : a) cout << x << ' ';
}