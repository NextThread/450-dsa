bool isPalindrome(Node *head)
{
  stack<int> st;
  Node *temp = head;
  while (temp != NULL)
  {
    st.push(temp->data);
    temp = temp->next;
  }

  while (head != NULL)
  {
    if (head->data != st.top())
    {
      return false;
    }
    head = head->next;
    st.pop();
  }
  return true;
}