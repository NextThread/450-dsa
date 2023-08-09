Node* findIntersection(Node* head1, Node* head2)
{
    Node *temp1 = head1, *temp2 = head2;
    Node *head = new Node(-1);
    Node *tail = head;
    while(temp1 and temp2) {
        if(temp1->data == temp2->data) { // value of both node of two list are same
            tail->next = temp1;
            tail = tail->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data) temp1 = temp1->next; // first list node value is less
        else temp2 = temp2->next; // node value of second list is small
    }
    tail->next = NULL;
    return head->next;
}