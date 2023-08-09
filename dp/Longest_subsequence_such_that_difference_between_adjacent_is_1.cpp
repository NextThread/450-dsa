class Solution
{
public:
    // problem name can be like, the absolute diff of adjacent elements should be 1
    int f(vector<vector<int>> &dp, int prev, int ind, int n, int arr[])
    {
        if (ind >= n)
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1]; // if pre-stored
        int inc = 0;
        if (prev == -1 or abs(arr[ind] - arr[prev]) == 1)
        { // agar diff 1 ka h, then only we can increment len
            inc = 1 + f(dp, ind, ind + 1, n, arr);
        }
        int exc = f(dp, prev, ind + 1, n, arr); // else skip
        return dp[ind][prev + 1] = max(inc, exc);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(dp, -1, 0, N, A);
    }
};