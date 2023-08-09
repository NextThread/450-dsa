class Solution
{
public:
    int t[1001][1001];
    int solve(int wt[], int val[], int n, int W)
    {
        if (n == 0 or W == 0)
            return 0;
        if (t[n][W] != -1)
            return t[n][W];
        if (wt[n - 1] <= W)
            return t[n][W] = max(val[n - 1] + solve(wt, val, n, W - wt[n - 1]), solve(wt, val, n - 1, W));
        else
            return t[n][W] = solve(wt, val, n - 1, W);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(t, -1, sizeof(t));
        return solve(wt, val, N, W);
    }
};