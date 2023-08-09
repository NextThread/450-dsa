class Solution
{
public:
    bool f(int ind, int arr[], int n, int target, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool pick = f(ind + 1, arr, n, target - arr[ind], dp);
        bool skip = f(ind + 1, arr, n, target - 0, dp);
        return dp[ind][target] = pick or skip;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2)
            return 0;
        int target = sum / 2;
        vector<vector<int>> dp(N, vector<int>(target + 1, -1));
        return f(0, arr, N, target, dp);
    }
};