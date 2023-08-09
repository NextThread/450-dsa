void push(stack<int> &s, int a)
{
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    return s.empty();
}

int pop(stack<int> &s)
{
    int k = s.top();
    s.pop();
    return k;
}

int getMin(stack<int> &s)
{
    int minn = s.top();
    while (s.size())
    {
        minn = min(minn, s.top());
        s.pop();
    }
    return minn;
}