const long long int mod = 1e9 + 7;
void multi(Node *head, long long &ans)
{
  while (head)
  {
    ans = (ans * 10 + head->data) % mod;
    head = head->next;
  }
}
long long multiplyTwoLists(Node *l1, Node *l2)
{
  // the idea is convert the linkedlist to numbers then multiply both of them and return
  long long ans1 = 0, ans2 = 0;
  multi(l1, ans1);
  multi(l2, ans2);
  return (ans1 * ans2) % mod;
}