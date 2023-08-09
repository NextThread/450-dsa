vector<int> topView(Node *root)
{
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
        if (mp.find(line) == mp.end()) // not in map
        {
            mp[line] = node->data;
        }
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
        res.push_back(it.second);
    return res;
}