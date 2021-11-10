#include <iostream>
#include <cmath>

void f(int polje[], int n, int m)
{
    if(n == 0)
    {
        return;
    }

    polje[n - 1] = pow(m, n - 1);
    return f(polje, n - 1, m);
}

int main(void)
{
    int n;
    do
    {
        std::cout << "Upišite željeni broj elemenata polja (n): ";
        std::cin >> n;
        if (n < 1)
        {
            std::cout << "Broj elemenata polja (n) mora biti 1 ili veći!" << std::endl;
        }
    } while (n < 1);

    int m;
    std::cout << "Upišite željenu vrijednost za m: ";
    std::cin >> m;

    int *polje = new int[n];
    f(polje, n, m);

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << polje[i] << ", ";
    }
    std::cout << polje[n - 1] << "]" << std::endl;

    delete[] polje;

    return 0;
}