class Solution
{
public:
    bool isPowerofTwo(long long n)
    {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};