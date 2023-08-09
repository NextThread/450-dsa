Node *reverseDLL(Node *head)
{
  Node *temp = head, *prev = temp;
  while (temp)
  {
    prev = temp;
    swap(temp->next, temp->prev);
    temp = temp->prev;
  }
  head = prev;
  return head;
}