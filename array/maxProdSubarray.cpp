class Solution
{
public:
    long long maxProduct(vector<int> arr, int n)
    {
        long long int mx1 = INT_MIN, mx2 = INT_MIN;
        long long int prof = 1, prol = 1;
        for (int i = 0; i < n; i++)
        {
            prof *= arr[i];
            mx1 = max(mx1, prof);
            if (prof == 0)
                prof = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            prol *= arr[i];
            mx2 = max(mx2, prol);
            if (prol == 0)
                prol = 1;
        }
        return max(mx1, mx2);
    }
};