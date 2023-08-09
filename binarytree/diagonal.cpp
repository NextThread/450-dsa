vector<int> diagonal(Node *root)
{
    vector<int> res;
    queue<Node *> q;
    if (!root)
        return {};
    q.push(root);
    while (q.size())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            res.push_back(temp->data);
            temp = temp->right;
        }
    }
    return res;
}