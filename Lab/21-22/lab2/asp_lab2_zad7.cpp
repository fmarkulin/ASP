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
            return false; // neuspjelo stvaranje novog elementa
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
        *broj = izlaz->broj;
        Cvor *tmp = izlaz;
        izlaz = izlaz->next;
        if(!izlaz)
            ulaz = nullptr;
        delete tmp;
        return true;
    }
};

int main(void)
{
    int n;
    std::cout << "Upišite željeni broj upisa elemenata u red: ";
    std::cin >> n;

    Red *red = new Red;

    for(int i = 0; i < n; i++)
    {
        double element;
        std::cout << "Upišite " << i + 1 << ". element: ";
        std::cin >> element;
        red->dodaj(element);
    }

    std::cout << "Brisanje elemenata iz reda..." << std::endl;
    for(int i = 0; i < n; i++)
    {
        double element;
        red->skini(&element);
        std::cout << i + 1 << ".| " << element << std::endl;
    }

    delete red;

    return 0;
}