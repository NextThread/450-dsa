class Solution
{
public:
    //   Stickler Thief

    int backward(int arr[], int ind, vector<int> &dp, int n) // function to start from last
    {
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int dontpick = 0 + backward(arr, ind - 1, dp, n);
        int pick = arr[ind] + backward(arr, ind - 2, dp, n);
        return dp[ind] = max(pick, dontpick);
    }

    int forward(int arr[], int ind, vector<int> &dp, int n) // function to start from first
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int dontpick = 0 + forward(arr, ind + 1, dp, n);
        int pick = arr[ind] + forward(arr, ind + 2, dp, n);
        return dp[ind] = max(pick, dontpick);
    }

    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1, -1);
        // return backward(arr, n-1, dp);
        return forward(arr, 0, dp, n);
    }
};