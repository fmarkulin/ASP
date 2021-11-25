#include <iostream>
#include <cmath>

double f (double z, int k)
{
    if(k < 0)
        return 0;

    if(k == 0)
        return z;
    
    return (-1 * pow(z, 2) * f(z, k - 1)) / (((2 * k) + 1) * (2 * k));
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