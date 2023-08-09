int height(Node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(Node *root)
{
    if (!root)
        return true;
    return isBalanced(root->left) and isBalanced(root->right) and abs(height(root->left) - height(root->right) <= 1);
}