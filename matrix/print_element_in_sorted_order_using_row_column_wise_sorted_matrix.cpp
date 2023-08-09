class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        vector<int> vals;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                vals.push_back(Mat[i][j]);
        }
        sort(vals.begin(), vals.end());
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = vals[cnt];
                cnt++;
            }
        }
        return Mat;
    }
};
