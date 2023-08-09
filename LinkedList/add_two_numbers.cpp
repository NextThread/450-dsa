ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  if (!l1 and !l2)
    return NULL;
  int a = l1->val + l2->val;
  ListNode *p = new ListNode(a % 10);
  p->next = addTwoNumbers(l1->next, l2->next);
  if (a >= 10)
    p->next = addTwoNumbers(p->next, new ListNode(1));
  return p;
}