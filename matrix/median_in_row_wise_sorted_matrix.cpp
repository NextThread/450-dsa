int f(vector<int> &row, int mid)
{
    int lo = 0, hi = row.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (row[mid] <= mid)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}
int median(vector<vector<int>> &matrix, int R, int C)
{
    int lo = 0, hi = 1e9;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int cnt = 0;
        for (int i = 0; i < R; i++)
        {
            cnt += f(matrix[i], mid);
        }
        if (cnt <= (R * C) / 2)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}