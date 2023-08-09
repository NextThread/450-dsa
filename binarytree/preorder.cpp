class Solution
{
public:
    // recursive
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->val);
        if (root->left)
            preorder(root->left, v);
        if (root->right)
            preorder(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        preorder(root, v);
        return v;
    }
    // iterative
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (!st.empty() or curr)
        {
            if (curr)
            {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return res;
    }
};