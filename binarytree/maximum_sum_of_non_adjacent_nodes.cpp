class Solution
{
public:
    int fun(Node *root, map<Node *, int> &mp)
    {
        if (!root)
            return 0;
        if (mp.find(root) != mp.end())
            return mp[root];
        int inc = 0, exc = 0;
        if (root->left)
        {
            inc += fun(root->left->left, mp);
            inc += fun(root->left->right, mp);
        }
        if (root->right)
        {
            inc += fun(root->right->left, mp);
            inc += fun(root->right->right, mp);
        }
        exc += fun(root->left, mp);
        exc += fun(root->right, mp);
        mp[root] = max(inc + root->data, exc);
        return max(inc + root->data, exc);
    }
    int getMaxSum(Node *root)
    {
        map<Node *, int> m;
        return fun(root, m);
    }
};