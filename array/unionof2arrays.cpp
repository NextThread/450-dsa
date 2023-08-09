#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < m; ++j)
        cin >> b[i];
    set<int> st;
    for (auto it : a)
        st.insert(it);
    for (auto it : b)
        st.insert(it);
    cout << st.size() << '\n';
}