class Solution
{
public:
    // Same as product array except self
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        long long int fromBegin = 1, fromLast = 1;
        vector<long long int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }
};