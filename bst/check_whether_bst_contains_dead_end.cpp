bool helper(Node *root, int l, long int r)
{
    if (!root)
        return false;
    if (l == root->data - 1 and r == root->data + 1)
        return true;
    return helper(root->left, l, root->data) or helper(root->right, root->data, r);
}

bool isDeadEnd(Node *root)
{
    return helper(root, 0, INT_MAX);
}