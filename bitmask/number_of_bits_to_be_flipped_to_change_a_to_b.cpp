class Solution
{
public:
    int countBitsFlip(int a, int b)
    {
        a ^= b;
        return __builtin_popcount(a);
    }
};