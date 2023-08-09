class Solution
{
public:
    long long dp[10][30];
    long long solveCount(int mat[][3], int N, int i, int j)
    {
        if (i < 0 || i > 3 || j < 0 || j > 2 || mat[i][j] == -1)
            return 0;
        else if (dp[mat[i][j]][N] != -1)
        {
            return dp[mat[i][j]][N];
        }
        else if (N == 1)
        {
            if (mat[i][j] != -1)
            {
                return 1;
            }
            return 0;
        }
        else
        {
            long long up = solveCount(mat, N - 1, i - 1, j);
            long long down = solveCount(mat, N - 1, i + 1, j);
            long long left = solveCount(mat, N - 1, i, j - 1);
            long long right = solveCount(mat, N - 1, i, j + 1);
            long long self = solveCount(mat, N - 1, i, j);
            return dp[mat[i][j]][N] = up + down + left + right + self;
        }
    }

    long long getCount(int N)
    {
        int mat[4][3] = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9,
            -1, 0, -1};
        long long res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] == -1)
                    continue;
                res += solveCount(mat, N, i, j);
            }
        }
        return res;
    }
};