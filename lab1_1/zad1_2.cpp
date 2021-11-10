#include <iostream>
#include <ctime>
#include <cmath>

int zbrojiKvadrate(int polje[], int n)
{
    if(n == 0)
    {
        return 0;
    }

    int s = sqrt(*polje);
    if ((s * s) == *polje)
    {
        return *polje + zbrojiKvadrate(polje + 1, n - 1);
    }
    else
    {
        return zbrojiKvadrate(polje + 1, n - 1);
    }
}

int main(void)
{
    int n;
    do
    {
        std::cout << "Upišite željeni broj elemenata polja (n): ";
        std::cin >> n;
        if(n < 1)
        {
            std::cout << "Broj elemenata polja (n) mora biti 1 ili veći!" << std::endl;
        }
    } while (n < 1);

    int *A = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        A[i] = rand() % (100 + 1 - 1) + 1;
    }

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    std::cout << "Zbroj članova polja koji su kvadrati nekog drugog prirodnog broja: " << zbrojiKvadrate(A, n) << std::endl;

    delete[] A;

    return 0;
}