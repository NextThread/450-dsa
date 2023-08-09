class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        int sum = arr[0];
        int res = sum;
        for (int i = 1; i < n; i++)
        {
            sum = max(arr[i], sum + arr[i]);
            res = max(res, sum);
        }
        return res;
    }
};