class Solution
{
public:
    int count(struct Node *tree)
    {
        if (!tree)
            return 0;
        return (1 + count(tree->left) + count(tree->right));
    }
    bool solve(struct Node *tree)
    {
        if (tree->left == NULL && tree->right == NULL)
            return true;
        if (tree->left != NULL && tree->right == NULL)
            if (tree->left->left || tree->left->right)
                return false;
            else if (tree->data > tree->left->data)
                return solve(tree->left);
        if (tree->left == NULL && tree->right != NULL)
            return false;
        if (tree->data < tree->left->data || tree->data < tree->right->data)
            return false;
        return (solve(tree->left) && solve(tree->right));
    }

    bool isHeap(struct Node *tree)
    {
        return (solve(tree) && (count(tree->left) >= count(tree->right)));
    }
};