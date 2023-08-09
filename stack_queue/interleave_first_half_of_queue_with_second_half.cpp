void interLeaveQueue(queue<int> &q)
{
    if (q.size() & 1)
        return 0;
    stack<int> s;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front()); // Push the first half elements of the queue to stack.
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top()); // Enqueue back the stack elements.
        s.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front()); // Dequeue the first half elements of the queue and enqueue them back.
        q.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front()); // Again push the first half elements into the stack.
        q.pop();
    }
    while (!s.empty())
    {
        // Interleave the elements of queue and stack.
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
