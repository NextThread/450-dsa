/*          Memo                   */

class Solution
{
public:
    int f(int i, int j, int n, int a[], vector<vector<int>> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        int len = 0;
        len = f(i + 1, j, n, a, dp);
        if (j == -1 or a[i] > a[j])
            len = max(len, 1 + f(i + 1, i, n, a, dp));
        return dp[i][j + 1] = len;
    }

    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, -1, n, a, dp);
    }
};

/*                 Tabulation          */
class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};