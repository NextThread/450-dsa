vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};
    vector<int> res;
    bool ltr = true;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = i;
            if (!ltr)
                index = size - 1 - i;
            v[index] = temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ltr = !ltr;
        for (int x : v)
            res.push_back(x);
    }
    return res;
}
