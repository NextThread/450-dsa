class Solution
{
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == s1.length() || j == s2.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int op1 = 0, op2 = 0;
        if (s1[i] == s2[j])
        {
            op1 = 1 + f(i + 1, j + 1, s1, s2, dp);
        }
        else
        {
            op2 = max(f(i + 1, j, s1, s2, dp), f(i, j + 1, s1, s2, dp));
        }
        return dp[i][j] = max(op1, op2);
    }

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return f(0, 0, s1, s2, dp);
    }
};