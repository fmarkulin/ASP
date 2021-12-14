#include <iostream>

void selection2Sort(int A[], int n, char smjer)
{
    if (smjer == '0')
    { // uzlazno sortiranje
        int i, j;
        for (i = 0; i < n; i++)
        {
            int min = i;
            for (j = i + 1; j < n; j++)
            {
                if (A[j] < A[min])
                    min = j;
            }
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    else
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            int max = i;
            for (j = i + 1; j < n; j++)
            {
                if (A[j] > A[max])
                    max = j;
            }
            int temp = A[i];
            A[i] = A[max];
            A[max] = temp;
        }
    }
}

int main(void)
{
    int n;
    std::cout << "Upisite broj clanova polja: ";
    std::cin >> n;
    
    int *A = new int[n];
    for(int i = 0; i < n; i++)
    {
        std::cout << "Upisite " << i << ". element polja: ";
        std::cin >> A[i];
    }

    char smjer;
    std::cout << "Upisite zeljeni smjer soritranja: ";
    std::cin >> smjer;

    selection2Sort(A, n, smjer);

    for(int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;

    delete[] A;

    return 0;
}