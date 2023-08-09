vector<int> reverseLevelOrder(Node *node)
{

    vector<int> v;
    if (!node)
        return v;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        v.push_back(node->data);
        if (node->right)
            q.push(node->right);
        if (node->left)
            q.push(node->left);
    }
    reverse(begin(v), end(v));
    return v;
}