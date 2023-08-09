#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_possible(vector<int> &a, int n, int cows, int min_dist)
{
    int cows_cnt = 1;
    int last_placed_cow = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - last_placed_cow >= min_dist)
        {
            cows_cnt++;
            last_placed_cow = a[i];
        }
    }
    if (cows_cnt >= cows)
        return true;
    return false;
}

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
            cin >> stalls[i];
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = stalls[n - 1] - stalls[0];
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (is_possible(stalls, n, k, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout << hi << endl;
    }
}