class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int row = -1, mx = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                    cnt++;
            }
            if (cnt > mx)
            {
                mx = cnt;
                row = i;
            }
        }
        return row;
    }
};
