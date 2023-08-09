int getNthFromLast(Node *head, int n)
{
  Node *temp = head;
  int len = 0;
  while (temp)
  {
    temp = temp->next;
    len++;
  }
  if (len < n)
    return -1;
  int left = len - n;
  while (left--)
  {
    head = head->next;
  }
  return head->data;
}