#include <iostream>

bool podnizUNizu(std::string niz, std::string podniz, int pocetak)
{
    if (podniz.length() == 0)
    {
        return true;
    }

    if (niz[pocetak] == podniz[0])
    {
        return podnizUNizu(niz, podniz.substr(1), pocetak + 1);
    }
    return false;
}

int main(void)
{
    std::string niz;
    std::cout << "Upišite niz: ";
    getline(std::cin, niz);

    std::string podniz;
    std::cout << "Upišite podniz: ";
    getline(std::cin, podniz);

    int pocetak;
    std::cout << "Upišite vrijednost za početak: ";
    std::cin >> pocetak;

    std::cout << "Rješenje funkcije: " << podnizUNizu(niz, podniz, pocetak);

    return 0;
}