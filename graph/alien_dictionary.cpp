class Solution
{
public:
    void dfs(int src, vector<vector<int>> &adj, vector<int> &vis, string &res)
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, res);
            }
        }
        char ch = src + 'a';
        res = ch + res;
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N - 1; i++)
        {
            string cur = dict[i];
            string next = dict[i + 1];
            for (int j = 0; j < min(cur.length(), next.length()); j++)
            {
                if (cur[j] != next[j])
                {
                    adj[cur[j] - 'a'].push_back(next[j] - 'a');
                    break;
                }
            }
        }
        vector<int> vis(K, 0);
        string res = "";
        for (int i = 0; i < K; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, res);
            }
        }
        return res;
    }
};