int kvazi_binomni(int n, int m)
{
    if (n == m)
    {
        return kvazi_binomni(n, 0);
    }

    if (n < 0 || m > n)
    {
        return 0;
    }

    if(m == 0)
    {
        return 1;
    }

    return kvazi_binomni(n - 1, m - 1) + m * kvazi_binomni(n - 1, m + 1);
}