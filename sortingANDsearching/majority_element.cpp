class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        map<int, int> mp;
        for (int i = 0; i < size; i++)
        {
            mp[a[i]]++;
            if (mp[a[i]] > size / 2)
                return a[i];
        }
        return -1;
    }
};
