class Solution
{
public:
    const long long int mod = 1e9 + 7;
    long long int f(int i, int j, string &str, vector<vector<long long int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j] % mod;
        if (i == j)
            return dp[i][j] = (long long int)1;
        else if (str[i] == str[j])
        {
            return dp[i][j] = 1 + (f(i + 1, j, str, dp) % mod + f(i, j - 1, str, dp) % mod) % mod;
        }
        return dp[i][j] = mod + ((f(i + 1, j, str, dp) % mod + f(i, j - 1, str, dp) % mod) % mod - f(i + 1, j - 1, str, dp) % mod);
    }

    long long int countPS(string str)
    {
        vector<vector<long long int>> dp(str.length() + 1, vector<long long int>(str.length() + 1, -1));
        return f(0, str.length() - 1, str, dp) % mod;
    }
};