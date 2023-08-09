class Solution
{
public:
    int helper(int c[], int i, int n, int w, vector<vector<int>> &dp)
    {
        if (w == 0)
            return 0;
        if (i == n)
            return 1e8;
        if (dp[i][w] != -1)
            return dp[i][w];
        int t = INT_MAX, nt = 0;
        nt = helper(c, i + 1, n, w, dp);
        int wt = i + 1;
        if (c[i] != -1 && wt <= w)
            t = helper(c, i, n, w - wt, dp) + c[i];
        return dp[i][w] = min(t, nt);
    }
    int minimumCost(int cost[], int N, int W)
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return helper(cost, 0, N, W, dp);
    }
};