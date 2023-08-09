void inorder(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void solve(Node *root, vector<int> &v, int &ind)
{
    if (!root)
        return;
    solve(root->left, v, ind);
    root->data = v[ind++];
    solve(root->right, v, ind);
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> v;
    inorder(root, v);
    int ind = 0;
    sort(v.begin(), v.end());
    solve(root, v, ind);
    return root;
}