int maxSubStr(string str, int n)
{
    int zero = 0, one = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            zero++;
        }
        else
        {
            one++;
        }
        if (zero == one)
        {
            cnt++;
        }
    }
    if (zero != one)
    {
        return -1;
    }
    return cnt;
}