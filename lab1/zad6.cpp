#include <iostream>
#include <string.h>

char *ostaviSlova(std::string ulaz)
{
    int charCount = 0;
    for (char& c : ulaz)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            charCount++;
        }
    }

    char* noviNiz = new char[charCount];
    int i = 0;
    for(char& c : ulaz)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            noviNiz[i] = c;
            i++;
        }
    }

    return noviNiz;
}

int main(void)
{
    std::string ulaz = "asp12_i_ASP13";
    char* niz = ostaviSlova(ulaz);
    for(int i = 0; i < strlen(niz); i++)
    {
        std::cout << niz[i];
    }

    delete[] niz;

    return 0;
}