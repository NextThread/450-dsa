class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /*    Recursive    */

        if (!head or !(head->next))
        {
            return head;
        }
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;

        /*    Iterative    */

        // ListNode *prev = nullptr, *nextNode;
        // while (head)
        // {
        //     nextNode = head->next;
        //     head->next = prev;
        //     prev = head;
        //     head = nextNode;
        // }
        // return prev;
    }
};