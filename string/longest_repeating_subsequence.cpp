class Solution
{
public:
    int f(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.size() || j == b.size())
            return 0; // if index reaches endpoint
        if (dp[i][j] != -1)
            return dp[i][j]; // check if previously stored
        int take = 0;
        if (a[i] == b[j] && i != j) // if both are equal, increment both the indexes
        {
            take = 1 + f(a, b, i + 1, j + 1, dp);
        }
        int donttake = max(f(a, b, i + 1, j, dp), f(a, b, i, j + 1, dp)); // we have 2 options, either increment i or j, so take the max of both
        return dp[i][j] = max(take, donttake);
    }

    int LongestRepeatingSubsequence(string str)
    {
        vector<vector<int>> dp(str.length() + 1, vector<int>(str.length() + 1, -1));
        return f(str, str, 0, 0, dp);
    }
};