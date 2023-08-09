class Solution
{
public:
    void removeLoop(Node *head)
    {
        //    we mark every data as -1 that means we checked previously
        //    if( temp->next->data == -1) then there is loop and we set temp->next=NULL
        Node *temp = head;
        while (temp->data != -1 && temp->next != NULL)
        {
            if (temp->next->data == -1)
            {
                break;
            }
            temp->data = -1;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            return;
        }
        else if (temp->next->data == -1)
        {
            temp->next = NULL;
        }
    }
};