
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        for (auto it : string_list)
        {
            string temp = it;
            sort(it.begin(), it.end());
            mp[it].push_back(temp);
        }
        for (auto it : mp)
            res.push_back(it.second);
        return res;
    }
};