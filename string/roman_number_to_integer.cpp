class Solution
{
public:
    int romanToDecimal(string &str)
    {
        map<char, int> mp;
        mp['M'] = 1000;
        mp['D'] = 500;
        mp['C'] = 100;
        mp['L'] = 50;
        mp['X'] = 10;
        mp['V'] = 5;
        mp['I'] = 1;
        int res = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (mp[str[i]] < mp[str[i + 1]])
                res -= mp[str[i]];
            else
                res += mp[str[i]];
        }
        return res;
    }
};