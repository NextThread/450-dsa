class Solution
{
public:
    int findPosition(int N)
    {
        if (N == 0)
            return -1;
        if (__builtin_popcount(N) > 1)
            return -1;
        return log2(N) + 1;
    }
};