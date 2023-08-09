class Solution
{
public:
    // recursive
    void postorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left)
            postorder(root->left, res);
        if (root->right)
            postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    // iterative
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> s1, s2;
        vector<int> vec;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            if (root->left)
                s1.push(root->left);
            if (root->right)
                s1.push(root->right);
            s2.push(root);
        }
        while (!s2.empty())
        {
            vec.push_back(s2.top()->val);
            s2.pop();
        }
        return vec;
    }
};