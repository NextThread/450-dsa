class Solution
{
public:
    void dfs(int i, vector<bool> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[i] = true;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
                st.push(it);
            }
        }
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> res;
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
                st.push(i);
            }
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};