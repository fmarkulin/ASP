#include <iostream>
#include <cmath>
#include <iomanip>

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

double exp(double x, int n, int *fakt, double *xpot) //sum k=0 -> n od (x^k)/k!
{
    if (n < 0)
        return 0;

    return (*xpot) / (*fakt) + exp(x, n - 1, fakt + 1, xpot + 1);
}

int main(void)
{
    int n;
    std::cout << "Upišite željenu veličinu polja: ";
    std::cin >> n;

    double x;
    std::cout << "Upišite željenu vrijednost broja x: ";
    std::cin >> x;

    // if (n > 0)
    // {
    int *nFactorial = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        nFactorial[i] = factorial(i);
    }
    std::cout << "Ispis faktorijela:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << nFactorial[i] << ", ";
    }
    std::cout << nFactorial[n] << "]" << std::endl;

    double *xPot = new double[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        xPot[i] = pow(x, i);
    }
    std::cout << "Ispis potencija:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << xPot[i] << ", ";
    }
    std::cout << xPot[n] << "]" << std::endl;

    double *A = new double[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        A[i] = exp(x, i, nFactorial, xPot);
    }
    std::cout << "Ispis polja:" << std::endl;
    std::cout << "[";
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n] << "]" << std::endl;

    delete[] nFactorial;
    delete[] xPot;
    delete[] A;
    // }
    // else
    // {
    //     int nFactorial = 1;
    //     std::cout << "Ispis faktorijela:" << std::endl;
    //     std::cout << "[" << nFactorial << "]" << std::endl;

    //     double xPot = 1;
    //     std::cout << "Ispis potencija:" << std::endl;
    //     std::cout << "[" << xPot << "]" << std::endl;

    //     double A = exp(x, n, &nFactorial, &xPot);
    //     std::cout << std::fixed;
    //     std::cout << std::setprecision(6);
    //     std::cout << "Ispis polja:" << std::endl;
    //     std::cout << "[" << A << "]" << std::endl;
    // }

    return 0;
}