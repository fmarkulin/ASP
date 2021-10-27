#include <iostream>

void ispis(float polje[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (polje[i] < 0)
        {
            std::cout << polje[i] << std::endl;
            break;
        }
    }
    if (i < n)
    {
        ispis(polje + (i + 1), n - (i + 1));
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

    float *A = new float[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Upišite vrijednost " << i << ". elementa: ";
        std::cin >> A[i];
    }

    //provjera polja - ispis
    std::cout << "Ispis polja:" << std::endl;
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