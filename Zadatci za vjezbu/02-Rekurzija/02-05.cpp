#include <iostream>

void okreni_oduzmi(int A[], int n)
{
    if(n == 0)
    {
        return;
    }

    std::cout << A[n - 1] - A[0] << " ";
    return okreni_oduzmi(A, n - 1);
}

int main(void)
{
    int polje[6] = {2,6,8,11,-3,100};
    okreni_oduzmi(polje, 5);
    return 0;
}