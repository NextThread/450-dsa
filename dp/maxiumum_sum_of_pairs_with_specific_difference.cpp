class Solution
{
public:
    int f(int arr[], int n, int k, vector<int> &dp)
    {
        if (n <= 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int op1 = 0;
        if (arr[n] - arr[n - 1] < k)
        {
            op1 = max(f(arr, n - 2, k, dp) + arr[n - 1] + arr[n], f(arr, n - 1, k, dp));
        }
        else
        {
            op1 = f(arr, n - 1, k, dp);
        }
        return dp[n] = op1;
    }

    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        vector<int> dp(N + 1, -1);
        return f(arr, N - 1, K, dp);
    }
};
