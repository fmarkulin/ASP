#include <iostream>

class Red
{
    struct Cvor
    {
        double broj;
        Cvor *next;
    };

    Cvor *ulaz = nullptr;
    Cvor *izlaz = nullptr;

public:
    bool dodaj(double broj)
    {
        Cvor *newElement = new (std::nothrow) Cvor;
        if (!newElement)
            return false; // neuspjelo stvaranje novog cvora
        newElement->broj = broj;
        newElement->next = nullptr;
        if (!ulaz)
            izlaz = newElement;
        else
            ulaz->next = newElement;
        ulaz = newElement;
        return true;
    }

    bool skini(double *broj)
    {
        if (!izlaz)
            return false; // red je prazan
        Cvor *temp = izlaz;
        *broj = izlaz->broj;
        izlaz = izlaz->next;
        if (!izlaz)
            ulaz = nullptr;
        delete temp;
        return true;
    }

    bool poljeURed(int polje[], int n)
    {
        if(n == 0)
            return true; // dodano cijelo polje
        std::cout << "Dodajem element: " << polje[n - 1] << std::endl;
        if(!dodaj(polje[n - 1]))
        {
            std::cout << "Neuspjelo dodavanje elementa!" << std::endl;
            return false;
        }
        return poljeURed(polje, n - 1);
    }
};