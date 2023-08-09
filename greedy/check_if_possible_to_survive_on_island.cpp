#include <bits/stdc++.h>
using namespace std;
/*
    N – Maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.
*/
int minimumDays(int S, int N, int M)
{
  double req = S * M;
  if ((S - S / 7) * N < req)
    return -1;
  else
    return ceil(req / N);
}
main()
{
  int S = 10, N = 16, M = 2;
  int days = minimumDays(S, N, M);
  if (days != -1)
    cout << "Yes " << days << endl;
  else
    cout << "No" << endl;
}
