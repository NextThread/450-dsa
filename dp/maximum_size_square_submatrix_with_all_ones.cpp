class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int mxarea = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mat[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
                mxarea = max(mxarea, dp[i][j]);
            }
        }
        return mxarea;
    }
};