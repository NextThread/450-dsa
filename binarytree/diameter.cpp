class Solution
{
public:
    int f(Node *root, int &dia)
    {
        if (!root)
            return 0;
        int ldia = f(root->left, dia);
        int rdia = f(root->right, dia);
        dia = max(dia, ldia + rdia + 1);
        return max(ldia, rdia) + 1;
    }

    int diameter(Node *root)
    {
        int dia = 0;
        f(root, dia);
        return dia;
    }
};
