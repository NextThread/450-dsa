int f(int n, int a, int b, vector<int> &dp)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    if (n >= a and !f(n - a, a, b, dp))
        return dp[n] = 1;
    if (n >= b and !f(n - b, a, b, dp))
        return dp[n] = 1;
    if (n >= 1 and !f(n - 1, a, b, dp))
        return dp[n] = 1;
    return dp[n] = 0;
}

int coinGameWinner(int n, int a, int b)
{
    vector<int> dp(n + 1, -1);
    return f(n, a, b, dp);
}
