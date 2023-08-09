class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum = 0;
        int minn = INT_MAX;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > x)
                return 1;
            sum += arr[i];
            while (sum > x && start < i)
            {
                if (i - start < minn)
                    minn = i - start + 1;
                sum -= arr[start];
                start++;
            }
        }
        if (minn == INT_MIN)
            return 0;
        return minn;
    }
};