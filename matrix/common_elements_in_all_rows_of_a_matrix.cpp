#include <bits/stdc++.h>
using namespace std;
#define N 5

void printCommonElements(int mat[N][N])
{
    unordered_map<int, int> mp;
    for (int j = 0; j < N; j++)
    {
        mp[mat[0][j]] = 1; // insert the first row elements in the map
    }

    for (int i = 1; i < N; i++) // ignore first row, as it has been used earlier
    {
        for (int j = 0; j < N; j++)
        {
            if (mp.find(mat[i][j]) != mp.end()) // if the element is present in our map
            {
                mp[mat[i][j]]++;
                if (i == N - 1 && mp[mat[i][j]] == N)
                    cout << mat[i][j] << " ";
            }
        }
    }
}

int main()
{
    int mat[N][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 1, 9},
            {9, 9, 0, 6, 5}};

    printCommonElements(mat);
    return 0;
}
