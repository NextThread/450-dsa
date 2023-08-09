class Solution
{
public:
  string FirstNonRepeating(string A)
  {
    string ans = "";
    unordered_map<char, int> cnt;
    queue<int> q;
    for (int i = 0; i < A.size(); i++)
    {
      cnt[A[i]]++;
      if (cnt[A[i]] == 1)
      {
        q.push(A[i]);
        ans.push_back(q.front());
      }
      else
      {
        while (!q.empty() && cnt[q.front()] > 1)
          q.pop();
        if (q.empty())
          ans.push_back('#');
        else
          ans.push_back(q.front());
      }
    }
    return ans;
  }
};