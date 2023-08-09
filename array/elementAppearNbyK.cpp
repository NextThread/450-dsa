vector<int> morethanNbyK(int arr[], int n, int k)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }
    vector<int> res;
    for (auto it : mp)
    {
        if (it.second >= n / k)
            res.push_back(it.first);
    }
    return res;
}