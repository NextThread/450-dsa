Node *removeDuplicates(Node *head)
{
    if (!head)
        return NULL;
    Node *curr = head;
    while (curr->next)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}