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
        if(!newElement)
            return false; // neuspjelo stvaranje novog cvora
        newElement->broj = broj;
        newElement->next = nullptr;
        if(!ulaz)
            izlaz = newElement;
        else
            ulaz->next = newElement;
        ulaz = newElement;
    }

    bool skini(double *broj)
    {
        if(!izlaz)
            return false; // red je prazan
        *broj = izlaz->broj;
        Cvor *temp = izlaz;
        izlaz = izlaz->next;
        if(!izlaz)
            ulaz = nullptr;
        delete temp;
        return true;
    }
};