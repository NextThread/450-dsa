#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int *in;
int *out;
void dfs(vector<vector<ll>> &AList, ll &count, ll parent, ll src)
{
    for (ll it : AList[src])
    {
        if (it != parent)
        {
            dfs(AList, count, src, it);
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> AList(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        AList[u].push_back(v);
        AList[v].push_back(u);
    }
    in = new int[n + 1];
    out = new int[n + 1];
    ll count = 0;
    dfs(AList, count, 0, 1);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            if (in[x] < in[y] and out[x] > out[y])
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if (in[x] > in[y] and out[x] < out[y])
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}