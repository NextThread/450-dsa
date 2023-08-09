int tour(petrolPump p[], int n)
{
    int balance = 0, start = 0, need = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            need += balance;
            start = i + 1;
            balance = 0;
        }
    }
    return (need + balance >= 0) ? start : -1;
}