#include <iostream>

int poljeEkstrema(int A[], int n)
{
    if (n <= 2)
    {
        return 1;
    }

    //A[i] = A[n - 2]
    //A[i] veći od prvih susjeda
    if (A[n - 3] < A[n - 2] && A[n - 2] > A[n - 1])
        return poljeEkstrema(A, n - 1);

    //A[i] manji od prvih susjeda
    if (A[n - 3] > A[n - 2] && A[n - 2] < A[n - 1])
        return poljeEkstrema(A, n - 1);

    return 0;
}

int main(void)
{
    int polje1[3] = {1,2,1};
    int polje2[3] = {2,1,2};
    int polje3[3] = {1,2,3};
    int polje4[2] = {1,2};

    std::cout << poljeEkstrema(polje1, 3) << std::endl;
    std::cout << poljeEkstrema(polje2, 3) << std::endl;
    std::cout << poljeEkstrema(polje3, 3) << std::endl;
    std::cout << poljeEkstrema(polje4, 2) << std::endl;

    return 0;
}