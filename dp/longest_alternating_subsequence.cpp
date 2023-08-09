class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &a)
    {
        int n = a.size();
        int asc = 0, des = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1])
                asc = des + 1;
            else if (a[i] > a[i + 1])
                des = asc + 1;
        }
        return max(asc, des) + 1;
    }
};