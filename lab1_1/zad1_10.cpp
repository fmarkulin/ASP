#include <iostream>
#include <cmath>

double f(double z, int k)
{
    if (k < 0)
    {
        return 0;
    }

    if (k == 0)
    {
        return z;
    }

    return (-1 * pow(z, 2) * f(z, k - 1)) / (((2 * k) + 1) * (2 * k));
}

int main(void)
{
    double z = 0.5;

    while(1)
    {
        int k;
        std::cout << "Upišite željenu vrijednost broja k ili broj 1337 za prekid rada programa: ";
        std::cin >> k;
        
        if(k == 1337)
        {
            return 0;
        }

        std::cout << "Rezultat fje: " << f(z, k) << std::endl;
    }
}