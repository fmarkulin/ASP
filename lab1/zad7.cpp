#include <iostream>
#include <cmath>
#include <ctime>

int *randomSquares(int polje[], int n)
{
    int *randomSquaredArray = new int[n];
    bool usedIndexes[n] = {};
    for (int i = 0; i < n; i++)
    {
        int index;
        do
        {
            index = rand() % n;
        } while (usedIndexes[index]);

        randomSquaredArray[i] = pow(polje[index], 2);
        usedIndexes[index] = true;
    }

    return randomSquaredArray;
}

int main(void)
{
    srand(time(NULL));

    int n;
    std::cout << "Upišite željenu veličinu polja: ";
    std::cin >> n;

    int *polje = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Upišite vrijednost " << i << ". elementa: ";
        std::cin >> polje[i];
    }

    std::cout << "Ispis polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            std::cout << polje[i] << "]" << std::endl;
        }
        else
        {
            std::cout << polje[i] << ", ";
        }
    }

    int *randomSquaredArray = randomSquares(polje, n);
    std::cout << "Nasumično kvadrirano polje:";
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            std::cout << randomSquaredArray[i] << "]" << std::endl;
        }
        else
        {
            std::cout << randomSquaredArray[i] << ", ";
        }
    }

    delete[] polje;
    delete[] randomSquaredArray;

    return 0;
}