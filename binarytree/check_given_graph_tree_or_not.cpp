#include <bits/stdc++.h>
using namespace std;
#define N 100000

vector<int> gr1[N], gr2[N];

bool vis1[N], vis2[N];

void Add_edge(int u, int v)
{
    gr1[u].push_back(v);
    gr2[v].push_back(u);
}

void dfs1(int x)
{
    vis1[x] = true;

    for (auto i : gr1[x])
        if (!vis1[i])
            dfs1(i);
}

void dfs2(int x)
{
    vis2[x] = true;

    for (auto i : gr2[x])
        if (!vis2[i])
            dfs2(i);
}

bool Is_Connected(int n)
{
    memset(vis1, false, sizeof vis1);
    dfs1(1);

    memset(vis2, false, sizeof vis2);
    dfs2(1);

    for (int i = 1; i <= n; i++)
    {

        // If any vertex it not visited in any direction
        // Then graph is not connected
        if (!vis1[i] and !vis2[i])
            return false;
    }
    return true;
}
bool checkCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, node, vis, adj))
                return true;
        }
        else if (it != parent)
            return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, -1, vis, adj))
                return true;
        }
    }

    return false;
}

int main()
{
    int n = 5;
    int V = n + 1;
    vector<int> adj[V];
    adj[1].push_back(0);
    adj[0].push_back(2);

    adj[0].push_back(3);
    adj[3].push_back(4);

    adj[0].push_back(1);
    adj[2].push_back(0);

    adj[3].push_back(0);
    adj[4].push_back(3);

    adj[2].push_back(1);
    adj[1].push_back(2);

    Add_edge(1, 0);
    Add_edge(0, 2);
    Add_edge(0, 3);
    Add_edge(3, 4);
    Add_edge(2, 1);

    bool connected;
    bool cycle;
    if (Is_Connected(n))
        connected = true;
    else
        connected = false;
    if (isCycle(V, adj))
        cycle = true;
    else
        cycle = false;
    if (cycle == false and connected == true)
        cout << "Tree";
    else
        cout << "Not tree";
    return 0;
}
