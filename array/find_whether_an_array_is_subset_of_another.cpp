
string isSubset(int a1[], int a2[], int n, int m)
{
    int i = 0, j = 0;
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    int cnt = 0;
    while (i < n and j < m)
    {
        if (a1[i] == a2[j])
            i++, j++, cnt++;
        else if (a1[i] < a2[j])
            i++;
        else
            j++;
    }
    if (cnt == m)
        return "Yes";
    return "No";
}