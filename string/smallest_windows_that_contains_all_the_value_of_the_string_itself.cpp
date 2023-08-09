class Solution
{
public:
    int smallestKSubstr(string str, int k)
    {
        unordered_map<char, int> mp(26);
        int distinct = 0, res = INT_MAX, i = 0, j = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (mp[str[j]] == 0) // means not present in our map, we just encountered, so it's a distinct character
                distinct++;
            mp[str[j]]++;         // store the current character in the map
            while (distinct == k) // then we need to update the size of the window
            {
                res = min(res, j - i + 1);
                mp[str[i]]--;        // after it decrease one occurence of the character
                if (mp[str[i]] == 0) // means the character has been totally removed from our map, so now distinct charcters decreased by 1
                    distinct--;
                i++;
            }
        }
        return res;
    }

    int findSubString(string str)
    {
        unordered_map<char, int> mp;
        for (char c : str)
            mp[c]++;
        int k = mp.size();
        return smallestKSubstr(str, k);
    }
};