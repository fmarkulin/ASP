#include <iostream>

int provjeriZagrade(char *niz, int *zastavica)
{
    if((*niz) != '[' && (*niz) != ']')
        if((*zastavica) == 0)
            return 1;
        else
            return 0;
    
    if((*niz) == '[')
    {
        (*zastavica)++;
        return provjeriZagrade(niz + 1, zastavica);
    }
    else
    {
        (*zastavica)--;
        return provjeriZagrade(niz + 1, zastavica);
    }
}

int main(void)
{
    // char polje1[7] = {'[','[','[',']','[',']',']'};
    char polje2[7] = {']',']','[','[','[',']',']'};
    // char polje3[8] = {'[','[','[',']','[',']',']',']'};
    // char polje4[3] = {'[','[',']'};
    // char polje5[4] = {'[','[',']',']'};

    int zastavica = 0;
    int *pz = &zastavica;
    // std::cout << provjeriZagrade(polje1, pz) << std::endl;
    std::cout << provjeriZagrade(polje2, pz) << std::endl;
    // std::cout << provjeriZagrade(polje3, pz) << std::endl;
    // std::cout << provjeriZagrade(polje4, pz) << std::endl;
    // std::cout << provjeriZagrade(polje5, pz) << std::endl;

    return 0;
}