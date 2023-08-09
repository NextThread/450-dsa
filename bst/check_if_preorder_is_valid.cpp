class Solution
{
public:
    Node *f(Node *root, int &val)
    {
        if (!root)
            return newNode(val);
        if (root->data < val)
            root->right = f(root->right, val);
        if (root->data > val)
            root->left = f(root->left, val);
        return root;
    }

    Node *post_order(int pre[], int size)
    {
        Node *root = NULL;
        for (int i = 0; i < size; i++)
            root = f(root, pre[i]);
        return root;
    }
};