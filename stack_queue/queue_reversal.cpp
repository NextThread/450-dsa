queue<int> rev(queue<int> q)
{
    stack<int> temp;
    while (q.size())
    {
        temp.push(q.front());
        q.pop();
    }
    while (temp.size())
    {
        q.push(temp.top());
        temp.pop();
    }
    return q;
}