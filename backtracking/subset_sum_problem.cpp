int equalPartitionDP(int n, int arr[], vector<vector<int>> &dp, int sum)
{
  if (sum == 0)
    return 1;
  if (sum < 0 || n == 0)
    return 0;
  if (dp[n][sum] != -1)
    return dp[n][sum];
  return dp[n][sum] = equalPartitionDP(n - 1, arr, dp, sum - arr[n - 1]) || equalPartitionDP(n - 1, arr, dp, sum);
}
int equalPartition(int n, int arr[])
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  if (sum & 1)
    return 0;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  return equalPartitionDP(n, arr, dp, sum / 2);
}