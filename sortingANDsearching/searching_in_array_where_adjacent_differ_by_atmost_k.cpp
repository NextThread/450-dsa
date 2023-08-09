int search(vector<int> &arr, int n, int key, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == key)
            return i;
        i += max(1, abs(arr[i] - key) / k);
    }
    return -1;
}