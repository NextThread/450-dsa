class Solution
{
public:
    int height(Node *root, int a)
    {
        if (!root)
            return -1;
        if (root->data == a)
            return 0;
        int lh = height(root->left, a);
        int rh = height(root->right, a);
        if (lh == -1 && rh == -1)
            return -1;
        return 1 + max(lh, rh);
    }
    Node *lca(Node *root, int n1, int n2)
    {
        if (!root or root->data == n1 or root->data == n2)
            return root;
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        return !left ? right : !right ? left
                                      : root;
    }
    int findDist(Node *root, int a, int b)
    {
        Node *llccaa = lca(root, a, b);
        if (!llccaa)
            return 0;
        int l = height(llccaa, a);
        int r = height(llccaa, b);
        if (l == -1 || r == -1)
            return 0;
        return l + r;
    }
};