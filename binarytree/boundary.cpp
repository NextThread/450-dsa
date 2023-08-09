class Solution
{
public:
    bool isleaf(Node *root)
    {
        return !root->left and !root->right;
    }

    void leftboundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isleaf(curr))
            {
                res.push_back(curr->data);
            }
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    void rightboundary(Node *root, vector<int> &res)
    {
        vector<int> temp;
        Node *curr = root->right;
        while (curr)
        {
            if (!isleaf(curr))
            {
                temp.push_back(curr->data);
            }
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }

    void addleaf(Node *root, vector<int> &res)
    {
        Node *curr = root;
        if (isleaf(curr))
        {
            res.push_back(curr->data);
            return;
        }
        if (curr->left)
        {
            addleaf(curr->left, res);
        }
        if (curr->right)
        {
            addleaf(curr->right, res);
        }
    }

    vector<int> boundary(Node *root)
    {
        if (!root)
            return {};
        vector<int> res;
        if (!isleaf(root))
            res.push_back(root->data);
        leftboundary(root, res);
        addleaf(root, res);
        rightboundary(root, res);
        return res;
    }
};