class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        int ans = arr[0];
        int sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum = max(arr[i], sum + arr[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
