class Solution
{
public:
    // This is the exact same of Invert a Binary Tree
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};