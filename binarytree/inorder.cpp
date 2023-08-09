class Solution
{
public:
    // recursive
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, res);
        res.push_back(root->val);
        if (root->right)
            inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    // iterative
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (!st.empty() or curr)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};