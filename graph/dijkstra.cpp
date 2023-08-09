vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    queue<int> q;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    q.push(S);
    while (q.size())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            int curr = it[0];
            int dis = it[1];
            if (dist[curr] > dist[node] + dis)
            {
                dist[curr] = dist[node] + dis;
                q.push(curr);
            }
        }
    }
    return dist;
}