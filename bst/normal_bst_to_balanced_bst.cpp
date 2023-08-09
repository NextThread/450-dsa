class Solution
{
    vector<TreeNode *> sorted;

public:
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        sorted.push_back(root);
        inorder(root->right);
    }

    TreeNode *createTree(int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (end - start) / 2 + start;
        TreeNode *root = sorted[mid];
        root->left = createTree(start, mid - 1);
        root->right = createTree(mid + 1, end);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return createTree(0, sorted.size() - 1);
    }
};