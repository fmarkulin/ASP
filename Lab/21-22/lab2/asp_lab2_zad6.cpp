#include <iostream>

class Red
{
private:
    static const int MAX = 10;
    double red[MAX];
    int ulaz = 0;
    int izlaz = 0;

public:
    bool dodaj(double broj)
    {
        if((ulaz + 1) % MAX == izlaz)
            return false; //red je pun
        red[ulaz] = broj;
        ulaz = (ulaz + 1) % MAX;
        return true;
    }

    bool skini(double *broj)
    {
        if(ulaz == izlaz)
            return false; //red je prazan
        *broj = red[izlaz];
        izlaz = (izlaz + 1) % MAX;
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