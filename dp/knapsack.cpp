class Solution
{
public:
    int dp[201][201];
    int solve(int wt[], int val[], int W, int N)
    {
        if (W == 0 || N == -1)
            return 0;
        if (dp[N][W] != -1)
            return dp[N][W];
        if (wt[N] > W)
            return dp[N][W] = solve(wt, val, W, N - 1);
        return dp[N][W] = max(val[N] + solve(wt, val, W - wt[N], N - 1), solve(wt, val, W, N - 1));
    }

    int knapSack(int W, int wt[], int val[], int N)
    {
        dp[N][W];
        memset(dp, -1, sizeof(dp));
        return solve(wt, val, W, N - 1);
    }
};
