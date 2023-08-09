class Solution
{
public:
    int f(int i, int j, string &s, string &rev, vector<vector<int>> &dp)
    {
        if (i >= s.length() or j >= rev.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int op1 = 0, op2 = 0;
        if (s[i] == rev[j])
            return 1 + f(i + 1, j + 1, s, rev, dp);
        else
        {
            op1 = f(i + 1, j, s, rev, dp);
            op2 = f(i, j + 1, s, rev, dp);
        }
        return dp[i][j] = max(op1, op2);
    }

    int longestPalindromeSubseq(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return f(0, 0, s, rev, dp);
    }
};