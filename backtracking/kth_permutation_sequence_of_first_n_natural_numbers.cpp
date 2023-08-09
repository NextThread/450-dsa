string kthPermutation(int n, int k)
{
  vector<int> a;
  for (int i = 1; i <= n; i++)
    a.push_back(i);
  vector<vector<int>> v;
  do
  {
    v.push_back(a);
  } while (next_permutation(a.begin(), a.end()));
  vector<int> temp = v[k - 1];
  string res = "";
  for (int i = 0; i < temp.size(); i++)
    res += to_string(temp[i]);
  return res;
}

// optimized

string kthPermutation(int n, int k)
{
  vector<int> temp;
  int fact = 1;
  for (int i = 1; i < n; i++)
  {
    fact *= i;
    temp.push_back(i);
  }
  temp.push_back(n);
  string ans = "";
  k--;
  while (true)
  {
    ans += to_string(temp[k / fact]);
    temp.erase(temp.begin() + k / fact);
    if (temp.size() == 0)
      return ans;
    k = k % fact;
    fact /= temp.size();
  }
  return ans;
}