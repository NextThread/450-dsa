int minFlips(string S)
{
    int even0 = 0, odd0 = 0, even1 = 0, odd1 = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (S[i] == '0')
                even0++;
            else
                even1++;
        }
        else
        {
            if (S[i] == '0')
                odd0++;
            else
                odd1++;
        }
    }
    return min(even0 + odd1, even1 + odd0);
}