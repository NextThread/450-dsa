class Solution
{
public:
    int f(int i, int j, string a, string b, vector<vector<int>> &dp)
    {
        if (i >= a.length() or j >= b.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
        {
            return dp[i][j] = 1 + f(i + 1, j + 1, a, b, dp);
        }
        int op1 = f(i + 1, j, a, b, dp);
        int op2 = f(i, j + 1, a, b, dp);
        return dp[i][j] = max(op1, op2);
    }

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return f(0, 0, s1, s2, dp);
    }
};