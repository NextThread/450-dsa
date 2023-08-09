vector<int> firstNegative(vector<int> arr, int n, int k)
{
    vector<int> ans(n - k + 1);
    int idx = 0, firstNegIndex = 0;
    for (int end = k - 1; end < n; end++)
    {
        while (firstNegIndex < end && (firstNegIndex <= end - k || arr[firstNegIndex] >= 0))
        {
            firstNegIndex++;
        }
        if (arr[firstNegIndex] < 0)
            ans[idx++] = arr[firstNegIndex];
        else
            ans[idx++] = 0;
    }
    return ans;
}