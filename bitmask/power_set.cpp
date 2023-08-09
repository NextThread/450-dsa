class Solution
{
public:
    void f(int i, string &s, vector<string> &res, string cur)
    {
        if (i == s.length())
        {
            res.push_back(cur);
            return;
        }
        f(i + 1, s, res, cur);
        f(i + 1, s, res, cur + s[i]);
    }

    vector<string> AllPossibleStrings(string s)
    {
        vector<string> res;
        f(0, s, res, "");
        sort(res.begin(), res.end());
        res.erase(res.begin());
        return res;
    }
};