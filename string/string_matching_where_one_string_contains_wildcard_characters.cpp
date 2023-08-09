class Solution
{
public:
    int f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 and j < 0)
            return true; // if we traversed both, that means pattern covered the whole string
        if (i >= 0 and j < 0)
            return false; // string is left, but pattern khatam(pattern is over)
        if (i < 0 and j >= 0)
        {                                // string khatam, but pattern baaki h, to check kro(string is over but pattern left)
            for (int k = 0; k <= j; k++) // if in that range, we encounter *, that means we can replace * by an empty string and ignore it. but if we got any letter ,then it's not possible to represent this, so return false
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] or p[j] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp); // if both matches
        }
        else if (p[j] == '*')
        {
            return dp[i][j] = f(i - 1, j, s, p, dp) or f(i, j - 1, s, p, dp); // take or of two options, if any one is true, then it'll return true
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};