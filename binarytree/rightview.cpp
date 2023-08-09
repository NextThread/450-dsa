vector<int> rightView(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == size - 1) // for left view change size-1 to 0, rest all same
                res.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
}