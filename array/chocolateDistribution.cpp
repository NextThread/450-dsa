class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long min_dif = INT_MAX;
        for (int i = 0; i <= a.size() - m; i++)
        {
            min_dif = min(min_dif, a[i + (m - 1)] - a[i]);
        }
        return min_dif;
    }
};
