#include <iostream>
#include <iomanip>
#include <cmath>

double pi(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return 4 * (pow(-1., n + 1) / (2 * n - 1)) + pi(n - 1);
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

    double *A = new double[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = pi(i + 1);
    }

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    delete[] A;

    return 0;
}