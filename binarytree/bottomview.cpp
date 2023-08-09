vector<int> bottomView(Node *root)
{
    // same to same code of topview, but in line 14 we are not checking
    // it line exist in out map, for topview we have checked
    vector<int> res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.size())
    {
        auto it = q.front();
        Node *node = it.first;
        q.pop();
        int line = it.second;
        mp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
        res.push_back(it.second);
    return res;
}