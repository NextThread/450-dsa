Node *lca(Node *root, int n1, int n2)
{
    if (!root or root->data == n1 or root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    return !left ? right : !right ? left
                                  : root; // if left return right or if right return left else return root
}