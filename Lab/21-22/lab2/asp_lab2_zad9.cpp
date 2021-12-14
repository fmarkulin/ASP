#include <iostream>

struct Zapis
{
    int posBroj;
    std::string nazivMjesta;
};

bool operator<(const Zapis &a, const Zapis &b)
{
    return a.posBroj < b.posBroj;
}

bool operator>(const Zapis &a, const Zapis &b)
{
    return a.posBroj > b.posBroj;
}

void insertionSort(Zapis A[], int n, char smjer)
{
    if (smjer == '0')
    { // uzlazno sortiranje
        Zapis temp;
        for (int i = 1; i < n; i++)
        {
            temp = A[i];
            int j;
            for (j = i; j >= 1 && A[j - 1] > temp; j--)
                A[j] = A[j - 1];
            A[j] = temp;
        }
    }
    else
    {
        Zapis temp;
        for (int i = 1; i < n; i++)
        {
            temp = A[i];
            int j;
            for (j = i; j >= 1 && A[j - 1] < temp; j--)
                A[j] = A[j - 1];
            A[j] = temp;
        }
    }
}

int main(void)
{
    int n;
    std::cout << "Upisite broj koliko zapisa zelite unijeti: ";
    std::cin >> n;

    Zapis *A = new Zapis[n];
    for (int i = 0; i < n; i++)
    {
        Zapis zapis;
        std::cout << "Upisite postanski broj mjesta: ";
        std::cin >> zapis.posBroj;
        std::cin.ignore(1, '\n');
        std::cout << "Upisite naziv mjesta: ";
        std::getline(std::cin, zapis.nazivMjesta);
        A[i] = zapis;
    }

    char smjer;
    std::cout << "Upišite smjer sortiranja: ";
    std::cin >> smjer;

    insertionSort(A, n, smjer);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            std::cout << A[i].posBroj << ":" << A[i].nazivMjesta << std::endl;
            break;
        }
        std::cout << A[i].posBroj << ":" << A[i].nazivMjesta <<  " | ";
    }

    return 0;
}