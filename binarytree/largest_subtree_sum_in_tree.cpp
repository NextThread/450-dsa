int findLargestSubtreeSumUtil(Node *root, int &res)
{
    if (!root)
        return 0;
    int currSum = root->key + findLargestSubtreeSumUtil(root->left, res) + findLargestSubtreeSumUtil(root->right, res);
    res = max(res, currSum);
    return currSum;
}

int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;
    int res = INT_MIN;
    findLargestSubtreeSumUtil(root, res);
    return res;
}