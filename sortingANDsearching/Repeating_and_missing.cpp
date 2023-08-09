class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];
        int freq[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == 2)
            {
                ans[0] = i;
            }
            if (freq[i] == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }
};