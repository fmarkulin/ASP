#include <iostream>
#include <cstring>

char *ostaviSlova(std::string ulaz)
{
    int charCount = 0;
    for(char& c : ulaz)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            charCount++;
        }
    }

    if(charCount == 0)
    {
        std::cout << "Ulazni niz ne sadrži znakove engleske abecede!" << std::endl;
        std::exit(0);
    }

    char *noviNiz = new char[charCount + 1];
    int i = 0;
    for(char& c : ulaz)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            noviNiz[i] = c;
            i++;
        }
    }
    noviNiz[charCount] = '\0';

    return noviNiz;
}

int main(void)
{
    std::string ulaz = "asp12_i_ASP13";
    std::cout << "Ulazni niz: " << ulaz << std::endl;
    char *niz = ostaviSlova(ulaz);
    for(int i = 0; i < strlen(niz); i++)
    {   
        std::cout << niz[i];
    }
    std::cout << std::endl;

    delete[] niz;

    return 0;
}