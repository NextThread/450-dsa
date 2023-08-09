#include<bits/stdc++.h>
using namespace std;

int maxx(vector<int>& arr)
{
    int mx = arr[0];
    for(int it : arr) mx = max(mx, it);
    return mx;
}

int minn(vector<int>& arr)
{
    int mx = arr[0];
    for(int it : arr) mx = min(mx, it);
    return mx;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    /*   Using function  */
    cout << "Max element is " << maxx(a) << '\n';
    cout << "Min element is " << minn(a) << '\n';

    /* using stl   */

    cout << *max_element(begin(a), end(a)) << ' ' << *min_element(begin(a), end(a)) << '\n';

    /*  basic implementation  */
    int mx = a[0], mn = a[0];
    for(int it : a)
    {
        mx = max(mx, it);
        mn = min(mn, it);
    }
    cout << mx << ' ' << mn << '\n';
}