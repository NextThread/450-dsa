class Solution
{
public:
    priority_queue<int> pq;
    void fun(Node *root, int k)
    {
        if (!root)
            return;
        pq.push(root->data);
        if (pq.size() == k + 1)
            pq.pop();
        fun(root->left, k);
        fun(root->right, k);
    }

    int KthSmallestElement(Node *root, int K)
    {
        fun(root, K);
        if (pq.size() < K)
            return -1;
        return pq.top();
    }
};