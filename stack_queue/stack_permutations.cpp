bool checkStackPermutation(int ip[], int op[], int n)
{
    stack<int> s;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        s.push(ip[i]);
        while (!s.empty() and s.top() == op[j])
        {
            s.pop();
            j++;
        }
    }
    if (s.empty())
        return true;
    return false;
}