int maxSum(vector<int> a, int ind, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (ind == 0)
        return a[ind];
    if (dp[ind] != -1)
        return dp[ind];
    int op1 = a[ind] + a[ind - 1] + maxSum(a, ind - 3, dp);
    int op2 = maxSum(a, ind - 1, dp);
    int op3 = a[ind] + maxSum(a, ind - 2, dp);
    return dp[ind] = max(op1, max(op2, op3));
}