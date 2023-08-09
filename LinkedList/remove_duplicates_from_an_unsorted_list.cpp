class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        unordered_set<int> seen;

        Node *curr = head;
        if (curr == NULL)
        {
            return head;
        }
        else
        {
            seen.insert(curr->data);
        }

        while (curr != NULL && curr->next != NULL)
        {

            if (seen.find(curr->next->data) != seen.end())
            {
                curr->next = curr->next->next;
            }
            else
            {
                seen.insert(curr->next->data);
                curr = curr->next;
            }
        }
        return head;
    }
};