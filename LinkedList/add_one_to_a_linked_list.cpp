Node *addOne(Node *head)
{
  Node *temp = head;
  long long int sum = 0;
  while (temp)
  {
    sum = (long long int)sum * 10 + temp->data;
    temp = temp->next;
  }
  head->data = sum + 1;
  head->next = NULL;
  return head;
}