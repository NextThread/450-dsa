class Solution
{
public:
    long long mod = 1000000007;
    long long add(int a, int b)
    {
        return (a % mod + b % mod) % mod;
    }
    long long mul(int a, int b)
    {
        return ((a % mod) * (b % mod)) % mod;
    }
    long long solve1(int n, int k, vector<int> &dp)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return add(k, mul(k, (k - 1)));
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = add(mul(solve1(n - 2, k, dp), k - 1), mul(solve1(n - 1, k, dp), k - 1));
    }
    long long countWays(int n, int k)
    {
        vector<int> dp(n + 1, -1);
        long long ans = solve1(n, k, dp);
        return ans;
    }
};