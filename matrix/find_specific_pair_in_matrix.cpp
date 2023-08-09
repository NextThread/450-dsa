int findMaxValue(int mat[][N])
{
    int maxValue = INT_MIN; // find max value of mat[d][c]-mat[a][b] where a<c and b<d
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            for (int d = a + 1; d < N; d++)
                for (int c = b + 1; c < N; c++)
                    if (maxValue < (mat[d][c] - mat[a][b]))
                        maxValue = mat[d][c] - mat[a][b];

    return maxValue;
}