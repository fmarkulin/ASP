#include <iostream>
#include <iomanip>
#include <cmath>

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

double exp(double x, int n, int *fakt, double *xpot)
{
    if(n < 0)
    {
        return 0;
    }

    return (*xpot) / (*fakt) + exp(x, n - 1, fakt + 1, xpot + 1);
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
            std::cout << "Broj elemenata bolja (n) mora biti 1 ili veći!" << std::endl;
        }
    } while (n < 1);
    
    double x;
    std::cout << "Upišite željenu vrijednost za x: ";
    std::cin >> x;

    double *A = new double[n];

    double *xPot = new double[n];
    for(int i = 0; i < n; i++)
    {
        xPot[i] = pow(x, i);
    }
    std::cout << "Potencije broja x:" << std::endl;
    std::cout << "[";
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << xPot[i] << ", ";
    }
    std::cout << xPot[n - 1] << "]" << std::endl;

    int *nfactorial = new int[n];
    for(int i = 0; i < n; i++)
    {
        nfactorial[i] = factorial(i);
    }
    std::cout << "Faktorijeli broja n:" << std::endl;
    std::cout << "[";
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << nfactorial[i] << ", ";
    }
    std::cout << nfactorial[n - 1] << "]" << std::endl;

    for(int i = 0; i < n; i++)
    {
        A[i] = exp(x, i, nfactorial, xPot);
    }

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    std::cout << std::fixed << std::setprecision(6);
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    delete[] A;
    delete[] xPot;
    delete[] nfactorial;

    return 0;
}