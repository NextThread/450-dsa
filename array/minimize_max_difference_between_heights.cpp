class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int res = arr[n - 1] - arr[0];
        int mn = arr[0];
        int mx = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < k)
                continue;
            mn = min(arr[0] + k, arr[i] - k);
            mx = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, mx - mn);
        }
        return res;
    }
};