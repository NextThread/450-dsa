// This problem is also name as,  Brother from different roots

void inorder(Node *root, unordered_set<int> &st)
{
    if (!root)
        return;
    inorder(root->left, st);
    st.insert(root->data);
    inorder(root->right, st);
}
int countPairs(Node *root1, Node *root2, int x)
{
    unordered_set<int> mp1, mp2;
    inorder(root1, mp1);
    inorder(root2, mp2);
    int count = 0;
    for (auto it : mp1)
    {
        if (mp2.find(x - it) != mp2.end())
            count++;
    }
    return count;
}