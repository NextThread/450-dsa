#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, int &cnt)
{
    vis[node] = true;
    cnt++;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, adj, cnt);
}
int main() {
    int v, e;     // v = no of nodes, e = no of edges
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i = 0 ; i < e ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
	vector<int> indegree(v, 0);
	for(int i = 0 ; i < v ; i++) {
	    for(auto it: adj[i]) indegree[it]++;
	}
    vector<int> fd;
	for(int i = 0 ; i < v ;i++) {
	    if(indegree[i] == 0) fd.push_back(i);
	}
	int cnt = 0;
    vector<bool> vis(v, false);
    for(int i = 0 ; i < fd.size() ; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, cnt);
    }
	if(cnt == v) cout<<"No cycle";
	else cout<<"Cycle present";
    return 0;
}