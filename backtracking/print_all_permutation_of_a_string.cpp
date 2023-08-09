class Solution
{
public:
  vector<string> find_permutation(string S)
  {
    vector<string> res;
    sort(S.begin(), S.end());
    do
    {
      res.push_back(S);
    } while (next_permutation(S.begin(), S.end()));
    sort(res.begin(), res.end());
    return res;
  }
};