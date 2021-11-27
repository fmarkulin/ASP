#include <iostream>

int provjeri_sortiranost(int *niz, int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    if(niz[n - 1] >= niz[n - 1 - 1]) return provjeri_sortiranost(niz, n - 1);
    return 0;
}

int main(void)
{
    int niz1[3] = {1, 2, 3};
    int niz2[4] = {1, 2, 2, 3};
    int niz3[1] = {1};
    int niz4[3] = {1, 4, 3};

    std::cout << provjeri_sortiranost(niz1, 3) << std::endl;
    std::cout << provjeri_sortiranost(niz2, 4) << std::endl;
    std::cout << provjeri_sortiranost(niz3, 1) << std::endl;
    std::cout << provjeri_sortiranost(niz4, 3) << std::endl;
    std::cout << provjeri_sortiranost(niz4, 0) << std::endl;

    return 0;
}