#include <iostream>
#include <cmath>

void f (int polje[], int n, int m)
{
    if(n == 0)
    {
        return;
    }

    polje[n - 1] = pow(m, (n - 1));
    f(polje, n - 1, m);
}

int main(void)
{
    int n;
    std::cout << "Upišite željenu veličinu polja: ";
    std::cin >> n;

    int m;
    std::cout << "Upišite željenu vrijednost za m: ";
    std::cin >> m;

    int* polje = new int[n];
    f(polje, n, m);
    
    std::cout << "Ispis polja: " << std::endl;
    std::cout << "[";
    for(int i = 0; i < n; i++)
    {
        if(i == (n - 1))
        {
            std::cout << polje[i] << "]" << std::endl;
        }
        else
        {
            std::cout << polje[i] << ", ";
        }
    }

    delete[] polje;

    return 0;
}