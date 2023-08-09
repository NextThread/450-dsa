bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]] = i;
    }
    for (int i = 0; i < size; i++)
    {
        int big = arr[i] + n;
        int small = arr[i] - n;
        if ((mp.find(big) != mp.end() && mp[big] != i) or
            (mp.find(small) != mp.end() && mp[small] != i))
        {
            return true;
        }
    }
    return false;
}