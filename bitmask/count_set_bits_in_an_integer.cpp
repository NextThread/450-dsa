class Solution
{
public:
    int setBits(int N)
    {
        // STL
        // return __builtin_popcount(N);
        int cnt = 0;
        while (N)
        {
            if (N & 1)
                cnt++;
            N >>= 1;
        }
        return cnt;
    }
};