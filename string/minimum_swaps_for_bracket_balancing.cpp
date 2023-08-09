class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        int openBrackets = 0;
        int closeBrackets = 0;
        int ans = 0;
        for (char ch : S)
        {
            if (ch == ']')
            {
                closeBrackets++;
            }
            else
            {
                if (closeBrackets > openBrackets)
                {
                    ans += closeBrackets - openBrackets;
                }
                openBrackets++;
            }
        }
        return ans;
    }
};