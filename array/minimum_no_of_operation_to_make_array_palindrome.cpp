
class Solution
{
public:
    bool ispalin(int n)
    {
        int rev = 0, temp = n;
        while (temp)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == n;
    }

    int PalinArray(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!ispalin(a[i]))
                return 0;
        }
        return 1;
    }
};