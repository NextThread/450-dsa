void copySetBits(unsigned &x, unsigned y,
                 unsigned l, unsigned r)
{
    // l and r must be between 1 to 32
    // (assuming ints are stored using 32 bits)
    if (l < 1 || r > 32)
        return;
    for (int i = l; i <= r; i++)
    {
        // Find a mask (A number whose
        // only set bit is at i'th position)
        int mask = 1 << (i - 1);

        // If i'th bit is set in y, set i'th
        // bit in x also.
        if (y & mask)
            x |= mask;
    }
}

// 10 ->  1010
// 13 ->  1101
// l = 2, r = 3
// copy 13 setbits into 10
// so,  result ->   1110 -> 11