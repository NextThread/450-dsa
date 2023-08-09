class Solution
{
public:
    int f(int i, int j, int n, vector<vector<int>> &m, vector<vector<int>> &dp)
    {
        if (j >= n or j < 0)
            return 0;
        if (i == n - 1)
            return dp[i][j] = m[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int op1 = f(i + 1, j, n, m, dp);
        int op2 = f(i + 1, j - 1, n, m, dp);
        int op3 = f(i + 1, j + 1, n, m, dp);
        return dp[i][j] = m[i][j] + max(op1, max(op2, op3));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int res = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            res = max(res, f(0, i, N, Matrix, dp));
        }
        return res;
    }
};