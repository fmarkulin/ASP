#include <iostream>

template <typename T>
int binarnoTrazi(T polje[], int n, T x)
{
    int left = 0;
    int right = n - 1;
    int index = -1;
    while (true)
    {
        int middle = (left + right) / 2;
        if(polje[middle] == x)
        {
            index = middle;
            break;
        } else if(left >= right)
        {
            break;
        }
        else if (polje[middle] < x)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return index;
}

int main(void)
{
    int n;
    do
    {
        std::cout << "Upišite željeni broj elemenata polja (n): ";
        std::cin >> n;
        if (n < 1)
        {
            std::cout << "Broj elemenata polja (n) mora biti 1 ili veći!" << std::endl;
        }
    } while (n < 1);

    float *A = new float[n];
    for(int i = 0; i < n; i++)
    {
        A[i] = i + 3;
    }
    
    std::cout << "Sadržaj polja:" << std::endl;
    std::cout << "[";
    for(int i = 0; i < n - 1; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << A[n - 1] << "]" << std::endl;

    float x;
    std::cout << "Upišite željenu vrijednost za x: ";
    std::cin >> x;

    int indexOfX = binarnoTrazi(A, n, x);
    if(indexOfX == -1)
    {
        std::cout << "Broj se ne nalazi u polju." << std::endl;
    }
    else
    {
        std::cout << "Broj " << x << " se nalazi u polju na indeksu: " << indexOfX << std::endl;
    }

    delete[] A;

    return 0;
}