int countRemovals(int a[], int i, int j, int k)
{
    if (i >= j)
        return 0;

    else if ((a[j] - a[i]) <= k)
        return 0;

    else if (dp[i][j] != -1)
        return dp[i][j];

    else if ((a[j] - a[i]) > k)
    {
        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}