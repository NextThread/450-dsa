class Solution
{
public:
    int f(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n < 0)
            return INT_MIN;
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int op1 = 0, op2 = 0, op3 = 0;
        op1 = 1 + f(n - x, x, y, z, dp);
        op2 = 1 + f(n - y, x, y, z, dp);
        op3 = 1 + f(n - z, x, y, z, dp);
        return dp[n] = max(op1, max(op2, op3));
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        return max(0, f(n, x, y, z, dp));
    }
};