#include <iostream>

void ispis(float polje[], int n)
{
    if (n == 0)
    {
        //polje veličine 0, kraj
        return;
    }

    if (*polje < 0)
    {
        if (n == 1)
        {
            std::cout << *polje << std::endl;
        }
        else
        {
            std::cout << *polje << ", ";
        }
    }

    return ispis(polje + 1, n - 1);
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

    float *A = new float[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Upišite vrijednost " << i << ". elementa polja: ";
        std::cin >> A[i];
    }

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    ispis(A, n);

    delete[] A;

    return 0;
}