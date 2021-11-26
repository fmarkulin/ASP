#include <iostream>

void ispisiVeci(int A[], int m, int B[], int n)
{
    if (m == 0 && n == 0)
    {
        return;
    }

    if(m == n)
    {
        std::cout << A[m - 1] << " " << B[n - 1] << " " << ((A[m - 1] >= B [n - 1]) ? A[m - 1] : B[n - 1]) << std::endl;
        return ispisiVeci(A, m - 1, B, n - 1);
    }
    else if(m > n) {
        std::cout << A[m - 1] << " - " << A[m - 1] << std::endl;
        return ispisiVeci(A, m - 1, B, n);
    }
    else
    {
        std::cout << "- " << B[n - 1] << " " << B[n - 1] << std::endl;
        return ispisiVeci(A, m, B, n - 1);
    }
}

int main(void)
{
    int m;
    std::cout << "m: ";
    std::cin >> m;
    
    int n;
    std::cout << "n: ";
    std::cin >> n;

    int *A = new int[m];
    int *B = new int[n];

    for(int i = 0; i < m; i++)
    {
        std::cin >> A[i];
    }

    for(int i = 0; i < n; i++)
    {
        std::cin >> B[i];
    }

    ispisiVeci(A, m, B, n);

    delete[] A;
    delete[] B;

    return 0;
}