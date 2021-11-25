#include <iostream>
#include <ctime>
#include <cmath>

int *kvadriranoNasumicno(int *polje, int n)
{
    int *novoPolje = new int[n];
    bool usedIndexes[n] = {};
    for (int i = 0; i < n; i++)
    {
        int index;
        do
        {
            index = rand() % ((n - 1) + 1 - 0) + 0;
        } while (usedIndexes[index]);

        novoPolje[i] = pow(polje[index], 2);
        usedIndexes[index] = 1;
    }
    return novoPolje;
}

int main(void)
{
    srand(time(NULL));

    int n;
    do
    {
        std::cout << "Upišite željeni broj elemenata polja (n) :";
        std::cin >> n;
        if (n < 1)
        {
            std::cout << "Broj elemenata polja (n) mora biti 1 ili veći!" << std::endl;
        }
    } while (n < 1);

    int *polje = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Upišite vrijednost za " << i << ". element polja: ";
        std::cin >> polje[i];
    }

    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << polje[i] << ", ";
    }
    std::cout << polje[n - 1] << "]" << std::endl;

    int *novoPolje = kvadriranoNasumicno(polje, n);

    std::cout << "Sadržaj novog polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << novoPolje[i] << ", ";
    }
    std::cout << novoPolje[n - 1] << "]" << std::endl;

    delete[] polje;
    delete[] novoPolje;

    return 0;
}