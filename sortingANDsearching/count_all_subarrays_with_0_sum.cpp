
class Solution
{
public:
    long long int findSubarray(vector<long long int> &arr, int n)
    {
        long long int cnt = 0;
        map<long long int, long long int> mp;
        long long int sum = 0;
        mp[0]++;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            mp[sum]++;
            cnt += mp[sum] - 1;
        }
        return cnt;
    }
};
