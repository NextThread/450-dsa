class Solution
{
public:
    void f(Node *root, vector<pair<int, int>> &res, int level)
    {
        if (!root)
            return;
        else if (!root->left and !root->right)
            res.push_back({root->data, level});
        f(root->left, res, level + 1);
        f(root->right, res, level + 1);
    }
    bool check(Node *root)
    {
        vector<pair<int, int>> res;
        f(root, res, 0);
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i].second != res[i + 1].second)
                return false;
        }
        return true;
    }
};