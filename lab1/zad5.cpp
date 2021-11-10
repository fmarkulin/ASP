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
        if (polje[middle] == x)
        {
            index = middle;
            break;
        }
        else if (left >= right)
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
    std::cout << "Upišite željenu veličinu polja: ";
    std::cin >> n;

    float x;
    std::cout << "Upišite realni broj x: ";
    std::cin >> x;

    float *A = new float[n];
    std::cout << "Ispis polja:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        A[i] = i * 1.1;
        if (i == (n - 1))
        {
            std::cout << A[i] << "]" << std::endl;
        }
        else
        {
            std::cout << A[i] << ", ";
        }
    }

    int indexOfX = binarnoTrazi(A, n, x);
    if (indexOfX == -1)
    {
        std::cout << "Broj se ne nalazi u polju." << std::endl;
    }
    else
    {
        std::cout << "Index traženog broja x u polju: " << indexOfX << std::endl;
    }

    delete[] A;

    return 0;
}