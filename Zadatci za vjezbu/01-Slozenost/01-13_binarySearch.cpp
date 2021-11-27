//A[0] < A[2] < A[4] < ... < A[n-2] < A[1] < ... < A[n - 1]
//binarno pretraživanje = logn
//0 1 2 3 4
int traziBroj(int A[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int res = 0;
    while(true)
    {
        int middle = (left + right) / 2;
        if(A[middle] == x)
        {
            res = 1;
            break;
        }
        else if (left >= right)
        {
            break;
        }
        else if (A[middle] < x)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return res;
}