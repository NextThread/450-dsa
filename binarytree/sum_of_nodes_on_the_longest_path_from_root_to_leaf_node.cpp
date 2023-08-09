vector<int> longestPath(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> lv = longestPath(root->left);
    vector<int> rv = longestPath(root->right);
    vector<int> res;
    if (lv.size() > rv.size())
        res = lv;
    else
        res = rv;
    res.push_back(root->data);
    return res;
}
int sumOfLongRootToLeafPath(Node *root)
{
    vector<int> res = longestPath(root);
    int sum = 0;
    for (auto it : res)
        sum += it;
    return sum;
}