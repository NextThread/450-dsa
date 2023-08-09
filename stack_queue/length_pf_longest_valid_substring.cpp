class Solution
{
public:
    int findMaxLen(string s)
    {
        int mx = 0, opening = 0, closing = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
                closing++;
            else
                opening++;
            if (opening == closing)
                mx = max(mx, opening + closing);
            else if (closing > opening)
                closing = opening = 0;
        }
        opening = closing = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                closing++;
            else
                opening++;
            if (opening == closing)
                mx = max(mx, opening + closing);
            else if (closing < opening)
                closing = opening = 0;
        }
        return mx;
    }
};