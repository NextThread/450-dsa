vector<vector<long long>> dp;

long long check(int i, int j, int arr[])
{
    if (i >= j)
    {
        if (i == j)
            return arr[i];
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    long long firstpick = arr[i] + min(check(i + 2, j, arr), check(i + 1, j - 1, arr)); // skip one for 2nd player
    long long lastpick = arr[j] + min(check(i, j - 2, arr), check(i + 1, j - 1, arr));  // skip one for second player
    dp[i][j] = max(firstpick, lastpick);
    return dp[i][j];
}

long long maximumAmount(int arr[], int n)
{
    dp.clear();
    dp.resize(n + 1, vector<long long>(n + 1, -1));
    return check(0, n - 1, arr);
}