class Solution
{
public:
    string f(Node *root, map<string, int> &mp)
    {
        if (!root)
            return "";
        string ls = f(root->left, mp);
        string rs = f(root->right, mp);
        string temp = ls + root->data + rs;
        if (temp.size() > 1)
            mp[temp] += 1;
        return temp;
    }
    int dupSub(Node *root)
    {
        map<string, int> mp;
        f(root, mp);
        for (auto it : mp)
        {
            if (it.first.size() > 1 and it.second >= 2)
                return 1;
        }
        return 0;
    }
};