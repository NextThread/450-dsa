class Solution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = 0 + max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};