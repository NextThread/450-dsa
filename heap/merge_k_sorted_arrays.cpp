// divide and conquere based approach

void merge(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = 0, k = 0, n1 = arr1.size(), n2 = arr2.size();
    vector<int> arr(n1 + n2);
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];

    swap(arr, arr1);
}
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    for (int interval = 1; interval < K; interval *= 2)
    {
        for (int i = 0; i + interval < K; i += 2 * interval)
        {
            merge(arr[i], arr[i + interval]);
        }
    }
    return arr[0];
}

// using map

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
            mp[arr[i][j]]++;
    }
    vector<int> ans;
    for (auto i : mp)
    {
        int val = i.second;
        while (val)
        {
            ans.push_back(i.first);
            val--;
        }
    }
    return ans;
}