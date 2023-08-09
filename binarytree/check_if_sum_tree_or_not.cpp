class Solution
{
public:
    int check(Node *root, bool &ok)
    {
        if (!root)
            return 0;
        int left = check(root->left, ok);
        int right = check(root->right, ok);
        if (!root->left and !root->right)
            return root->data;
        if (left + right != root->data)
            ok = false;
        return left + right + root->data;
    }

    bool isSumTree(Node *root)
    {
        if (!root)
            return true;
        bool ok = true;
        check(root, ok);
        return ok;
    }
};