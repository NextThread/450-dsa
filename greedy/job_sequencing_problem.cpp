static bool comp(Job a1, Job a2)
{
    return a1.profit > a2.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comp);
    int res = 0, done = 0;
    vector<bool> visit(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j >= 1; j--)
        {
            if (visit[j] == false)
            {
                visit[j] = true;
                done++;
                res += arr[i].profit;
                break;
            }
        }
    }
    return {done, res};
}