class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, v);
        v.push_back(root->data);
        if (root->right)
            inorder(root->right, v);
    }

    bool isBST(Node *root)
    {
        vector<int> v;
        inorder(root, v);
        if (is_sorted(v.begin(), v.end()))
            return true;
        return false;
    }
};
