class Solution {
public:
    int minValue(Node* root) {
        if(!root) return -1;
        while(root->left) {
            root = root->left;
        }
        return root->data;
    }
};