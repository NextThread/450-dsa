int intersectPoint(Node *head1, Node *head2)
{
    Node *l1 = head1;
    Node *l2 = head2;
    while (l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next;
        if (l1 == NULL)
            l1 = head2;
        if (l2 == NULL)
            l2 = head1;
    }
    return l1->data;
}