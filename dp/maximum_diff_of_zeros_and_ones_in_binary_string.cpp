class Solution
{
public:
    int maxSubstring(string S)
    {
        int cur = 0, mx = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '1')
                cur--;
            else
                cur++;
            mx = max(mx, cur);
            if (cur < 0)
                cur = 0;
        }
        if (mx == 0)
            return -1;
        return mx;
    }
};