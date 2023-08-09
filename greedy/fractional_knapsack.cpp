static bool cmp(struct Item a, struct Item b)
{
  double r1 = (double)a.value / (double)a.weight;
  double r2 = (double)b.value / (double)b.weight;
  return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int N)
{
  sort(arr, arr + N, cmp);
  double finalvalue = 0.0;
  for (int i = 0; i < N; i++)
  {
    if (arr[i].weight <= W)
    {
      W -= arr[i].weight;
      finalvalue += arr[i].value;
    }
    else
    {
      finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
      break;
    }
  }
  return finalvalue;
}