int inSequence(int A, int B, int C)
{
    if (C == 0 && (A == B))
        return 1;
    else if (C == 0)
        return 0;
    if (C < 0)
    {
        if (B > A)
            return 0;
    }
    else
    {
        if (B < A)
            return 0;
    }
    if ((B - A) % C == 0)
        return 1;
    return 0;
}