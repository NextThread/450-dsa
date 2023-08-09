bool areAnagrams(Node *root1, Node *root2)
{
    if (!root1 and !root2)
        return true;
    if (!root1 or !root2)
        return false;
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (true)
    {
        int n1 = q1.size(), n2 = q2.size();
        if (n1 != n2)
            return false;
        if (n1 == 0 or n2 == 0)
            return true;
        vector<int> curr_level1, curr_level2;
        while (n1)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;
            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }
        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
        if (curr_level1 != curr_level2)
            return false;
    }
    return true;
}