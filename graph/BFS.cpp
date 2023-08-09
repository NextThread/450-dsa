#include<bits/stdc++.h>
using namespace std;
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v+1);
    for(int i = 0 ; i < e ; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>storebfs;
    vector<bool>vis(v+1, false);
    queue<int>q;
    q.push(0); // push the starting node
    vis[0] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        storebfs.push_back(node);
        for(auto it : g[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
    for(int x : storebfs) cout<<x<<" ";
}