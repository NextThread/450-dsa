string solve(Node *root, vector<Node *> &ans, unordered_map<string, int> &mp)
{
    if (!root)
        return "N";
    string s = to_string(root->data) + "$" +
               solve(root->left, ans, mp) + "$" +
               solve(root->right, ans, mp);
    if (mp[s]++ == 1)
        ans.push_back(root);
    return s;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> ans;
    unordered_map<string, int> mp;
    solve(root, ans, mp);
    return ans;
}