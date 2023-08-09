void solve(stack<int> &s, int val)
{
    if (s.empty() || (!s.empty() and s.top() < val))
    {
        s.push(val);
        return;
    }
    int x = s.top();
    s.pop();
    solve(s, val);
    s.push(x);
}
void SortedStack ::sort()
{
    if (s.empty())
        return;
    int t = s.top();
    s.pop();
    sort();
    solve(s, t);
}