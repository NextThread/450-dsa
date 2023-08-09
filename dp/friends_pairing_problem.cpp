const int mod = 1e9 + 7;
class Solution
{
public:
    long long f(int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0 or n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n] % mod;
        long solo = f(n - 1, dp) % mod;
        long duo = (n - 1) * f(n - 2, dp) % mod;
        return dp[n] = (solo + duo) % mod;
    }

    int countFriendsPairings(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};