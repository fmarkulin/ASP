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
    do
    {
        std::cout << "Upišite željenu veličinu polja: ";
        std::cin >> n;
        if(n < 1)
            std::cout << "Upisani n je manji od 1!" << std::endl;
    } while (n < 1);

    double x;
    std::cout << "Upišite željenu vrijednost broja x: ";
    std::cin >> x;

    int *nFactorial = new int[n];
    for (int i = 0; i < n; i++)
    {
        nFactorial[i] = factorial(i);
    }
    std::cout << "Ispis faktorijela:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << nFactorial[i] << ", ";
    }
    std::cout << nFactorial[n - 1] << "]" << std::endl;

    double *xPot = new double[n];
    for (int i = 0; i < n; i++)
    {
        xPot[i] = pow(x, i);
    }
    std::cout << "Ispis potencija:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << xPot[i] << ", ";
    }
    std::cout << xPot[n - 1] << "]" << std::endl;

    double *A = new double[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = exp(x, i, nFactorial, xPot);
    }
    std::cout << "Ispis polja:" << std::endl;
    std::cout << "[";
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    delete[] nFactorial;
    delete[] xPot;
    delete[] A;

    return 0;
}