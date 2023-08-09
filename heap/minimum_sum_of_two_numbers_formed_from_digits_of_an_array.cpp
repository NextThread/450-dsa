string solve(int arr[], int n)
{
    sort(arr, arr + n);
    int rem = 0;
    string res;
    for (int i = n - 1; i >= 0; i -= 2)
    {
        int temp;
        if (i == 0)
            temp = arr[i] + rem;
        else
            temp = arr[i] + arr[i - 1] + rem;
        res += temp % 10 + '0';
        if (temp >= 10)
            rem = temp / 10;
        else
            rem = 0;
    }
    if (rem)
        res += rem + '0';
    while (res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}