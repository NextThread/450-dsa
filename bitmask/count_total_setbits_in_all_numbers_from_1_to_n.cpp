class Solution
{
public:
    int countSetBits(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int x = log2(n);
        return (1 << (x - 1)) * x + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};