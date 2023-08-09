int LISS(node *root)
{

    //          This is nothing but, LIS in a binary tree

    if (!root)
        return 0;

    // Calculate size excluding the current node
    int size_excl = LISS(root->left) +
                    LISS(root->right);

    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);

    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}