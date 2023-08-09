#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0), dfsVis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(5);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(1);
    if (isCyclic(V, adj))
        cout << "Cycle Detected";
    else
        cout << "No Cycle Detected";
    return 0;
}