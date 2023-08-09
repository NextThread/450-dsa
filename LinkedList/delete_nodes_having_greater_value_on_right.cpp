Node *DeleteNodesOnRight(Node *head)
{
  if (!head or !head->next)
    return head;
  head->next = DeleteNodesOnRight(head->next);
  if (head->next->data > head->data)
    return head->next;
  return head;
}