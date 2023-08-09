class Solution
{
public:
    int f(Node *node)
    {
        if (!node)
            return 0;
        int val = node->data;
        node->data = f(node->left) + f(node->right);
        return node->data + val;
    }
    void toSumTree(Node *node)
    {
        f(node);
    }
};