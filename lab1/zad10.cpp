#include <iostream>
#include <cmath>

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return factorial(n - 1) * n;
}

double f (double z, int k)
{
    if(k < 0)
        return 0;

    return (pow(-1, k) * pow(z, (2 * k) + 1)) / factorial((2 * k) + 1);
}

int main(void)
{
    double z = 0.5;
    while(true)
    {
        int k;
        std::cout << "Upišite željenu vrijednost za k ili broj 42069 za prekid rada programa: ";
        std::cin >> k;
        
        if(k == 42069)
        {
            break;
        }

        if(k < 0)
        {
            std::cout << "Molim upišite broj >= 0!";
            continue;
        }

        std::cout << "f = " << f(z, k) << std::endl; 
    }
    
    return 0;
}