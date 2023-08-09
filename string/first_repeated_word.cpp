class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int mxfreq = -1;
        for (auto it : mp)
            mxfreq = max(mxfreq, it.second);
        int secondfreq = -1;
        string res = "";
        for (auto it : mp)
        {
            if (it.second != mxfreq && secondfreq < it.second)
            {
                res = it.first;
                secondfreq = it.second;
            }
        }
        return res;
    }
};