class Solution
{
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int ans = INT_MIN;
        for (int i = 0; i < C; i++)
        {
            int dp[R] = {0};
            for (int j = i; j < C; j++)
            {
                int curr = 0;
                for (int r = 0; r < R; r++)
                {
                    dp[r] += M[r][j];
                    curr += dp[r];
                    if (curr > ans)
                        ans = curr;
                    if (curr < 0)
                        curr = 0;
                }
            }
        }
        return ans;
    }
};