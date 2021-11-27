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
    char polje1[8] = {'[','[','[',']','[',']',']'};
    char polje2[8] = {']',']','[','[','[',']',']'};
    char polje3[9] = {'[','[','[',']','[',']',']',']'};
    char polje4[3] = {'[','[',']'};

    int zastavica = 0;
    int *pz = &zastavica;
    std::cout << provjeriZagrade(polje1, pz) << std::endl;
    zastavica = 0;
    std::cout << provjeriZagrade(polje2, pz) << std::endl;
    zastavica = 0;
    std::cout << provjeriZagrade(polje3, pz) << std::endl;
    zastavica = 0;
    std::cout << provjeriZagrade(polje4, pz) << std::endl;

    return 0;
}