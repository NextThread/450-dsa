class Solution
{
public:
    int lps(string s)
    {
        int len = 0, i = 1;
        while (i < s.size())
        {
            if (s[len] == s[i])
            {
                len++;
                i++;
            }
            else
            {
                i = i - len + 1;
                len = 0;
            }
        }
        return len;
    }
};