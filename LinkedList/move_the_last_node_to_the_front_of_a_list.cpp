void moveToFront(ListNode *head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    ListNode *secLast = NULL;
    ListNode *last = *head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;

    last->next = *head;

    *head = last;
}