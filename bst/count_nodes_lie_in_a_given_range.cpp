class Solution
{
public:
    void f(Node *root, int l, int h, int &cnt)
    {
        if (!root)
            return;
        if (root->data >= l and root->data <= h)
        {
            cnt++;
            if (root->data > l)
                f(root->left, l, h, cnt);
            if (root->data < h)
                f(root->right, l, h, cnt);
        }
        else if (root->data < l)
        {
            f(root->right, l, h, cnt);
        }
        else
        {
            f(root->left, l, h, cnt);
        }
    }

    int getCount(Node *root, int l, int h)
    {
        int cnt = 0;
        f(root, l, h, cnt);
        return cnt;
    }
};