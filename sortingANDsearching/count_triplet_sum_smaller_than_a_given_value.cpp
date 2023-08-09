class Solution
{
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                long long val = arr[i] + arr[j] + arr[k];
                if (val < sum)
                {
                    cnt += k - j;
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return cnt;
    }
};