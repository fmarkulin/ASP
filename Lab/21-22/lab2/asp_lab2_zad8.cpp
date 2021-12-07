#include <iostream>
#include <ctime>

class Red
{
    struct Cvor
    {
        int broj;
        Cvor *next;
    };

    Cvor *ulaz = nullptr;
    Cvor *izlaz = nullptr;

public:
    bool dodaj(int broj)
    {
        Cvor *newElement = new (std::nothrow) Cvor;
        if(!newElement)
            return false; // nije uspjelo stvaranje novog elementa
        newElement->broj = broj;
        newElement->next = nullptr;
        if(ulaz == nullptr)
            izlaz = newElement;
        else
            ulaz->next = newElement;
        ulaz = newElement;
        return true;
    }

    bool poljeURed(int polje[], int n)
    {
        if(n == 0)
        {
            std::cout << "Svi elementi polja dodani su u red." << std::endl;
            return true;
        }
        std::cout << "Dodaje se element: " << polje[n - 1] << std::endl;
        if (!dodaj(polje[n-1]))
        {
            std::cout << "Dodavanje elementa [" << polje[n - 1] << "] nije uspjelo. Prekid rada funkcije..." << std::endl;
            return false;
        }
        return poljeURed(polje, n - 1);
    }
};

int main(void)
{
    srand(time(NULL));

    static const int MAX = 10;
    int *polje = new int[MAX];
    std::cout << "Polje: [";
    for(int i = 0; i < MAX; i++)
    {
        polje[i] = rand() % (10 + 1 - 1) + 1;
        if(i == MAX - 1)
            std::cout << polje[i] << "]" << std::endl;
        else
            std::cout << polje[i] << ", ";
    }

    Red *red = new Red;
    red->poljeURed(polje, MAX);

    delete[] polje;
    delete red;

    return 0;
}