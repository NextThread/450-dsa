// This is same as, count pairs with given sum
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int target = k - arr[i];
            if (mp.find(target) != mp.end())
            {
                cnt += mp[target];
            }
            mp[arr[i]] += 1;
        }
        return cnt;
    }
};