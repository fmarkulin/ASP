#include <iostream>
#include <cmath>

void f (int polje[], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        polje[i] = pow(m, i);
    }
}

int main(void)
{
    int n;
    std::cout << "Upišite željenu veličinu polja: ";
    std::cin >> n;

    int m;
    std::cout << "Upišite željenu vrijednost za m: ";
    std::cin >> m;

    int* polje = new int[n];
    f(polje, n, m);
    
    std::cout << "Ispis polja: " << std::endl;
    std::cout << "[";
    for(int i = 0; i < n; i++)
    {
        if(i == (n - 1))
        {
            std::cout << polje[i] << "]" << std::endl;
        }
        else
        {
            std::cout << polje[i] << ", ";
        }
    }

    return 0;
}