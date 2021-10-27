#include <iostream>
#include <ctime>
#include <cmath>

int zbrojiKvadrate(int polje[], int n)
{
    if (n < 0)
    {
        return 0;
    }

    int s = sqrt(polje[n - 1]);
    if ((s * s) == polje[n - 1])
    {
        return zbrojiKvadrate(polje, n - 1) + polje[n - 1] + 0;
    }
    else
    {
        return zbrojiKvadrate(polje, n - 1) + 0;
    }
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

    int *A = new int[n]();
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 + 1;
    }

    //provjera polja - ispis
    std::cout << "Ispis polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    std::cout << "Zbroj kvadrata: " << zbrojiKvadrate(A, n) << std::endl;

    delete[] A;

    return 0;
}