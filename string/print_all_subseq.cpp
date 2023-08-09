void f(string s, int index, string temp, vector<string> &ans)
{
    if (index == s.length())
    {
        if (temp.length() != 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    f(s, index + 1, temp, ans);
    temp.push_back(s[index]);
    f(s, index + 1, temp, ans);
}

vector<string> subsequences(string str)
{
    int n = str.length();
    vector<string> ans;
    string temp = "";
    f(str, 0, temp, ans);
    return ans;
}
