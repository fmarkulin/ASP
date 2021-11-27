float kamrac(float g, int n, float p, float rez = 1)
{
    if (n <= 0)
    {
        return g * rez;
    }
    float percentage = (1 + p/100);
    rez = percentage * rez;
    return kamrac(g, n - 1, p, rez);
}