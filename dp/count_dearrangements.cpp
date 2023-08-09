int dp1[100001];
int f(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = (n - 1) * (f(n - 1) + f(n - 2));
}

int main()
{
    int n = 4;
    memset(dp, -1, sizeof(dp));
    cout << f(n);
    return 0;
}
