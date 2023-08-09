int smallestSumSubarr(int arr[], int n)
{
    int sum = INT_MAX, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
            sum = arr[i];

        else
            sum += arr[i];

        mn = min(mn, sum);
    }
    return mn;
}