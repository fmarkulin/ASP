#include <iostream>

struct Zapis
{
    int posBroj;
    std::string nazivMjesta;
};

bool operator<(Zapis const &a, Zapis const &b)
{
    return a.posBroj < b.posBroj;
}

void insertionSort(Zapis A[], int n, char smjer)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        Zapis temp = A[i];
        if (smjer == '0')
        {
            for (j = i; j >= 1 && temp < A[j - 1]; j--)
                A[j] = A[j - 1];
        }
        else
        {
            for (j = i; j >= 1 && A[j - 1] < temp; j--)
                A[j] = A[j - 1];
        }
        A[j] = temp;
    }
}

int main(void)
{
    Zapis *zapisi = new Zapis[8];
    for(int i = 0; i < 8; i++)
    {
        Zapis zapis;
        std::cin >> zapis.posBroj;
        std::cin.ignore(1, '\n');
        std::getline(std::cin, zapis.nazivMjesta);
        zapisi[i] = zapis;
    }

    insertionSort(zapisi, 8, '0');

    for(int i = 0; i < 8; i++)
    {
        std::cout << zapisi[i].posBroj << ".|" << zapisi[i].nazivMjesta << std::endl;
    }

    delete[] zapisi;
    return 0;
}