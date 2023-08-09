bool isCircular(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == head)
            return true;
        temp = temp->next;
    }
    return false;
}