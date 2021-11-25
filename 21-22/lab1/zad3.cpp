#include <iostream>
#include <cmath>
#include <iomanip>

double pi(int n) //sum k=1->n od (-1)^n+1 * 1/(2n-1)
{
    if (n == 1)
    {
        return 4;
    }
    return 4 * pow(-1, n + 1) * (1. / (2 * n - 1)) + pi(n - 1);
}

int main(void)
{
    int n;
    do
    {
        std::cout << "Upišite željenu veličinu polja: ";
        std::cin >> n;
        if (n <= 0)
        {
            std::cout << "Veličina polja mora biti veća od 0!" << std::endl;
        }
    } while (n <= 0);

    double *A = new double[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = pi(i + 1);
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

    delete[] A;

    return 0;
}