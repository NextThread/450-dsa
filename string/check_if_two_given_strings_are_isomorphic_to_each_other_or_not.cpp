class Solution
{
public:
    bool areIsomorphic(string s1, string s2)
    {
        map<char, int> mp;
        map<char, int> mp2;
        int n = s1.length();
        int m = s2.length();
        if (n != m)
            return false;
        for (int i = 0; i < n; i++)
        {
            mp[s1[i]]++;
            mp2[s2[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[s1[i]] != mp2[s2[i]])
                return false; // if freq level of cur chars not same
            else
            { // decrease both by 1
                mp[s1[i]]--;
                mp2[s2[i]]--;
            }
        }
        return true;
    }
};