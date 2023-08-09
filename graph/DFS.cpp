#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &storedfstraversal)
{
    storedfstraversal.push_back(node);
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, storedfstraversal);
    }
}

int main() {
    int v, e;    // v = no of nodes, e = no of edges
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i = 0 ; i < e ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> storedfstraversal;
    vector<bool> vis(v, false);
    for (int i = 1; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, storedfstraversal);
    }
    cout << "DFS traversal of the given graph " << '\n';
    for (int i = 0; i < storedfstraversal.size(); i++)
        cout << storedfstraversal[i] << " ";
}