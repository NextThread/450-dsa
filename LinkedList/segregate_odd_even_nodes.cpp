Node *divide(int N, Node *head)
{
  Node *e = new Node(-1), *o = new Node(-1);
  Node *even = e, *odd = o;
  while (head)
  {
    if (((head->data) % 2) == 0)
    {
      e->next = head;
      e = e->next;
    }
    else
    {
      o->next = head;
      o = o->next;
    }
    head = head->next;
  }
  e->next = odd->next;
  o->next = NULL;
  return even->next;
}