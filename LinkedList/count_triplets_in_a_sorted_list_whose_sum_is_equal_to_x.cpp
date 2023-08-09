int countPairs(struct Node *first, struct Node *second, int value)
{
  int count = 0;
  while (first && second && first != second && second->next != first)
  {
    if ((first->data + second->data) == value)
    {
      count++;
      first = first->next;
      second = second->prev;
    }
    else if ((first->data + second->data) > value)
      second = second->prev;
    else
      first = first->next;
  }
  return count;
}

int countTriplets(struct Node *head, int x)
{
  if (!head)
    return 0;
  struct Node *current, *first, *last;
  int count = 0;
  last = head;
  while (last->next)
    last = last->next;
  for (current = head; current != NULL; current = current->next)
  {
    first = current->next;
    count += countPairs(first, last, x - current->data);
  }
  return count;
}