class Solution
{
public:
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here
        sort(A, A + n);
        int target = X;
        for (int i = 0; i < n; i++)
        {
            int target2 = target - A[i];
            // now we have to apply 2 sum and consider target as target2
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                if (A[lo] + A[hi] == target2)
                    return 1;
                else if (A[lo] + A[hi] > target2)
                    hi -= 1;
                else
                    lo += 1;
            }
        }
        return 0;
    }
};