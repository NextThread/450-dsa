#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
// n is number of computers in cafe.
// 'seq' is given sequence of customer entry, exit events
int runCustomerSimulation(int n, const char *seq)
{
  // seen[i] = 0, indicates that customer 'i' is not in cafe
  // seen[1] = 1, indicates that customer 'i' is in cafe but
  //			 computer is not assigned yet.
  // seen[2] = 2, indicates that customer 'i' is in cafe and
  //			 has occupied a computer.
  char seen[MAX_CHAR] = {0};
  int res = 0;

  int occupied = 0;
  for (int i = 0; seq[i]; i++)
  {
    int ind = seq[i] - 'A';
    // If First occurrence of 'seq[i]'
    if (seen[ind] == 0)
    {
      // set the current character as seen
      seen[ind] = 1;
      // If number of occupied computers is less than
      // n, then assign a computer to new customer
      if (occupied < n)
      {
        occupied++;

        // Set the current character as occupying a computer
        seen[ind] = 2;
      }
      // Else this customer cannot get a computer,
      // increment result
      else
        res++;
    }
    // If this is second occurrence of 'seq[i]'
    else
    {
      // Decrement occupied only if this customer
      // was using a computer
      if (seen[ind] == 2)
        occupied--;
      seen[ind] = 0;
    }
  }
  return res;
}
main()
{
  cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
  cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
}
