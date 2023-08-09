int square(int num)
{
    if (num < 0)
        num = -num;
    int power = 0, result = 0, temp = num;

    while (temp)
    {
        if (temp & 1)
            result += (num << power);
        power++;
        temp >>= 1;
    }
    return result;
}