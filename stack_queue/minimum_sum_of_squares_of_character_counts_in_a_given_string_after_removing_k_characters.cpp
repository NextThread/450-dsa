int minValue(string s, int k)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    priority_queue<int> pq;
    for (auto x : mp)
        pq.push(x.second);
    for (int i = 0; i < k; i++)
    {
        int temp = pq.top();
        pq.pop();
        temp -= 1;
        pq.push(temp);
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pow(pq.top(), 2);
        pq.pop();
    }
    return ans;
}