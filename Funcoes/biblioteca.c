int Potencialint(const int base, const int expoente)
{
    int result = 1;
    for (int i = 0; i < expoente; i++)
    {
        result *= base;
    }
    return result;
}