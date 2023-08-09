/*                        Tabulation              */

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        int res = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

/*                      Memoization

    class Solution
{
public:
    int res = 0;
    int f(int i, int j, string &a, string &b, int &n, int &m, vector<vector<int>> &dp)
    {
        if (i >= n or j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int cnt = 0;
        if (a[i] == b[j])
        {
            cnt = 1 + f(i + 1, j + 1, a, b, n, m, dp);
            res = max(res, cnt);
        }
        f(i + 1, j, a, b, n, m, dp);
        f(i, j + 1, a, b, n, m, dp);
        return dp[i][j] = cnt;
    }

    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        f(0, 0, s1, s2, n, m, dp);
        return res;
    }
};

*/