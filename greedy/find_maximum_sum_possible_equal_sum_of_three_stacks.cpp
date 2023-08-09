int maxEqualSum(int n1, int n2, int n3, vector<int> &stack1, vector<int> &stack2, vector<int> &stack3)
{
  int sum1 = accumulate(begin(stack1), end(stack1), 0);
  int sum2 = accumulate(begin(stack2), end(stack2), 0);
  int sum3 = accumulate(begin(stack3), end(stack3), 0);
  int top1 = 0, top2 = 0, top3 = 0;
  while (1)
  {
    if (top1 == n1 || top2 == n2 || top3 == n3)
      return 0;
    if (sum1 == sum2 && sum2 == sum3)
      return sum1;
    if (sum1 >= sum2 && sum1 >= sum3)
      sum1 -= stack1[top1++];
    else if (sum2 >= sum1 && sum2 >= sum3)
      sum2 -= stack2[top2++];
    else if (sum3 >= sum2 && sum3 >= sum1)
      sum3 -= stack3[top3++];
  }
}