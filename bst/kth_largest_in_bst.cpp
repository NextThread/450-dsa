class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int f(Node *root, int k)
    {
        if (!root)
            return 0;
        pq.push(root->data);
        if (pq.size() > k)
            pq.pop();
        f(root->left, k);
        f(root->right, k);
    }
    int kthLargest(Node *root, int K)
    {
        f(root, K);
        return pq.top();
    }
};