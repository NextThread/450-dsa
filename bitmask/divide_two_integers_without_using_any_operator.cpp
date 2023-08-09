long long divide(long long dividend, long long int divisor)
{
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);

    long long quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        ++quotient;
    }

    return quotient * sign;
}