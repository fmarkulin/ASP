#include <iostream>

class Red
{
    static const int MAX = 10;
    int red[MAX];
    int ulaz = 0;
    int izlaz = 0;

public:
    bool dodaj(double broj)
    {
        if((ulaz + 1) % MAX == izlaz)
            return false; // red je pun
        red[ulaz] = broj;
        ulaz = (ulaz + 1) % MAX;
        return true;
    }

    bool skini(double *broj)
    {
        if(ulaz == izlaz)
            return false; // red je prazan
        *broj = red[izlaz];
        izlaz = (izlaz + 1) % MAX;
        return true;
    }
};

int main(void)
{
    int n;
    std::cout << "n: ";
    std::cin >> n;

    Red *red = new Red;
    for(int i = 0; i < n; i++)
    {
        double broj;
        std::cout << i << ".broj: ";
        std::cin >> broj;
        red->dodaj(broj);
    }

    double broj;
    while(red->skini(&broj))
    {
        std::cout << "Skinut..." << broj << std::endl;
    }

    delete red;

    return 0;
}