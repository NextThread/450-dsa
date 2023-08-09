class MyQueue
{
public:
    stack<int> in;
    stack<int> out;
    MyQueue()
    {
        in = stack<int>();
        out = stack<int>();
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int val = out.top();
        out.pop();
        return val;
    }

    int peek()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty()
    {
        return out.empty() && in.empty();
    }
};