class Solution
{
public:
    bool isIsomorphic(Node *root1, Node *root2)
    {
        if (!root1 and !root2)
            return true;
        if (!root1 or !root2)
            return false;
        if (root1->data != root2->data)
            return false;
        return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) or
               (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
    }
};