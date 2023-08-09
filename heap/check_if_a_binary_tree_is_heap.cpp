int count(struct Node *tree)
{
  if (!tree)
    return 0;
  return (1 + count(tree->left) + count(tree->right));
}

bool solve(struct Node *tree)
{
  if (!tree->left and !tree->right)
    return true;
  if (!tree->left && tree->right)
    return false;
  if (tree->left and !tree->right)
    if (tree->left->left or tree->left->right)
      return false;
    else if (tree->data > tree->left->data)
      return solve(tree->left);
  if (tree->data < tree->left->data or tree->data < tree->right->data)
    return false;
  return (solve(tree->left) && solve(tree->right));
}

bool isHeap(struct Node *tree)
{
  return (solve(tree) && (count(tree->left) >= count(tree->right)));
}